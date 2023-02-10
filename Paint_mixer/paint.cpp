#include "paint.h"
#include <iostream>


Paint::Paint(int r, int g, int b, double f) {
	red = static_cast<unsigned char>(r);
	green = static_cast<unsigned char>(g);
	blue = static_cast<unsigned char>(b);
	if (f >= 1)
		fill = 1;
	else if (f <= 0)
		fill = 0;
	else
		fill = f;
}

std::ostream& operator<<(std::ostream& out, const Paint& a) {
	
	std::cout << "(" << static_cast<unsigned int>(a.red) << ", " << static_cast<unsigned int>(a.green) << ", " << static_cast<unsigned int>(a.blue) << ")" << "[" << a.fill * 100 << "%]";




	return out;
}

Paint Paint::GetEmpty() {
	Paint empty = Paint(0, 0, 0, 0);
	return empty;
}

 Paint Paint::operator/(int c) {
	 Paint a = *this;
	if (c == 0)
		return a;
	else {
		a.fill = a.fill / c;
		return a;
	}
}

Paint operator+(const Paint& a, const Paint& b) {

	Paint sum;

	if (a.fill + b.fill > 100) {
		sum.fill = a.fill + (100 - a.fill);
	}


	sum.red = (a.red * a.fill + b.red * b.fill) / (a.fill + b.fill);
	sum.blue = (a.blue * a.fill + b.blue * b.fill) / (a.fill + b.fill);
	sum.green = (a.green * a.fill + b.green * b.fill) / (a.fill + b.fill);
	sum.fill = a.fill + b.fill;

	return sum;
}