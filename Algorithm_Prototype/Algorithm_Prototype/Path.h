#pragma once
#include <string>
#include <vector>
#include "City.h"

class Path
{
private:
	vector<City*> citysVisited;			// potential memory leak
	unsigned int cost;

public:
	// Default Constructor
	Path();

	//Special Constructor
	Path(vector<City*> citysVisited, unsigned int cost);

	// Destructor
	~Path();

	/*----------------------------------------------------------------------
							Methods
	-----------------------------------------------------------------------*/
	/*** Setter ***/
	void setCitysVisited(vector<City*> citysVisited);
	void setCost(unsigned int cost);

	/*** Getter ***/
	vector<City*> getCitysVisited();
	unsigned int getCost();

	/*
	This method adds a city to the citysVisited vector
	@param	newCity					new city (pointer) to vector, that lies on path
	@return void
	*/

	void add_CitytoPath(City* currentCity);
};

