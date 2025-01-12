#include "background.h"

background::background(float x, float y) : entity() {

	// Load the texture
	texture.loadFromFile("background_image.jpg");
	// Reinitialize the sprite with the image attained above
	sprite = sf::Sprite(texture);

	// set the initial position and velocity of the background
	// use (x,y) for the initial position of the background
	sprite.setPosition({ x,y });
}

background::~background() {}

void background::update() {} 

void background::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

