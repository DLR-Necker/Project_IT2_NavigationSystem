#include "pch.h"
#include "Way_Calculator.h"

// Default Constructor
Way_Calculator::Way_Calculator() {};

// Special Constructor
 Way_Calculator::Way_Calculator(Map* map) {
	 this->map = map;
 }

// Default Deconstructor
Way_Calculator::~Way_Calculator() {};

int Way_Calculator::cityToIndex(City* city) {
	// Find City in listCity
	int i = 0;
	while (map->listCitys[i] != city) {
		i++;
	}
	return i;
}