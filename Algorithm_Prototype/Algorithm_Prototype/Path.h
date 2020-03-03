#pragma once
#include <string>
#include <vector>
#include "City.h"

class Path
{
private:
	vector<City*> citysVisited;			// potential memory leak
	unsigned int totalCost;				// maybe union  is  better suited

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
	void setTotalCost(unsigned int totalCost);

	/*** Getter ***/
	vector<City*> getCitysVisited();
	unsigned int getTotalCost();

	/*
	This method adds a city to the citysVisited vector
	@param	newCity					new city (pointer) to vector, that lies on path
	@return void
	*/

	void add_CitytoPath(City* currentCity);
};

