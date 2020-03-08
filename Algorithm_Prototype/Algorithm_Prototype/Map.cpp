#include "pch.h"
#include "Map.h"
#include <iostream>


// Default Constructor
Map::Map() {}

// Special Constructor

// Default Deconstructor
Map::~Map() {}

/*----------------------------------------------------------------------
							Methods
-----------------------------------------------------------------------*/

void Map::searchBestWay(City* start, City* end) {
	cout << "**** Searching for shortest and fastest way... *****" << endl;
	Calculator_BestWay* cb = new Calculator_BestWay(this);
	cb->findWay(start, end);
}

void Map::searchEveryWay(City* start, City* end) {
	cout << "**** Searching for every way... *****" << endl;
	Calculator_EveryWay* ce = new Calculator_EveryWay(this);
	ce -> findWay(start, end);
}

