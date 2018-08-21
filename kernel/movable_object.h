#pragma once

#include "game_field.h"
#include "game_object.h"
#include "constants.h"

struct MovableObject: public GameObject{

	const GameField field;
	vec2d acceleration = { 0.05, 0 };

	vec2d velocity;

	MovableObject(unsigned width, unsigned height, vec2d pos, GameField field) :
		GameObject(width, height, pos),
		field(field) {}


	void step(double dt = constants::step) {
		pos.x += velocity.x * dt;
		pos.y += velocity.y * dt;
	}
};