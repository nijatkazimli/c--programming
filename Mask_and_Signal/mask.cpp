#include <iostream> 
using namespace std;
#include "mask.h"

// to do

Mask::Mask(int c, double* w) : size(c), coeff(nullptr) {
	
	
	if (w) {
		coeff = new double[c];
		for (int i = 0; i < c; i++) {
			coeff[i] = w[i];
		}
	}


}

Mask::~Mask() {
	delete coeff;
}

ostream& operator<<(ostream& out, const Mask& obj) {
	cout << "Mask of size " << obj.size << " and coefficients ";
	cout << "[";
	if (obj.coeff) {
		for (int i = 0; i < obj.size; i++) {
			cout << " " << obj.coeff[i] << " ";
		}
		cout << "]";

	}
	else
		cout << "]";
	return out;
}

double Mask::operator()() const {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += coeff[i];
	}
	return sum;
}
