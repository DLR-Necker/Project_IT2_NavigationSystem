#include "pch.h"
#include "Calculator_EveryWay.h"

// Default Constructor
Calculator_EveryWay::Calculator_EveryWay() {}

// Special Constructor
Calculator_EveryWay::Calculator_EveryWay(Map* map):Way_Calculator(map) {}


// Destructor
Calculator_EveryWay::~Calculator_EveryWay() {}

/*----------------------------------------------------------------------
						Methods
-----------------------------------------------------------------------*/

/*** Additional Methods ***/

vector<int> Calculator_EveryWay::findNeighbours(int currentCityIndex) {
	// Initialise neighbour vector:
	vector<int> neighbours;
	// Screen network for neighbours of current City
	for (int i = 0; i = maxCitys; i++) {
		if (map->network[currentCityIndex][i] != 0) {
			neighbours.push_back(i);
		}
	}
	return neighbours;
}

int Calculator_EveryWay::totalPathCost(Path currentPath, int currentCityIndex, int neighbourCityIndex) {
	unsigned int newPathcost = ( currentPath.getTotalCost() ) + ( map->network[currentCityIndex][neighbourCityIndex] );
	return newPathcost;
}

Path* Calculator_EveryWay::findWay(City* start, City* end){

	// Converts start (current) city into its respective network array index:
	int currentCityIndex = cityToIndex(start);
	int endCityIndex = cityToIndex(end);

	//Get current Path:
	Path currentPath = this->currentPath;

	/* Find next city along the path -> Backtracking
	   3 cases: 1. End is reached				--> successful path --> store to vector  waysFound --> back to previous city
				2. Neighbour was visited	    --> go back to previous city on the path with unvisited neighbours
				3. Unvisited neighbours found	--> go to next unvisited neighbour
	*/
	// 1. Is end reached?:
	if (currentCityIndex == endCityIndex) {
		currentPath.add_CitytoPath(start);			// Store current city to path								
		this->waysFound.push_back(currentPath);		// Store path to waysFound									
		return &(currentPath);						// Go back to previous city
	}

	// 2. Are there visited neighbours?
	auto neighbours = findNeighbours(currentCityIndex);	// Call findNeighbours to create array of neighbouring city indices
	
	visitedCitys[maxCitys] = this->visitedCitys;

	for (int j = 0; j < neighbours.size() ; j++) {
		if (visitedCitys[neighbours[j]] == 1) {}		// Check if neighbour at index i was already visited. if yes, go ahead

	 // 3. Unvisited neighbours
		else {											// Call findWay again to move one step ahead.						
			// Store current city to path
			currentPath.add_CitytoPath(map->listCitys[currentCityIndex]);
			// Update total cost of path (time or distance)
			currentPath.setTotalCost(totalPathCost(currentPath, currentCityIndex, neighbours[j]));
			// Set current Path attribute of Calculator_EveryWay
			this->currentPath = currentPath;
			//Set current city status to visited
			this->visitedCitys[currentCityIndex] = 1;
			// Go one step ahead by calling findWay with first unvisited neighbour
			findWay(map->listCitys[neighbours[j]], end);
		}
	}
	// Delete last city on path because it will be added in the next iteration.
	currentPath.delete_CityfromPath();
	this->visitedCitys[currentCityIndex] = 0;
	return &(currentPath);
}

