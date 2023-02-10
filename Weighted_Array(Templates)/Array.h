#pragma once
#include <iostream>
#include <exception>

using namespace std;


template<class T>
class Array
{
protected:
	T* arr;
	int size;
	void init(T* tab, int size);
public:
	Array(T* tab = nullptr, int s = 0);
	Array(const Array&);
	Array & operator=(const Array &);
	~Array();
	virtual void display() const;

	T operator[](int) const;
	T & operator[](int);
	T accumulate() const;

	template<class F>
	friend ostream& operator<<(ostream&, const Array<F>&);

	template<class G>
	friend bool cmp(G, G);

	template<class S>
	friend void sort(Array<S>&, int, bool);

};


template<class T>
void Array<T>::init(T* tab, int n) {

	size = 0;
	arr = new T[n];
	if (arr) {
		size = n;
		for (int i = 0; i < size; i++)
			arr[i] = tab ? tab[i] : 0;
	}
	else {
		cout << "No allocated memory" << endl;
	}

}

template<class T>
Array<T>::Array(T* tab, int size) : arr(nullptr), size(0)
{
	init(tab, size);
}


template<class T>
Array<T>::~Array()
{
	delete[] arr;
}


template<class T>
T Array<T>::operator[](int i) const
{
	if (i > size)
		throw out_of_range("Index out of array bound");
	else
		return arr[i];
}


template<class T>
T& Array<T>::operator[](int i)
{
	if (i > size)
		throw out_of_range("Index out of array bound");
	else
		return arr[i];
}


template<class T>
Array<T>::Array(const Array<T>& a) : arr(nullptr), size(0) {
	if (a.arr)
	{
		init(a.arr, a.size);
	}
}


template<class T>
Array<T>& Array<T>::operator=(const Array<T>& rh)
{
	if (this == &rh)
		return *this;

	delete[] arr;
	arr = nullptr;
	size = 0;

	if (rh.arr)
	{
		init(rh.arr, rh.size);
	}

	return *this;
}

template<class T>
void Array<T>::display() const {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class F>
ostream& operator<<(ostream& out, const Array<F>& obj) {
	
	obj.display();

	return out;
}

template<class T>
T Array<T>::accumulate() const {
	T sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}

template<>
char Array<char>::accumulate() const {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (isdigit(arr[i]))
		{
			sum += static_cast<int>(arr[i])-'0';

		}

	}
	return static_cast<char>(sum);
}

template<class G>
bool cmp(G a, G b) {
	if (a < b)
		return true;
	return false;
}

template<class S, typename W>
void sort(Array<S>& obj, int size, W compare) {
	
	for (int k = 0; k < size - 1; k++) {
		for (int i = 0; i < size - 1; i++)
		{
			bool logic = compare(obj[i], obj[i + 1]);
			if (logic) {
				S tmp = obj[i];
				obj[i] = obj[i + 1];
				obj[i + 1] = tmp;
			}

		}
	}
}