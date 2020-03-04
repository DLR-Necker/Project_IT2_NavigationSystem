#pragma once
#include <string>
#include <vector>
#include "City.h"
#include "Vertex.h"
using namespace::std;

class Path
{
private:
	vector<Vertex> citysOnPath;
	unsigned int totalCost;				// maybe union  is  better suited

public:
	// Default Constructor
	Path();

	//Special Constructor
	Path(vector<Vertex> citysOnPath, unsigned int cost);

	// Destructor
	~Path();

	/*----------------------------------------------------------------------
							Methods
	-----------------------------------------------------------------------*/
	/*** Setter ***/
	void set_citysOnPath(vector<Vertex> citysOnPath);
	void setTotalCost(unsigned int totalCost);

	/*** Getter ***/
	vector<Vertex> get_citysOnPath();
	unsigned int getTotalCost();

	/*
	This method adds a city to the citysVisited vector
	@param	newCity					new city (pointer) to vector, that lies on path
	@return void
	*/

	void add_CitytoPath(Vertex currentCity);
};


