#pragma once

#include <cmath>

#include "colider.h"


namespace colider {

	bool is_intersect(const GameObject *  obj1, const GameObject * obj2)
	{
		return obj1->right() >= obj2->left() && obj1->left() <= obj2->right() &&
			obj1->bottom() >= obj2->top() && obj1->top() <= obj2->bottom();
	}

	void colide(Racket * racket, Ball *  ball)
	{
		if (!is_intersect(racket, ball)) return;

		ball->velocity.y = -ball->velocity.y;
		if (ball->pos.x < racket->pos.x)
			ball->velocity.x = -ball->acceleration.x;
		else
			ball->velocity.x = ball->acceleration.x;

		//ball->velocity = ball->velocity / ball->velocity.len() *ball->norm;
	}


	void colide(Brick * brick, Ball *  ball)
	{
		if (!is_intersect(brick, ball)) return;
		brick->destroy();

		double overlap_left{ ball->right() - ball->left() };
		double overlap_right{ brick->right() - brick->left() };
		double overlap_top{ brick->bottom() - brick->top() };
		double overlap_bottom{ brick->bottom() - ball->top() };

		bool ball_from_left(abs(overlap_left) < abs(overlap_right));
		bool ball_from_top(abs(overlap_top) < abs(overlap_bottom));

		double min_overlap_x{ ball_from_left ? overlap_left : overlap_right };
		double min_overlap_y{ ball_from_top ? overlap_top : overlap_bottom };

		if (abs(min_overlap_x) < abs(min_overlap_y))
			ball->velocity.x = ball_from_left ? -1 : 1 * ball->acceleration.x;
		else
			ball->velocity.y = ball_from_top ? -1 : 1 * ball->acceleration.x;
	}

}