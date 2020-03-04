#include "pch.h"
#include "Path.h"

// Default Constructor
Path::Path() {}

//Special Constructor
Path::Path(vector<City*> citysOnPath, unsigned int totalCost) {
	this->citysOnPath = citysOnPath;
	this->totalCost = totalCost;
}

// Destructor
Path::~Path() {}

/*----------------------------------------------------------------------
						Methods
-----------------------------------------------------------------------*/
/*** Setter ***/
void Path::set_citysOnPath(vector<City*> citysOnPath) {
	this->citysOnPath = citysOnPath;
}
void Path::setTotalCost(unsigned int totalCost) {
	this->totalCost = totalCost;
}

/*** Getter ***/
vector<City*> Path::get_citysOnPath() {
	return this->citysOnPath;
}
unsigned int Path::getTotalCost() {
	return this->totalCost;
}
/*** Additional Methods ***/
void Path::add_CitytoPath(City* currentCity) {
	this->citysOnPath.push_back(currentCity);
}
