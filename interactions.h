#pragma once

#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include "ball.h"
#include "paddle.h"
#include "brick.h"

// interaction of any two entity
bool is_interacting(const entity& e1, const entity& e2);

// handles interaction between the ball and the paddle
void handle_interaction(ball& ball, const paddle& paddle);

// handles interaction between the ball and a brick the ball touches
void handle_interaction(ball& ball, brick& brick);

#endif // INTERACTIONS_H