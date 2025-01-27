#pragma once
#include "entity.h"



class ball : public moving_entity {
public:
	// Interface of the class

	// Constructor
	// Arguments are the initial coordinates of the centre of the ball
	// SFML uses the computer graphics convention
	// (0,0) is the top left corner of the screen
	// x increases to the right
	// y increases downwards
	ball(float x, float y);

	void move_up() noexcept override;
	void move_left() noexcept override;
	void move_right() noexcept override;
	void move_down() noexcept override;

	void update() override;
	void draw(sf::RenderWindow& window) override;

};

