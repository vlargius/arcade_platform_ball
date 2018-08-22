#pragma once

#include "movable_object.h"

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}


class Racket : public MovableObject{

public:

	Racket(unsigned width, unsigned height, vec2d pos, GameField field) :
		MovableObject(width, height, pos, field) {}

	void step(double dt = constants::step) {
		MovableObject::step(dt);
	}

	unsigned w() const { return width; }
	unsigned h() const { return height; }

};