#include <algorithm>

#include "game.h"
#include "interactions.h"

// Function to scan all entities and clean up the destroyed ones
void entity_manager::refresh() {
    // We must clean up the alias pointers first, to avoid dangling pointers
    // We simply remove them from their vector
    for (auto& [type, alias_vector] : grouped_entities) {
        // remove_if takes an iterator range and a predicate
        // All the elements for which the predicate is true are moved to the back
        // It returns an iterator to the first moved element
        // erase takes an iterator range and deletes all the elements in the range
        alias_vector.erase(remove_if(begin(alias_vector), end(alias_vector),
            [](const auto& p) { return p->is_destroyed(); }
            ),
        end(alias_vector));
    }

    // Now we can safely destroy the objects, now that there are no aliases to them
    all_entities.erase(remove_if(begin(all_entities), end(all_entities),
        [](const auto& p) { return p->is_destroyed(); }
    ),
        end(all_entities));
}

// Function to destroy all entities
void entity_manager::clear() {
    // Again, we must clean up the alias pointers first
    grouped_entities.clear();
    all_entities.clear();
}

// Function to update all the entities
void entity_manager::update() {
    for (auto& e : all_entities)
        e->update();
}

// Function to update make all the entities draw themselves
void entity_manager::draw(sf::RenderWindow& window) {
    for (auto& e : all_entities)
        e->draw(window);
}

game::game() {
    game_window.setFramerateLimit(60);
}

// main game loop
void game::run() {

    game_window.clear();

    // for some reason I have to reset the program once before the graphics show up
    // will be deleted later
    reset();
    // was the pause key pressed in the last frame?
    bool pause_key_active{ false };

    while (game_window.isOpen()) {
        game_window.clear(sf::Color::Black);

        // closing the game
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            game_window.close();
            // can be changed to pause the game

        while (auto event = game_window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                game_window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    game_window.close();
            }
        }
        
        // if user presses P, we pause the game
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
            // if it was not pressed on the last iteration, toggle the status
            if (!pause_key_active) {
                if (state == game_state::running) state = game_state::paused;
                else state = game_state::running;
            }
            pause_key_active = true;
        }
        else
            pause_key_active = false;

        // if user presses R, we reset the game
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
            reset();
        }


        // update the images if the game is not paused
        // rest of the actions will stay the same as only the updating stops when the game is paused
        if (state == game_state::running) {
            manager.update();

            // For every ball, call a function which
            //    For every brick, call a function which
            //         Calls handle_collision with the ball and the brick as arguments
            manager.apply_all<ball>([this](auto& the_ball) {
                manager.apply_all<brick>([&the_ball](auto& the_brick) {
                    handle_interaction(the_ball, the_brick);
                    });
                });

            // Paddle interaction
            manager.apply_all<ball>([this](auto& the_ball) {
                manager.apply_all<paddle>([&the_ball](auto& the_paddle) {
                    handle_interaction(the_ball, the_paddle);
                    });
                });
            manager.refresh();
        }

        // calculate the next frame to show
        manager.draw(game_window);

        /*
        // random walking creature
        the_creature.update();
        the_creature.draw(game_window);
        */


        // display the next frame
        game_window.display();
    }
}

// (Re)initialize the game
void game::reset() {
    
    state = game_state::running;
    // Destroy all the entities and re-create them
    manager.clear();

    manager.create<background>(0.0f, 0.0f);
    manager.create<ball>(constants::window_width / 2.0f, constants::window_height / 2.0f);
    manager.create<paddle>(constants::window_width / 2.0f, constants::window_height - constants::paddle_height - 15.0f);

    for (int i = 0; i < constants::brick_columns; ++i) {
        for (int j = 0; j < constants::brick_rows; ++j) {
            // Calculate the brick's position
            float x = static_cast<float>(constants::brick_offset + (i + 1) * constants::brick_width);
            float y = static_cast<float>((j + 1) * constants::brick_height);

            // Create the brick object
            manager.create<brick>(x, y);
        }
    }

    // Limit the framerate
    game_window.setFramerateLimit(60);      // Max rate is 60 frames per second
}