#include "pch.h"
#include "Calculator_BestWay.h"

// Default Constructor
Calculator_BestWay::Calculator_BestWay(){}

// Special Constructor
Calculator_BestWay::Calculator_BestWay(Map* map):Way_Calculator(map) {}

// Default Deconstructor
Calculator_BestWay::~Calculator_BestWay() {}


/*----------------------------------------------------------------------
							Methods
-----------------------------------------------------------------------*/


vector<Path*> Calculator_BestWay::findWay(City * start, City * end) 
{
	/*** Initialization of Dijkstra ***/
	initialize(start, end);

	

	



	return vector<Path*>();
}

void  Calculator_BestWay::initialize(City* start, City* end) {
	// Creating the start and end indices
	int start = cityToIndex(start);
	int end = cityToIndex(end);

	// Initialize knots before algorithm starts; set tentative cost of all knots except start to max unsigned int value (4,294,967,295) 
	for (int i = 0; i < maxCitys; i++) {
		if (i = this->start) {
			nodes[i].tentativeCost = 0;
		}
		nodes[i].visited = false;
		nodes[i].tentativeCost = -1;
		nodes[i].predecessor = -1;				// -1: no predecesor at the moment; only set when shortest way found from start to current node via predecessor  
	}

}


