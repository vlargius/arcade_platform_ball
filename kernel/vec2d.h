#pragma once

#include <math.h>

const double eps = 1.e-12;

struct vec2d {
	double x = 0;
	double y = 0;

	double len() { return sqrt(x*x + y * y)+eps; }

	vec2d operator /(double val) {
		return { x / val, y / val };
	}

	vec2d operator *(double val) {
		return { x * val, y * val };
	}

	vec2d operator +(vec2d vec) {
		return { x * vec.x, y * vec.y };
	}
};
