#pragma once
#include "Way_Calculator.h"
#include "Path.h"
#include "Map.h"
using namespace::std;


class Calculator_EveryWay :
	public Way_Calculator
{
protected:


public:
	// Default Constructor
	Calculator_EveryWay();

	// Default Deconstructor
	~Calculator_EveryWay();

	/*----------------------------------------------------------------------
							Methods
	-----------------------------------------------------------------------*/

	/*** Additional Methods ***/

	/*
	This method adds a path to the possiblePaths vector.
	@param	currentPath						Successful path that led to the destination city
	@return void					
	*/

	void add_PathtoWaysFound(Path currentPath);

	/*
	This method finds all unvisited neighbours of the current city on the path 
	@param	currentCity						The current city along the path whose unvisited neighbours are to be found
	        endCity							Destination city (is always the same). Is obtained from Way_Calculator
	@return bool							True, if an unvisited neighbour or endCity is found / False, if no unvisited neighbour is found
	*/

	bool neighbours(City* currentCity, City* endCity);

};

