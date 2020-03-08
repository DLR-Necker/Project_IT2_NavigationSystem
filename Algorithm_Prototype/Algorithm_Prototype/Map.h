#ifndef _MAP_H
#define _MAP_H

#include <vector>
#include <array>
#include "City.h"
#include "Network.h"
#include "Path.h"
#include "Way_Calculator.h"
#include "Calculator_BestWay.h"
#include "Calculator_EveryWay.h"
using namespace::std;

class Map
{					
	
public:
	// Attributes
	City* listCitys[maxCitys];									

	unsigned int network[maxCitys][maxCitys];				// muss in UML Diagramm angepasst werden

	enum type { none = 0, distance, time };

	type mapType;

	// Default Constructor
	Map();

	//Special Constructor
	//Map(/*type mapType,*/ );

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
	@return void
	*/
	void searchBestWay(City* start, City* end);

	/*
	This method determines every possible way from a starting point (City) to an end point (City) excluding loops. 
	@param	start		starting point
			end			end point
	@return void
	*/
	void searchEveryWay(City* start, City* end);

};

#endif