#include "brick.h"

brick::brick() : entity() {
	texture = sf::Texture{ "brick01.png" };
	sprite = sf::Sprite(texture);
}

void brick::place_brick(float x, float y) {
	sprite.setPosition({ x,y });
}

void brick::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void brick::update() {
	// update after interactions and stuff
}