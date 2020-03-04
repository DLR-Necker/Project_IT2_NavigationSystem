#pragma once

#include<vector>
#include <string>
#include "Path.h"
#include "Map.h"
//#include "Network.h"
using namespace::std;

class Way_Calculator
{
protected:
	int start;
	int ende;
	vector<Path> waysFound;		// potential memory leak
	Map* map;

	/*----------------------------------------------------------------------
								Methods
	-----------------------------------------------------------------------*/

	/*
		This method converts start and end city based on their names in listCitys into indices based on listCitys
		@param	start					start City
				end						end City
		@return void
	*/
	int cityToIndex(City* city);

public:
	// Default Constructor
	Way_Calculator();

	// Special Constructor
	Way_Calculator(Map* map);

	// Default Deconstructor
	~Way_Calculator();

	/*----------------------------------------------------------------------
							Virtual	Methods
	-----------------------------------------------------------------------*/

	/*
		This method converts start and end city based on their names in listCitys into indices based on listCitys
		@param	start					start City
				end						end City
		@return void
	*/



};