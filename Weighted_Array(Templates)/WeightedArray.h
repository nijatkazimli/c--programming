#pragma once
#include <iostream>
#include "Array.h"
using namespace std;


template<class D, int size>
class WeightedArray : public Array<D> {

	Array weight_arr[size];
	WeightedArray(Array, Array, int);


};


template<class D, int size>
WeightedArray<D, size>::WeightedArray(Array<D> ob1, Array<D> ob2, int size) : Array(ob1) , weight_arr(ob2) {

	
}