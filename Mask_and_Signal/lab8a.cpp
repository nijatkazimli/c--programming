#include <iostream> 
using namespace std;
#include "mask.h"
#include "signal.h"

int main ()
{
	double f1[3] = {1, 1, 1};
	double w[8] = {1, 2, 1, 0, 1, 2, 1, 0};

	cout << endl << "*********************** Part 1 ***********************" << endl << endl;

	Signal s0;
	Signal s1(4);
	Signal s2(8,w);

	cout << "Signal s0: " << s0 << endl;
	cout << "Signal s1: " << s1 << endl;
	cout << "Signal s2: " << s2 << endl;

	cout << endl << "*********************** Part 2 ***********************" << endl << endl;

	Signal s3(s0);
	s3 = s2 + s2;
	cout << "Sum s2 + s2: " << s3 << endl;
	s3 = s1 + s2;
	cout << "Sum s1 + s2: " << s3 << endl;

	cout << endl << "*********************** Part 3 ***********************" << endl << endl;

	Mask m0(3);
	Mask m1(3,f1);

	cout << "Mask m0: " << m0 << endl;
	cout << "Mask m1: " << m1 <<  endl;
	cout << "Sum of coefficints m1: " << m1() << endl;

	cout << endl << "*********************** Part 4 ***********************" << endl << endl;
/*
	s0 = s2.convolution(m1);
	cout << "Convolution s2*m1: " << s0 << endl;
	
	s0 = s2.linear_filtration(m1);
	cout << "Linera fitration of s2 with mask m1: " << s0 << endl;

	cout << endl;
*/
	cout << endl << "*********************** Part 5 ***********************" << endl << endl;
/*
	cout << "With move logic program is still working properly!" << endl;
*/
	return 0;
}

