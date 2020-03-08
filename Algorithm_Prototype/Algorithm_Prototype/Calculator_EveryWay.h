#ifndef _CalcEW_
#define _CalcEW_

#include "Way_Calculator.h"

class Calculator_EveryWay :
	public Way_Calculator
{
protected:
	bool visitedCitys[maxCitys];	// Array indices represent indices of each city in listcitys. True: City visited (1) ; False: City not visited (0)
	Path currentPath;
	//City* currentCity;

public:
	// Default Constructor
	Calculator_EveryWay();

	// Special Constructor
	Calculator_EveryWay(Map* map);

	// Default Deconstructor
	~Calculator_EveryWay();

	/*----------------------------------------------------------------------
							Methods
	-----------------------------------------------------------------------*/

	/*** Additional Methods ***/

	/*
	This method finds all neighbours of the current city on the current path
	@param	currentCityIndex				City whose neighbours are to be found.
	@return vector<int>						returns all indices of neighbour cities.
	*/

	std::vector<int> findNeighbours(int currentCityIndex);

	/*
	This method determines the total Cost of the current path
	@param	currentPath						Path object whose total cost is to be updated.
			currentCityIndex				Current city on the path
			neighbourCityIndex				Index of unvisited neighbouring city which is next along the path.
	@return vector<int>						returns all indices of neighbour cities.
	*/

	int totalPathCost(Path currentPath, int currentCityIndex, int neighbourCityIndex);

	/*
	This method returns a possible path between start and destination.
	@param	start					start City
			end						destination City
	@return Path					Successful path between start and end
	*/

	virtual Path* findWay(City* start, City* end);

};

#endif 

