#pragma once
#include "buffer.h"
#include "paint.h"

class Mixer {
public:
	void add(const Paint& paint, unsigned int count = 1);
	bool mix(unsigned int count);
	Paint get();
	size_t size() const;
private:
	Buffer nonmixed;
	Buffer mixed;
};
