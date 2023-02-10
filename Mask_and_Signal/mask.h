#pragma once
#include <iostream> 
using namespace std;

class Mask
{
	double* coeff;
	int size;
public:
	friend class Signal;
	Mask(int, double* = nullptr);
	~Mask();
	Mask(const Mask&) = delete;
	Mask& operator=(const Mask&) = delete;

	double operator()() const;
	friend ostream& operator<<(ostream&, const Mask&);
};


