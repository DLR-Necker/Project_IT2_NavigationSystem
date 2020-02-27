#include "pch.h"
#include "Map.h"
using namespace::std;

// Default Constructor
Map::Map() {
	this->mapType = none;												// Defines Map type
}

// Special Constructor
Map::Map(type mapType, City* listCitys[], vector<vector<int>> network) {
	this->mapType = mapType;
}

// Default Deconstructor
Map::~Map() {}

/*----------------------------------------------------------------------
							Methods
-----------------------------------------------------------------------*/
vector<City*> Map::searchBestWay(City* start, City* end) {
	vector<City*> bestWay;
	return bestWay;
}

vector<City*> Map::searchEveryWay(City* start, City* end) {
	vector<City*> everyWay;
	return everyWay;
}


