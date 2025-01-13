#include "brick.h"

const sf::Color brick_colour_hit1{ 0, 255, 0, 80 };
const sf::Color brick_colour_hit2{ 0, 255, 0, 175 };
const sf::Color brick_colour_hit3{ 0, 255, 0, 255 };

void brick::set_strength(int s) noexcept { strength = s; };
void brick::weaken() noexcept { --strength; };
bool brick::is_too_weak() const noexcept { return strength <= 0; };

brick::brick() : entity() {
	texture.loadFromFile("brick01.png", true);
	sprite = sf::Sprite(texture);
	sprite.setTexture(texture);
}

void brick::place_brick(float x, float y) {
	sprite.setPosition({ x,y });
}

brick::brick(float x, float y) : brick() {
	sprite.setPosition({ x,y });
}

void brick::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void brick::update() {
	// update after interactions and stuff
	if (strength == 1) sprite.setColor(brick_colour_hit1);
	else if (strength == 2) sprite.setColor(brick_colour_hit2);
	else if (strength == 3) sprite.setColor(brick_colour_hit3);
}