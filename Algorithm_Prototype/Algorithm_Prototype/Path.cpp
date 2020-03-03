#include "pch.h"
#include "Path.h"

// Default Constructor
Path::Path() {}

//Special Constructor
Path::Path(vector<City*> citysVisited, unsigned int totalCost) {
	this->citysVisited = citysVisited;
	this->totalCost = totalCost;
}

// Destructor
Path::~Path() {}

/*----------------------------------------------------------------------
						Methods
-----------------------------------------------------------------------*/
/*** Setter ***/
void Path::setCitysVisited(vector<City*> citysVisited) {
	this->citysVisited = citysVisited;
}
void Path::setTotalCost(unsigned int totalCost) {
	this->totalCost = totalCost;
}

/*** Getter ***/
vector<City*> Path::getCitysVisited() {
	return this->citysVisited;
}
unsigned int Path::getTotalCost() {
	return this->totalCost;
}
/*** Additional Methods ***/
void Path::add_CitytoPath(City* currentCity) {
	this->citysVisited.push_back(currentCity);
}
