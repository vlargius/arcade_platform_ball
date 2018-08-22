#pragma once

#include "game_field.h"
#include "game_object.h"
#include "constants.h"

struct MovableObject: public GameObject{

	const GameField field;
	vec2d acceleration = { 0.15, 0 };

	vec2d velocity;

	MovableObject(unsigned width, unsigned height, vec2d pos, GameField field) :
		GameObject(width, height, pos),
		field(field) {}


	void step(double dt = constants::step) {

		double new_x = pos.x + velocity.x * dt;
		double new_y = pos.y += velocity.y * dt;

		if (!field.is_in(new_x, new_y)) {
			return;
		}

		pos.x = new_x;
		pos.y = new_y;
	}
};