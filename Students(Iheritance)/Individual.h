#ifndef _INDIVIDUAL_H
#define _INDIVIDUAL_H
#include <iostream>
#include <cstdio>

using namespace std;

class Individual
{
protected:
	std::string sign;

public:
	virtual void signature() = 0;
	Individual(): sign("none") {  };
	
	virtual void info(std::ostream & os) const { os << "I'm individual"; };

	friend std::ostream& operator<<(std::ostream& os, const Individual& i);
};

#endif // _INDIVIDUAL_H