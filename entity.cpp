#include "entity.h"
#include "constants.h"
#include <iostream>


sf::FloatRect entity::get_bounding_box() const noexcept {
	return sprite.getGlobalBounds();
}

sf::Vector2f entity::get_centre() const noexcept {
	auto box = get_bounding_box();
	float x_pos = (float)(box.position.x) + box.size.x / 2.0;
	float y_pos = (float)(box.position.y) + box.size.y / 2.0;
	sf::Vector2f res = { x_pos, y_pos};
	return res;
}
float entity::x() const noexcept {
	return sprite.getPosition().x;
}

float entity::y() const noexcept {
	return sprite.getPosition().y;
}