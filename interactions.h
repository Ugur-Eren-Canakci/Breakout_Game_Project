#pragma once

#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include "ball.h"
#include "paddle.h"

bool is_interacting(const entity& e1, const entity& e2);

void handle_interaction(ball& e1, const paddle& e2);

#endif // INTERACTIONS_H