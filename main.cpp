// Code for a "breakout" game
// Based on a talk by Vittorio Romeo
// Uses the SFML graphics library
#include <iostream>
#include <SFML/Graphics.hpp>
//#include <random>
#include <string>
#include <vector>
#include <algorithm>
#include "constants.h"
#include "entity.h"
#include "background.h"
#include "ball.h"
#include "paddle.h"
#include "interactions.h"
#include "brick.h"
#include "brick_placements.h"
#include "game.h"

using namespace std::literals;
/*
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
*/// random walk class and objects
// The main function for the program
int main() {
    std::cout << "Window width: " << constants::window_width << "\nWindow height: " << constants::window_height << std::endl;

    game game;
    game.run();
    
    return 0;
}
