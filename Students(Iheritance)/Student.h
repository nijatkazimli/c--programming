#ifndef _STUDENT_H
#define _STUDENT_H
#include <cstdio>

#include "Person.h"

using namespace std;
      
class Student: public Person
{
	double* scores;
	int scores_size;
	
	void init_scores(int ile_ocen=0, double* oceny=nullptr);
	//void convert_scores(const string &in );
	
public:
	Student(string first="Test", string last = "Student", int age = 18, const string &scores ="" );
	Student(const Student& obj);
	~Student();
	Student operator=(Student& obj2);
	double average() ;
	void signature() override;
	void convert_scores(const string& in);
};

#endif