#include "brick.h"
#include <vector>
#include "constants.h"

void place_bricks(std::vector<brick>& vec) {
	
	for (int i = 0; i < constants::brick_rows; i++) {
		for (int j = 0; j < constants::brick_columns; j++) {
			float w_offset = constants::brick_offset;
			float h_offset = constants::brick_height + 35.0f;
			vec.at(i * constants::brick_columns + j).place_brick(w_offset + j*constants::brick_width,
															     h_offset + i*constants::brick_height);
		}
	}
}