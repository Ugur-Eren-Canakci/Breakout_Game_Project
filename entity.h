#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <string>

class entity { // abstract base class	
protected:
	bool destroyed{ false };
	static sf::Texture texture;
	sf::Sprite sprite{ texture };
public:
	// virtual destroyer
	virtual ~entity() {}

	// pure virtual functions here
	// concrete graphical entities must implement these functions
	// the update member function will compute the new position, appearance, etc.
	// the draw member function will cause the updated object to be displayed in the renderwindow
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	// Helper function to get the bounding box of a sprite
	sf::FloatRect get_bounding_box() const noexcept;

	// Helper function to get the centre of a sprite
	sf::Vector2f get_centre() const noexcept;
	
	// Helper function to get x and y positions
	float x() const noexcept;
	float y() const noexcept;

	// Helper functions to get the edges of the sprite
	float left() const noexcept;
	float right() const noexcept;
	float top() const noexcept;
	float bottom() const noexcept;

	// Helper functions for the state of the entity
	void destroy() noexcept;
	bool is_destroyed() const noexcept;

};

class moving_entity : public entity {
protected:
	sf::Vector2f velocity;
public:
	// pure virtual functions will be inherited from entity
	// so that classes that derive moving_entity will have to define them

	virtual void move_up() noexcept = 0;
	virtual void move_left() noexcept = 0;
	virtual void move_right() noexcept = 0;
	virtual void move_down() noexcept = 0;
};
#endif // ENTITY_H


