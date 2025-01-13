#include "ball.h"
#include "constants.h"
#include "paddle.h"
#include <iostream>

ball::ball(float x, float y) : moving_entity() {
	texture.loadFromFile("ball.png", true);
	sprite = sf::Sprite{ texture };
	
	sprite.setPosition({ x,y });
	velocity = { constants::ball_speed, constants::ball_speed };
}

void ball::move_up() noexcept {
	velocity.y = -constants::ball_speed;
}

void ball::move_left() noexcept {
	velocity.x = -constants::ball_speed;
}

void ball::move_right() noexcept {
	velocity.x = constants::ball_speed;
}

void ball::move_down() noexcept {
	velocity.y = constants::ball_speed;
}

// Compute the ball's new position
void ball::update() {
	// Move the position of the ball
	sprite.move(velocity);

	// window borders check
	if (x() < 0) {
		velocity.x = -velocity.x;
	}

	if (x() > constants::window_width) {
		velocity.x = -velocity.x;
	}

	if (y() < 0) {
		velocity.y = -velocity.y;
	}

	if (y() > constants::window_height) {
		// currently the ball reflects from the bottom of the window
		// will end the turn in the future
		velocity.y = -velocity.y;
	}
	
}

void ball::draw(sf::RenderWindow& window) {
	// Ask the window to draw the sprite for us
	window.draw(sprite);
}
