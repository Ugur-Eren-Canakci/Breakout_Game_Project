#include "paddle.h"
#include <iostream>
using namespace std::literals;

paddle::paddle(float x, float y) : moving_entity() {
	texture.loadFromFile("paddle.png", true);
	sprite = sf::Sprite(texture);
	sprite.setPosition({ x,y });
	velocity = { 0.0f, 0.0f };
}

void paddle::process_player_input() {
	// if right arrow key
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		// if paddle is not on the right edge
		if (x() <= constants::window_width - constants::paddle_width) { 
			velocity.x = constants::paddle_speed;
		}
		// otherwise
		else {
			velocity.x = 0.0f;
		}
	}
	// if left arrow key
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		// if paddle is not on the right edge
		if (x() >= 0 ) {
			velocity.x = -constants::paddle_speed;
		}
		// otherwise
		else {
			velocity.x = 0.0f;
		}
	}
	else {
		velocity.x = 0.0f;
	}
}

void paddle::update() {
	process_player_input();
	// move the sprite once, w.r. to the key
	sprite.move(velocity);
}

void paddle::draw(sf::RenderWindow& window) {
	// tell the renderwindow to draw the paddle with its current sprite position 
	window.draw(sprite);
}

void paddle::move_up() noexcept {}
void paddle::move_left() noexcept {}
void paddle::move_right() noexcept {}
void paddle::move_down() noexcept {}