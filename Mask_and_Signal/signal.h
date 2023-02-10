#pragma once
#include <iostream> 
using namespace std;

class Mask;

class Signal
{
	double* samples;
	int no_of_samples;
public:
	// Part 1
	// to do

	Signal();
	Signal(int, double[]);
	Signal(int);
	Signal(const Signal&);
	Signal(Signal&&);
	~Signal();
	
	 
	// 
	// 
	// Part 2
	// to do
	// 
	//Part 4
	//Signal linear_filtration(const Mask&);
	//Signal convolution(const Mask&);
	// Part 5
	// to do
	// 

	Signal operator=(const Signal&);
	friend ostream& operator<<(ostream&, const Signal&);
	friend Signal operator+(const Signal&, const Signal&);
	Signal operator=(Signal&&);
	
};

