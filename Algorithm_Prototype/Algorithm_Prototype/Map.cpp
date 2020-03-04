#include "pch.h"
#include "Map.h"
using namespace::std;

// Default Constructor
Map::Map() {
	Map::generate_Network();										// initialization of the network from adjacent matrix given in "Network.h"
}

// Special Constructor
/*
Map::Map() {
	
}*/

// Default Deconstructor
Map::~Map() {}

/*----------------------------------------------------------------------
							Methods
-----------------------------------------------------------------------*/


void Map::searchBestWay(City* start, City* end) {
	
	
}




