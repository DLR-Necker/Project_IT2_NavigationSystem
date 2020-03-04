#pragma once
#include <string>
#include <vector>
#include "City.h"

class Path
{
private:
	vector<City*> citysOnPath;			// potential memory leak
	unsigned int totalCost;				// maybe union  is  better suited

public:
	// Default Constructor
	Path();

	//Special Constructor
	Path(vector<City*> citysOnPath, unsigned int cost);

	// Destructor
	~Path();

	/*----------------------------------------------------------------------
							Methods
	-----------------------------------------------------------------------*/
	/*** Setter ***/
	void set_citysOnPath(vector<City*> citysOnPath);
	void setTotalCost(unsigned int totalCost);

	/*** Getter ***/
	vector<City*> get_citysOnPath();
	unsigned int getTotalCost();

	/*
	This method adds a city to the citysVisited vector
	@param	newCity					new city (pointer) to vector, that lies on path
	@return void
	*/

	void add_CitytoPath(City* currentCity);
};

