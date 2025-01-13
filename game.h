#pragma once

#include "constants.h"
#include "paddle.h"
#include "ball.h"
#include "background.h"
#include "brick.h"
#include "brick_placements.h"

using namespace std::literals;



class game {
private:
    enum class GameState { RUNNING, PAUSE };
    GameState game_state{ GameState::RUNNING };
	sf::RenderWindow game_window{ 
        sf::VideoMode({ constants::window_width,
                        constants::window_height
        }),
        "Breakout_Not_A_Game_Yet"s 
    };

    // the background image
    background background_image{ 0.0f, 0.0f };

    // the ball
    ball the_ball{ constants::window_width / 2.0, constants::window_height / 2.0 };

    // the paddle
    paddle the_paddle{
        (float)constants::window_width / 2 - constants::paddle_width / 2,
        (float)constants::window_height - constants::paddle_height - 5.0f
    };

    // the bricks
    std::vector<brick> bricks{ constants::brick_columns * constants::brick_rows };
    // brick placement
    //place_bricks(bricks);
public:

    game();
    void run(); 
    void reset();
};

