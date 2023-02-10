#include "Individual.h"

std::ostream& operator<<(std::ostream& os, const Individual& ind) {
	//fill missing info() call
	
	ind.info(os);

	os << " ( sign:" << ind.sign << ") "<< std::endl;
	return os;
}