#pragma once
#include "entity.h"
#include "constants.h"
class paddle : public moving_entity {
private:
	float paddle_width = 90.0f, paddle_height = 9.0f;
public:
	// constructor
	paddle(float x, float y);
	
	// update the paddle
	void update() override;

	// draw the object on the right window 
	void draw(sf::RenderWindow& window) override;
	
	// process player input
	void process_player_input();

	void move_up() noexcept override;
	void move_left() noexcept override;
	void move_right() noexcept override;

};

