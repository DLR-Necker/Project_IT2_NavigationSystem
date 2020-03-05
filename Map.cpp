#include "pch.h"
#include "Map.h"
#include "Calculator_BestWay.h"
using namespace::std;

// Default Constructor
Map::Map() {}
									

// Special Constructor


// Default Deconstructor
Map::~Map() {}

/*----------------------------------------------------------------------
							Methods
-----------------------------------------------------------------------*/

vector<Path> Map::searchBestWay(City* start, City* end) {
	return ( new Calculator_BestWay(this))->findWay(start, end);
}

vector<Path> Map::searchEveryWay(City* start, City* end) {
	vector<Path> everyWay;
	return everyWay;
}


