#pragma once
#include "entity.h"



class brick : public entity {
private:
	int life = 1;
public:
	// default constructor
	brick(); 
	
	// two args constructor
	brick(float x, float y);

	// placement of the sprite
	void place_brick(float x, float y);
	
	void update() override;

	// drawing on a particular window
	void draw(sf::RenderWindow& window) override;
};

