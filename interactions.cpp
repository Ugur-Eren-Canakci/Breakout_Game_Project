#include "interactions.h"

bool is_interacting(const entity& e1, const entity& e2) {

	auto box1 = e1.get_bounding_box();
	auto box2 = e2.get_bounding_box();
	if (box1.findIntersection(box2) != std::nullopt) return true;
	return false;
}

void handle_interaction(ball& ball, const paddle& paddle) {
	if (is_interacting(ball, paddle)) {
		ball.move_up();
	}
}

// will be called with the closest brick

void handle_interaction(ball& ball, brick& brick) {
	if (is_interacting(ball, brick)) {
        // The brick is destroyed
        brick.destroy();

        // Make the new direction depend on where the collision occurs on the brick
        // If the ball collides on the side of the brick, make the ball bounce to the left/right
        // If the ball collides on the top/bottom of the brick, make the ball bounce upwards/downwards

        // First we find the amount of overlap in each direction
        // The smaller the left overlap, the closer the ball is to the left side of the brick
        // And similarly for the other sides of the brick
        float left_overlap = ball.right() - brick.left();
        float right_overlap = brick.right() - ball.left();
        float top_overlap = ball.bottom() - brick.top();
        float bottom_overlap = brick.bottom() - ball.top();

        // If the left overlap is smaller than the right overlap, the ball hit the left side
        bool from_left = std::abs(left_overlap) < std::abs(right_overlap);
        bool from_top = std::abs(top_overlap) < std::abs(bottom_overlap);

        // Use the right or left overlap as appropriate
        float min_x_overlap = from_left ? left_overlap : right_overlap;
        float min_y_overlap = from_top ? top_overlap : bottom_overlap;

        // If the ball hit the left or right side of the brick, change its horizontal direction
        // If the ball hit the top or bottom of the brick, change its vertical direction
        if (std::abs(min_x_overlap) < std::abs(min_y_overlap)) {
            if (from_left) 
                ball.move_left();
            else
                ball.move_right();
        }
        else {
            if (from_top)
                ball.move_up();
            else
                ball.move_down();
        }
    }
}

void handle_interaction(ball& ball, std::vector<brick>& bricks) {
	// vector is prepared so that a brick at row i and column j has subscript i*constants::brick_rows+j

}
