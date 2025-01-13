#include "game.h"
#include "interactions.h"

game::game() {
	place_bricks(bricks);
    game_window.setFramerateLimit(60);
}

// main game loop
void game::run() {
    // was the pause key pressed in the last frame?
    bool pause_key_active{ false };

    while (game_window.isOpen()) {
        game_window.clear(sf::Color::White);

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
                if (game_state == GameState::RUNNING) game_state = GameState::PAUSE;
                else game_state = GameState::RUNNING;
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
        if (game_state == GameState::RUNNING) {
            background_image.update();
            the_ball.update();
            the_paddle.update();
            for (brick& el : bricks) {
                el.update();
            }

            // handle collisions
            handle_interaction(the_ball, the_paddle);

            for (brick& brick : bricks) {
                handle_interaction(the_ball, brick);
            }
            bricks.erase(std::remove_if(std::begin(bricks), std::end(bricks),
                [](const brick& b) { return b.is_destroyed(); }),
                std::end(bricks));

        }

        // calculate the next frame to show
        background_image.draw(game_window);
        the_ball.draw(game_window);
        the_paddle.draw(game_window);
        for (brick& el : bricks) {
            el.draw(game_window);
        }

        /*
        // random walking creature
        the_creature.update();
        the_creature.draw(game_window);
        */


        // display the next frame
        game_window.display();
    }
}

void game::reset() {
    bricks = std::vector<brick>{ constants::brick_columns * constants::brick_rows };
    place_bricks(bricks);
}