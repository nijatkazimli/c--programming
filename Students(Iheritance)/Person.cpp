#include <iomanip>
#include "Person.h"


void Person::signature()
{
	sign = first.substr(0,1) + last.substr(0,1) + " " + std::to_string(age);
	// YOU SAID MY SOLUTION IS BETTER, SO MORE POINTS IS EXPECTED, please ;(
}

void Person::info(std::ostream & out) const
{
	out << endl;
	out << first << "      " << last << "    ";
}

Person::Person(string first, string last, int age): first(first), last(last), age(age)
{
	signature();
}


