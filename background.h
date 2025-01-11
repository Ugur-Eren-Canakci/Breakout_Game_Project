#pragma once

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "entity.h"
#include "constants.h"

// class to represent background 
// inherits from entity
class background : public entity {
private:
	static sf::Texture texture;
	static sf::Sprite sprite;
public:
	// Interface of the class
	
	// Constructor
	// arguments are the initial coordinates of the centre of the background
	background(float x, float y);

	void update() override;
	void draw(sf::RenderWindow& window) override;

	~background() override;
};

#endif // BACKGROUND_H
