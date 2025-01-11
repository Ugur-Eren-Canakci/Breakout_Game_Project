#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class entity { // abstract base class
public:
	// pure virtual functions here
	// concrete graphical entities must implement these functions
	// the update member function will compute the new position, appearance, etc.
	// the draw member function will cause the updated object to be displayed in the renderwindow
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	// virtual destroyer
	virtual ~entity() {}


};
#endif // ENTITY_H

