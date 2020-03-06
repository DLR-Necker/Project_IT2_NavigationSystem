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
	int start_index;
	int end_index;
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
		This method calculates the cheapest way from start to end throughout the network
		@param	start					start City
				end						end City
		@return Path*					pointer on generated Path object representing the result 
	*/

	virtual Path* findWay(City* start, City* end);

	/*
		This method converts start and end city based on their names in listCitys into indices based on listCitys
		@param	start					start City
				end						end City
		@return void
	*/
	virtual void printPath(vector<Path> waysFound);

};