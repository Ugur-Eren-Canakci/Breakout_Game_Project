#pragma once
#include "entity.h"
#include "constants.h"

class brick : public entity {
private:
	int strength = constants::brick_strength;
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

	// strength functions
	void set_strength(int s) noexcept;
	void weaken() noexcept;
	bool is_too_weak() const noexcept;
};

