#include "pch.h"
#include "Map.h"
using namespace::std;

// Default Constructor
Map::Map() {
	Map::generate_Network();										// initialization of the network from adjacent matrix given in "Network.h"
}

// Special Constructor
Map::Map(array<City*, maxCitys> listCitys, array<Vertex, maxCitys> network) {
	this->listCitys = listCitys;
	this->network = network;
}

// Default Deconstructor
Map::~Map() {}

/*----------------------------------------------------------------------
							Methods
-----------------------------------------------------------------------*/
void Map::generate_Network() {
	for (int i = 0; i < maxCitys; i++) {
		Vertex* v = new Vertex();									// Default Constructor initializes totalCost with  max value of unsigned int
		v->setName(citys[i]);										// citys[] is a list of cities provided in "Network.h"
		v->setNeighbours(i);										// initializes the neighbours vector 
		this->network[i] = *v;											// adding vertex to network array
	}
}

vector<City*> Map::searchBestWay(City* start, City* end) {
	vector<City*> bestWay;
	return bestWay;
}

vector<City*> Map::searchEveryWay(City* start, City* end) {
	vector<City*> everyWay;
	return everyWay;
}


