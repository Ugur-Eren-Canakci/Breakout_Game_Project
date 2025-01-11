#include "ball.h"
#include "constants.h"

// Initialize the static data
sf::Texture ball::texture("ball_image.png");
sf::Sprite ball::sprite(texture);

ball::ball(float x, float y) : moving_entity() {
	sprite.setPosition({ x,y });
	velocity = { constants::ball_speed, constants::ball_speed };
}

// Compute the ball's new position
void ball::update() {
	// Move the position of the ball
	sprite.move(velocity);
}

void ball::draw(sf::RenderWindow& window) {
	// Ask the window to draw the sprite for us
	window.draw(sprite);
}