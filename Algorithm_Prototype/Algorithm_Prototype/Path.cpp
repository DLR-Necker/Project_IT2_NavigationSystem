#include "pch.h"
#include "Path.h"

// Default Constructor
Path::Path() {}

//Special Constructor
Path::Path(std::vector<City*> citysOnPath, unsigned int totalCost) {
	this->citysOnPath = citysOnPath;
	this->totalCost = totalCost;
}

// Destructor
Path::~Path() {
	//vector city delete
}

/*----------------------------------------------------------------------
						Methods
-----------------------------------------------------------------------*/
/*** Setter ***/
void Path::set_citysOnPath(std::vector<City*> citysOnPath) {
	this->citysOnPath = citysOnPath;
}
void Path::setTotalCost(unsigned int totalCost) {
	this->totalCost = totalCost;
}

/*** Getter ***/
std::vector<City*> Path::get_citysOnPath() {
	return this->citysOnPath;
}
unsigned int Path::getTotalCost() {
	return this->totalCost;
}
/*** Additional Methods ***/
void Path::add_CitytoPath_BW(City* currentCity) {
	this->citysOnPath.insert(citysOnPath.begin(), currentCity);				// generates vector from start to end point by inserting the current City* to the front. 
																			// Dijkstra's algorithm uses predecessors to determine the path hence calculating from end to start.
}

void Path::add_CitytoPath_EW(City* currentCity) {
	this->citysOnPath.push_back(currentCity);
}

void Path::delete_CityfromPath(){
	this->citysOnPath.pop_back();
}