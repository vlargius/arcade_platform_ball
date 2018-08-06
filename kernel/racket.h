#pragma once

#include "movable_object.h"

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

extern int gAxis[2];

class Racket : public MovableObject{

public:

	Racket(unsigned width, unsigned height, vec2d pos, GameField field) :
		MovableObject(width, height, pos, field) {}

	void update() {
		move();

		
		if (gAxis[0] > 0 && right() < field.width)
			velocity.x = acceleration;
		else if (gAxis[0] < 0 &&  left() > 0)
			velocity.x = -acceleration;

		else
			velocity.x -= sgn(velocity.x) * acceleration;
	}

	unsigned w() const { return width; }
	unsigned h() const { return height; }

};