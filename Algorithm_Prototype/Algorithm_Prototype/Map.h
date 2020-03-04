#pragma once

#include <vector>
#include <array>
#include "City.h"
#include "Network.h"
#include "Path.h"
using namespace::std;


class Map
{
private:
	// enum type { none, distance, time };						// wird wahrscheinlich nicht benötigt; Map sollte beide Netzwerke initialisieren, um zur Laufzeit damit arbeiten zu könnnen
	// type mapType; 
	
	
public:
	// Attributes
	City* listCitys[maxCitys];									// use of array<T,n> because usual Arrays can not be a return value -> needed for Constructor 

	int network[maxCitys][maxCitys];						

	// Default Constructor
	Map();

	//Special Constructor
	Map(/*type mapType,*/ );

	// Default Deconstructor
	~Map();

	// !!!!!!!! METHODS NEED TO BE MODIFIED!!!!!//

	/*----------------------------------------------------------------------
							Methods
	-----------------------------------------------------------------------*/

	/*
	This method determines the way with the least amount of costs - either distance- or time-wise - from a starting point (City) to an end point (City) based on the Dijkstra-Algorithm.
	@param	start		starting point
			end			end point 
	@return bestWay		result of the Dijksta-Algorithm
	*/
	vector<Path> searchBestWay(City* start, City* end);

	/*
	This method determines every possible way from a starting point (City) to an end point (City) excluding loops. 
	@param	start		starting point
			end			end point
	@return everyWay	result of the search
	*/
	vector<Path> searchEveryWay(City* start, City* end);


};
