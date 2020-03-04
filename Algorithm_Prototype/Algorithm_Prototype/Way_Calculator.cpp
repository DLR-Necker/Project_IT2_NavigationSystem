#include "pch.h"
#include <iostream>
#include "Way_Calculator.h"
using namespace::std;

// Default Constructor
Way_Calculator::Way_Calculator() {};

// Special Constructor
 Way_Calculator::Way_Calculator(Map* map) {
	 this->map = map;
 }

// Default Deconstructor
Way_Calculator::~Way_Calculator() {}


/*----------------------------------------------------------------------
								Methods
	-----------------------------------------------------------------------*/

int Way_Calculator::cityToIndex(City* city) {
	// Find City in listCity
	int i = 0;
	while (map->listCitys[i] != city) {
		i++;
	}
	return i;
}

vector<Path*> Way_Calculator::findWay(City * start, City * end)
{
	cout << "Fehlende Methode in der Subklasse!" << endl;
	return vector<Path*>();
}
;
