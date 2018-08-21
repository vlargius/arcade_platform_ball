#pragma once

#include "game_object.h"
#include "racket.h"
#include "ball.h"
#include "brick.h"

namespace colider {

	bool is_intersect(const GameObject *  obj1, const GameObject * obj2);

	void colide(Racket * racket, Ball *  ball);

	void colide(Brick * brick, Ball *  ball);

}