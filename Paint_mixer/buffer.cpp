#include "buffer.h"

void Buffer::push(const Paint& paint) {

	paints[count] = paint;
	++count;

}

Paint Buffer::pop() {

	Paint last = paints[count];
	--count;
	
	return last;
 }

bool Buffer::empty() const {
	if (count == 0)
		return true;
	else
		return false;
}

unsigned int Buffer::size() const {
	return count;
}
