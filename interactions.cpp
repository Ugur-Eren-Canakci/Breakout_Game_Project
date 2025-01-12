#include "interactions.h"

bool is_interacting(const entity& e1, const entity& e2) {

	auto box1 = e1.get_bounding_box();
	auto box2 = e2.get_bounding_box();
	if (box1.findIntersection(box2) != std::nullopt) return true;
	return false;

}

void handle_interaction(ball& b, const paddle& p) {
	if (is_interacting(b, p)) {
		b.move_up();
	}
}
