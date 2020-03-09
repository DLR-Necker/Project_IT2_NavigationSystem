#ifndef _WAYCALC_
#define _WAYCALC_


#include<vector>
#include <string>
#include "Path.h"
#include "Map.h"
#include "utility.h"


class Way_Calculator
{
protected:
	int start_index;
	int end_index;
	Path currentPath;
	vector<Path> waysFound;		
	Map* map;

	/*----------------------------------------------------------------------
								Methods
	-----------------------------------------------------------------------*/

	/*
		This method converts a city from listCitys based on its name value into its index.
		@param	city					City to be indexed
		@return int	
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
							(Virtual)	Methods
	-----------------------------------------------------------------------*/

	/*
		This method finds a possible way between start and end. 
		If called from Calculator_BestWay, the cheapest path is calculated and returned.
		@param	start					start City
				end						end City
		@return Path*					pointer on generated Path object representing the result 
	*/

	virtual void findWay(City* start, City* end);

	/*
		This method prints the given path vector containing pointers to city objects to the console.
		@param	waysFound		vector with result paths
		@return void
	*/
	void print_waysFound();
	
};
#endif