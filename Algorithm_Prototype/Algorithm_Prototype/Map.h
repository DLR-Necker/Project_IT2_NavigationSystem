#pragma once

#include <vector>
#include "City.h"
#include "Network.h"
using namespace::std;

class Map
{
private:
	enum type { none, distance, time };
	type mapType;
	vector<vector<int>> network;

public:
	// Attributes
	City* listCitys[maxCitys];

	// Default Constructor
	Map();

	//Special Constructor
	Map(type mapType, City* listCitys[maxCitys], vector<vector<int>> network);

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
	vector<City*> searchBestWay(City* start, City* end);

	/*
	This method determines every possible way from a starting point (City) to an end point (City) excluding loops. 
	@param	start		starting point
			end			end point
	@return everyWay	result of the search
	*/
	vector<City*> searchEveryWay(City* start, City* end);


};
