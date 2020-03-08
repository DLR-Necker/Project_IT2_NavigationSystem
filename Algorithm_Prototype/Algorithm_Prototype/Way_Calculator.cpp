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

void Way_Calculator::findWay(City * start, City * end)
{
	cout << "Fehlende Methode in der Subklasse!" << endl;
}

void Way_Calculator::print_waysFound() {
	cout << "Printing result..." << endl;
	for (unsigned int i = 0; i < waysFound.size(); i++) {
		Path* p = &waysFound[i];
		for (unsigned int j = 0; j < p->get_citysOnPath().size(); j++) {
			if ( j == ((p->get_citysOnPath().size())-1) ) {											// last city on path is reached
				cout << p->get_citysOnPath()[j]->getName() << ": ";
			}
			else {
				cout << p->get_citysOnPath()[j]->getName();
				cout << ", ";
			}
		}

		

		if ( (int) map->mapType == 1) {		// 1: mapType == distance
			cout << p->getTotalCost() << " km" << endl;
		}
		else if ((int)map->mapType == 2) {	// 2: mapType == time

			cout << utility().convert_minutesToHours(p->getTotalCost()) << " hrs" << endl;
		}
		else {	
			cout << " (no map Type found)";
		}
			
	}
}
		


