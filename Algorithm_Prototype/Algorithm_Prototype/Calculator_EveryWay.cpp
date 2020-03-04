#include "pch.h"
#include "Calculator_EveryWay.h"

// Default Constructor
Calculator_EveryWay::Calculator_EveryWay() {}


// Destructor
Calculator_EveryWay::~Calculator_EveryWay() {}

/*----------------------------------------------------------------------
						Methods
-----------------------------------------------------------------------*/

/*** Additional Methods ***/

void Calculator_EveryWay::add_PathtoWaysFound(Path currentPath) {
	Way_Calculator::waysFound.push_back(currentPath);
}

bool Calculator_EveryWay::neighbours(City* currentCity, City* endCity){

	//Break Conditions: endCity is reached ; no unvisited neighbours
	// Check, if either one condition is met: 

	if (currentCity == endCity) {
		//Store currentCity to Path
		
		// Store Path to waysFound
		
		return true; 
	}

	if (/*are neighbours of current city part of path?*/) {
		return false;
	}

}







/*

{	
	//Define map matrice to be used for calculation:
	unsigned int currentDistance = Way_Calculator::network_distance[0][1];

	// Retrieve matrice position of current city and end from network array:


	// Create neighbour array based on network matrice:
	// Define row of array depending on city: 
	int city = ;								//number of city
	for (int i = 0; i = maxCitys; i++) {
		
	}


	// 1st break condition of search: destination is reached 
	if (currentCity == end) {
		// Add currentCity to Path
		add_CitytoPath(City* currentCity);
		// Add path to possiblePaths
		this->Calculator_EveryWay::add_PathtoPossiblePaths(Path currentPath);
		//return possiblePaths
		return Path();

	} // 2nd break condition of search: no more unvisited neighbouring cities 
	else if (...) {
		
	} // Search continues, because no break condition is met.
	else {

	}
		return Path();

}

*/