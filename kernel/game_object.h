#pragma once

#include "rectangle.h"

struct GameObject : public MyRectangle {

	GameObject(unsigned width, unsigned height, vec2d pos) :
		MyRectangle(width, height, pos) {}
};
