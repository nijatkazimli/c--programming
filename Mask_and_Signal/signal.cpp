#include <iostream> 
#include <iomanip> 
using namespace std;
#include "mask.h"
#include "signal.h"

// to do

Signal::Signal() : samples(nullptr), no_of_samples(0) {

}

Signal::Signal(int _no) : no_of_samples(_no) {

	samples = new double[no_of_samples];
	for (int i = 0; i < no_of_samples; i++) {
		samples[i] = 0;
	}
}

Signal::Signal(int _no, double _sample[]) : no_of_samples(_no) {

	samples = new double[no_of_samples];
	for (int i = 0; i < no_of_samples; i++) {
		samples[i] = _sample[i];
	}
}

Signal::~Signal() {
	delete samples;
}

ostream& operator<<(ostream& out, const Signal& obj) {

	cout << "[";
	for (int i = 0; i < obj.no_of_samples; i++) {
		cout << " " << obj.samples[i] << " ";
	}

	cout << "]";

	return out;
}

Signal::Signal(const Signal& obj) {

	no_of_samples = obj.no_of_samples;
	samples = new double[no_of_samples];
	for (int i = 0; i < this->no_of_samples; i++) {
		samples[i] = obj.samples[i];
	}
}

Signal operator+(const Signal& obj1, const Signal& obj2) {

	if (obj1.no_of_samples != obj2.no_of_samples) {
		Signal empt;
		return empt;
	}
	else {
		Signal basic;
		basic.no_of_samples = obj1.no_of_samples;
		basic.samples = new double[basic.no_of_samples];
		for (int i = 0; i < basic.no_of_samples; i++) {
			basic.samples[i] = obj1.samples[i] + obj2.samples[i];
		}
		return basic;

	}
}

Signal Signal::operator=(const Signal& obj) {

	if (this == &obj)
		return *this;

	delete samples;

	no_of_samples = obj.no_of_samples;
	samples = new double[obj.no_of_samples];
	for (int i = 0; i < obj.no_of_samples; i++) {
		samples[i] = obj.samples[i];
	}

	return *this;

}

Signal::Signal(Signal&& obj) : no_of_samples(obj.no_of_samples) {
	
	samples = obj.samples;
}

Signal Signal::operator=(Signal&& obj) {

	if (this == &obj)
		return *this;

	delete samples;
	no_of_samples = obj.no_of_samples;
	samples = obj.samples;
	return *this;

}