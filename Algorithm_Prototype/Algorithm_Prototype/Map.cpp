#include "pch.h"
#include "Map.h"
#include "Way_Calculator.h"
#include "Calculator_BestWay.h"
#include "Calculator_EveryWay.h"
#include <iostream>


// Default Constructor
Map::Map() {}

// Special Constructor

// Default Deconstructor
Map::~Map() {
	delete listCitys[maxCitys];
}

/*----------------------------------------------------------------------
							Methods
-----------------------------------------------------------------------*/

void Map::searchBestWay(City* start, City* end) {
	cout << "**** Searching for shortest and fastest way... *****" << endl;
	Calculator_BestWay* cb = new Calculator_BestWay(this);
	cb->findWay(start, end);
	cb->print_waysFound();
}

void Map::searchEveryWay(City* start, City* end) {
	cout << "**** Searching for every way... *****" << endl;
	Calculator_EveryWay* ce = new Calculator_EveryWay(this);
	ce -> findWay(start, end);
	ce->print_waysFound();
}

