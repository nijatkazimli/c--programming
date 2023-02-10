//#include "Array.h"
//#include <exception>
//using namespace std;
//
//void Array::init(int* tab, int n) {
//
//	size = 0;
//	arr = new (nothrow) int[n];
//	if(arr){
//		size = n;
//			for (int i = 0; i < size; i++)
//				arr[i] = tab ? tab[i] : 0;
//	}else{ 
//		cout<<"No allocated memory"<<endl;
//	}
//
//}
//
//Array::Array(int* tab, int size): arr(nullptr), size(0)
//{
//	init(tab, size);
//}
//
//Array::~Array()
//{
//	delete[] arr;
//}
//
//int Array::operator[](int i) const
//{
//	return arr[i];
//}
//
//int & Array::operator[](int i) 
//{
//	return arr[i];
//}
//
//Array::Array(const Array & a): arr(nullptr), size(0){
//	if (a.arr)
//	{
//		init(a.arr, a.size);
//	}
//}
//
//Array & Array::operator=(const Array & rh) 
//{
//	if (this == &rh)
//		return *this;
//	
//	delete[] arr;
//	arr = nullptr;
//	size = 0;
//	
//	if (rh.arr)
//	{
//		init(rh.arr, rh.size);
//	}
//
//	return *this;
//}
