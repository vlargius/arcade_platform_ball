#pragma once

struct GameField{

	GameField(unsigned width, unsigned height):
		width(width),
		height(height) {}

	bool is_in(int x, int y) const {
		return x >= 0 && x < width && y >= 0 && y < height;
	}

	unsigned top() const { return top_offset; }
	unsigned bottom() const { return height; }
	unsigned left() const { return 0; }
	unsigned right() const { return width; }

	unsigned width;
	unsigned height;

	unsigned top_offset = 35;
};