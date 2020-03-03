#include "pch.h"
#include "Calculator_EveryWay.h"

// Default Constructor
Calculator_EveryWay::Calculator_EveryWay() {}


// Destructor
Calculator_EveryWay::~Calculator_EveryWay() {}

/*----------------------------------------------------------------------
						Methods
-----------------------------------------------------------------------*/
/*** Setter ***/
void Calculator_EveryWay::setPossiblePaths(vector<Path> possiblePaths) {
	this->possiblePaths = possiblePaths;
}

/*** Getter ***/
vector<Path> Calculator_EveryWay::getPossiblePaths() {
		return this->possiblePaths;
}

/*** Additional Methods ***/
void Calculator_EveryWay::add_PathtoPossiblePaths(Path currentPath) {
	this->possiblePaths.push_back(currentPath);
}

Path Calculator_EveryWay::everyWay(City* currentCity, City* end)
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
		
	} // Search continous, because no break condition is met.
	else {

	}
		return Path();

}