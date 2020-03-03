#include "pch.h"
#include "Path.h"

// Default Constructor
Path::Path() {}

//Special Constructor
Path::Path(vector<City*> citysVisited, unsigned int cost) {
	this->citysVisited = citysVisited;
	this->cost = cost;
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
void Path::setCost(unsigned int cost) {
	this->cost = cost;
}

/*** Getter ***/
vector<City*> Path::getCitysVisited() {
	return this->citysVisited;
}
unsigned int Path::getCost() {
	return this->cost;
}
/*** Additional Methods ***/
void Path::add_CitytoPath(City* currentCity) {
	this->citysVisited.push_back(currentCity);
}
