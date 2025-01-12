#include "ball.h"
#include "constants.h"
#include <iostream>

// Initialize the static data
sf::Texture ball::texture("ball.png");
sf::Sprite ball::sprite(texture);

ball::ball(float x, float y) : moving_entity() {
	sprite.setPosition({ x,y });
	velocity = { constants::ball_speed, constants::ball_speed };
}

// Compute the ball's new position
void ball::update() {
	// Move the position of the ball
	sprite.move(velocity);

	// check current position
	float x_pos = sprite.getPosition().x;
	float y_pos = sprite.getPosition().y;
	
	// window borders check
	if (x_pos < 0) {
		velocity.x = -velocity.x;
	}

	if (x_pos > constants::window_width) {
		velocity.x = -velocity.x;
	}

	if (y_pos < 0) {
		velocity.y = -velocity.y;
	}

	if (y_pos > constants::window_height) {
		velocity.y = -velocity.y;
	}
	
}

void ball::draw(sf::RenderWindow& window) {
	// Ask the window to draw the sprite for us
	window.draw(sprite);
}