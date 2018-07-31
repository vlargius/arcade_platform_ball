#pragma once

#include "game_object.h"

class Brick : public GameObject {
	
	bool is_alive;

public:

	bool is_ok() const { return is_alive; }

	void destroy() {
		is_alive = false;
	}

	Brick(unsigned width, unsigned height, vec2d pos) :
		GameObject(width, height, pos) {}

};
