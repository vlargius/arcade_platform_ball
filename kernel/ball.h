#pragma once
#include "movable_object.h"
#include "constants.h"

class Ball : public MovableObject
{
	bool is_in_game = true;
	
public:
	double norm;

	Ball(unsigned width, unsigned height, vec2d pos, GameField field) :
		MovableObject(width, height, pos, field) {
		velocity = vec2d{ 0, -0.05};
		acceleration = { 0.5, 0 };
		norm = 0.5;
	}


	bool in_game() const { return is_in_game; }

	void step(double dt = constants::step)
	{		
		MovableObject::step();
	
		if (left() < field.left())
			velocity.x = acceleration.x;
		
		else if (right() > field.right())
			velocity.x = -acceleration.x;
		
		if (top() < field.top())
			velocity.y = acceleration.y;

		else if (bottom() > field.bottom())
			is_in_game = false;

	}

};