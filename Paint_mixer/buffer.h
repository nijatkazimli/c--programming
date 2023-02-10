#pragma once
#include "paint.h"

const unsigned int MAX_BUFFER_SIZE = 20;

class Buffer {
public:
	Buffer();
	void push(const Paint &paint);
	Paint pop();
	bool empty() const;
	unsigned int size() const;
private:
	Paint paints[MAX_BUFFER_SIZE];
	unsigned int count = 0;
};
