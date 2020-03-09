#ifndef _PATH_
#define _PATH_

#include <string>
#include <vector>
#include "City.h"
using namespace::std;

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
							(Virtual) Methods
	-----------------------------------------------------------------------*/
	/*** Setter ***/
	void set_citysOnPath(vector<City*> citysOnPath);
	void setTotalCost(unsigned int totalCost);

	/*** Getter ***/
	vector<City*> get_citysOnPath();
	unsigned int getTotalCost();

	/*
	These methods add/delete a city to a path vector at the last position
	@param	newCity					new city (pointer) to vector, that lies on path
	@return void
	*/

	void add_CitytoPath_BW(City* currentCity);		// Used by Calculator_BestWay
	void add_CitytoPath_EW(City* currentCity);		// Used by Calculator_EveryWay
	void delete_CityfromPath();
};
#endif