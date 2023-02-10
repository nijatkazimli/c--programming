#ifndef _PERSON_H
#define _PERSON_H
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdio>

#include "Individual.h"

using namespace std;

class Person : public Individual
{
protected:
	string first;
	string last;
	int		age;
public:
	Person(string first="Anony", string last = "Mous", int age = 18);
//fill missing

	void signature() override;
	void info(std::ostream& os) const;

};

#endif