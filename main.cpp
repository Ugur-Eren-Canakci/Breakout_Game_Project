// Code for a "breakout" game
// Based on a talk by Vittorio Romeo
// Uses the SFML graphics library
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <string>
#include "constants.h"
#include "entity.h"
#include "background.h"
#include "ball.h"

using namespace std::literals;

class creature {
private:
    // static RNG engine and Bernoulli distribution objects
    static std::mt19937 mt;
    static std::bernoulli_distribution bd;

    // basic attributes of the ball
    float vx{ 4.0f };
    float vy{ 4.0f };
    
    // will shift position wr. to this object
    sf::Vector2f velocity;
    
    // necessary to draw on the renderwindow
    sf::CircleShape circle;
public:
    creature(float x, float y) {
        velocity = { vx, vy };
        circle.setPosition({ x, y });
        circle.setRadius(5.0f);
        circle.setFillColor(sf::Color::Red);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(circle);
    }

    // new position is chosen randomly, by using bd(mt)
    void update() {
        // generate the velocity on both direction
        vx = (bd(mt) ? vx : -vx);
        vy = (bd(mt) ? vy : -vy);
        // move the circle by one increment of {vx,vy}
        circle.move({ vx, vy });
    }


};

std::mt19937 creature::mt;
std::bernoulli_distribution creature::bd;

// The main function for the program
int main() {
    std::cout << "Window width: " << constants::window_width << "\nWindow height: " << constants::window_height << std::endl;

    // background image
    background background_image(0.0f, 0.0f);

    // the ball
    ball the_ball(constants::window_width / 2.0, constants::window_height / 2.0);

    /* the random walk
    // create a creature object in the middle of the window
    creature the_creature(
        constants::window_width / 2.0, 
        constants::window_height / 2.0 
    );
    */
    sf::RenderWindow game_window(
        sf::VideoMode({ constants::window_width, 
                        constants::window_height 
        }),
        "Random Walk"s
    );

    game_window.setFramerateLimit(60);
    
    while (game_window.isOpen()) {
        game_window.clear(sf::Color::Black);

        auto event = game_window.pollEvent();

        while (const std::optional event = game_window.pollEvent()) {
            // Window closed or escape key pressed: exit
            if (event->is<sf::Event::Closed>() ||
                (event->is<sf::Event::KeyPressed>() &&
                    event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape)) 
            {
                game_window.close();
            }
        }

        // update the images
        background_image.update();
        the_ball.update();

        // calculate the next frame to show
        background_image.draw(game_window);
        the_ball.draw(game_window);

        /*
        // random walking creature
        the_creature.update();
        the_creature.draw(game_window);
        */


        // display the next frame
        game_window.display();
    }


    return 0;
}
