#include "pch.h"
#include <iostream>
#include "Way_Calculator.h"

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

Path* Way_Calculator::findWay(City * start, City * end)
{
	cout << "Fehlende Methode in der Subklasse!" << endl;
	Path* p = new Path();
	return p;
}

void Way_Calculator::print_waysFound() {

	for (unsigned int i = 0; i < waysFound.size(); i++) {

		for (unsigned int j = 0; j < waysFound[i].get_citysOnPath().size(); j++) {
			if (i = waysFound.size()) {											// last city on path is reached
				cout << waysFound[i].get_citysOnPath()[j]->getName() << ": ";
			}

			cout << ", ";
		}

		

		if ( (int) map->mapType == 1) {		// 1: mapType == distance
			cout << waysFound[i].getTotalCost() << " km" << endl;
		}
		else if ((int)map->mapType == 2) {	// 2: mapType == time

			cout << utility().convert_minutesToHours(waysFound[i].getTotalCost()) << " hrs" << endl;
		}
		else {	
			cout << " (no map Type found)";
		}
			
	}
}
		


