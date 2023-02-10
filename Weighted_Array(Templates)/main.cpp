#include <iostream>
#include <string>
#include "Array.h"
#include "WeightedArray.h"

using namespace std;

int main()
{
	const int size = 7;
	int t1[size] = { -3, -1, -2, 0, -5, 2, 7 };
	double t2[size] = { 2.5, 0.7, 0.4, -0.1, 1.8, 3.3, -5 };
	char t3[size] = { 'a','n','a','r','r','a','y' };
	
	//	{
	//		Array a0;
	//		Array a1(t1, size);
	//		cout << a1[0] << " " << a1[1] << " ... " << a1[size - 1] << endl;

	//		Array a2(nullptr, size);
	//		cout << a2[0] << " " << a2[1] << " ... " << a2[size - 1] << endl;

	//		Array a3(a1);
	//		a3 = a2;
	//		cout << a3[0] << " " << a3[1] << " ... " << a3[size - 1] << endl;

	//		a3 = a0;
	//	}
	

	cout << " ---------- Part 1 (2 point) ---------- " << endl;

	Array<char> a0;
	Array<int> a1(t1, size);
	Array<double> a2(t2, size);
	Array<char> a3(t3, size);

	cout << a1;
	cout << a2;
	cout << a3;

	int b1 = a1[1];
	double b2 = a2[4];
	char b3 = a3[0];

	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;

	cout << " ---------- Part 2 (2 point) ---------- " << endl;

	char t4[size] = { 'a','2','b','3','0','c','4' };
	Array<char> a4(t4, size);

	cout << a1.accumulate() << endl;
	cout << a2.accumulate() << endl;
	cout << (int)a3.accumulate() << endl;
	cout << (int)a4.accumulate() << endl;

	cout << " ---------- Part 3 (1 point) ---------- " << endl;
	
	cout << "cmp() test :  cmp(1,2) = " << (cmp<int>(1, 2) ? "true" : "false") << " ( = true) " << endl;

	sort(a1, size, cmp<int>);
	cout << a1 << endl;
	sort(a2, size, cmp<double>);
	cout << a2 << endl;
	sort(a3, size, cmp<char>);
	cout << a3 << endl;
	
	cout << " ---------- Part 4 (2 point) ---------- " << endl;

	//WeightedArray<int, size> a6(t1, t2, size);
	//WeightedArray<char, size> a7(t3, t2, size);
	//
	//cout << a6 << endl;
	//cout << a7 << endl;

	cout << " ---------- Part 5 (1 point) ---------- " << endl;
	//// you may add code in this part

	try {
	
		cout << a0[25] << endl;
	}
	catch (out_of_range &e) {
		cerr << e.what() << endl;
	}
	
	
	cout << " ---------- Part 5 (end) ---------- " << endl;
	
	
}
