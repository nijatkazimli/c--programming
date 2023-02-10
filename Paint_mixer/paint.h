#pragma once
#include <iostream>
class Paint {

	
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	double fill;
public:
	Paint(int r = 0, int g = 0, int b = 0, double f = 1);
	static Paint GetEmpty();


	friend std::ostream& operator<<(std::ostream& out, const Paint& a);
	Paint operator/(int c);
	friend Paint operator+(const Paint& a, const Paint& b);
};