#include "pch.h"
#include "Path.h"
using namespace::std;

// Default Constructor
Path::Path() {}

//Special Constructor
Path::Path(vector<Vertex> citysOnPath, unsigned int totalCost) {
	this->citysOnPath = citysOnPath;
	this->totalCost = totalCost;
}

// Destructor
Path::~Path() {}

/*----------------------------------------------------------------------
						Methods
-----------------------------------------------------------------------*/
/*** Setter ***/
void Path::set_citysOnPath(vector<Vertex> citysOnPath) {
	this->citysOnPath = citysOnPath;
}
void Path::setTotalCost(unsigned int totalCost) {
	this->totalCost = totalCost;
}

/*** Getter ***/
vector<Vertex> Path::get_citysOnPath() {
	return this->citysOnPath;
}
unsigned int Path::getTotalCost() {
	return this->totalCost;
}
/*** Additional Methods ***/
void Path::add_CitytoPath(Vertex currentCity) {
	this->citysOnPath.push_back(currentCity);
}
