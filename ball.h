#pragma once
#include "movable_object.h"

class Ball : public MovableObject
{
	bool is_in_game = true;
	
public:
	double norm;

	Ball(unsigned width, unsigned height, vec2d pos, GameField field) :
		MovableObject(width, height, pos, field) {
		velocity = vec2d{ 0, -0.5};
		acceleration = 0.5;
		norm = 0.5;
	}


	bool in_game() const { return is_in_game; }

	void update()
	{		
		move();
	
		if (left() < field.left())
			velocity.x = acceleration;
		
		else if (right() > field.right())
			velocity.x = -acceleration;
		
		if (top() < field.top())
			velocity.y = acceleration;

		else if (bottom() > field.bottom())
			is_in_game = false;

	}

};