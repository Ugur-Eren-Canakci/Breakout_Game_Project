#include "brick.h"

// initialize static members

brick::brick() : entity() {
	texture.loadFromFile("brick01.png", true);
	sprite = sf::Sprite(texture);
	sprite.setTexture(texture);
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