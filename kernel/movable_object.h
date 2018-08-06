#pragma once

#include "game_field.h"
#include "game_object.h"

struct MovableObject: public GameObject{

	const GameField field;
	double acceleration = 1.0;

	vec2d velocity;

	MovableObject(unsigned width, unsigned height, vec2d pos, GameField field) :
		GameObject(width, height, pos),
		field(field) {}


	void move() {
		pos.x += velocity.x;
		pos.y += velocity.y;
	}
};