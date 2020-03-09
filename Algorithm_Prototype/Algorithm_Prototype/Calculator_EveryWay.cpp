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

vector<int> Calculator_EveryWay::findNeighbours(int currentCityIndex) {
	// Initialise neighbour vector:
	vector<int> neighbours;
	// Screen network for neighbours of current City
	for (int i = 0; i < maxCitys; i++) {
		if (map->network[currentCityIndex][i] > 0) {
			neighbours.push_back(i);
		}
	}
	return neighbours;
}

void Calculator_EveryWay::totalPathCost() {
	for (unsigned int i = 0; i < waysFound.size(); i++) {								// outer iterator on vector waysFound
		unsigned int tentCost = 0;
		int this_index = 0;
		int next_index = 0;

		for (unsigned int j = 0; j < waysFound[i].get_citysOnPath().size()-1; j++) {	// inner iterator on vector citysOnPath
			vector<City*> currentP = waysFound[i].get_citysOnPath();
			unsigned int a = j + 1;
			this_index = cityToIndex(currentP[j]);
			next_index = cityToIndex(currentP[a]);
			tentCost += map->network[this_index][next_index];
		}

		waysFound[i].setTotalCost(tentCost);
	}

}
void Calculator_EveryWay::findWay(City* start, City* end){

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
	// 1. CHECK IF END IS REACHED:
	if (currentCityIndex == endCityIndex) {
		currentPath.add_CitytoPath_EW(start);															// Store current city to path								
		waysFound.push_back(currentPath);																// Store path to waysFound	
		currentPath.delete_CityfromPath();																// Delete last city on path because it will be added in the next iteration.
		this->currentPath = currentPath;
		return;
	}

	// 2. CHECK FOR UNVISITED NEIGHBOURS:
	// 2.1. Find all neighbours
	auto neighbours = findNeighbours(currentCityIndex);													// Call findNeighbours to create array of neighbouring city indices

	// 2.2. Check, which neighbours were already visited along the path:
	visitedCitys[maxCitys] = this->visitedCitys;
 
	for (unsigned int j = 0; j < neighbours.size() ; j++) {											
		if (visitedCitys[neighbours[j]] != 1) {																// Go ahead, if current neighbour is unvisited 
			currentPath.add_CitytoPath_EW(map->listCitys[currentCityIndex]);								// Store current city to path
			this->currentPath = currentPath;																// Set current Path attribute of Calculator_EveryWay
			visitedCitys[currentCityIndex] = 1;																//Set current city status to visited	

			findWay(map->listCitys[neighbours[j]], end);													// Call findWay again to move one step ahead.		
			
			currentPath.delete_CityfromPath();																	// Delete last city on path, otherwise it will be added multiple times.
			this->currentPath = currentPath;
		}
	}

	this->visitedCitys[currentCityIndex] = 0;																// Reset current city to unvisited 	
}

