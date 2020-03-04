#pragma once

#include <queue>
#include "Way_Calculator.h"
using namespace::std;

class Calculator_BestWay :
	protected Way_Calculator
{
protected:
	vector<Path> waysFound;								// Path object stores visited Cities in order together with their total Cost from start
	priority_queue<int> pq;								// Priority Queue needed for Dijekstra algorithm
	struct nodeData { bool visited;						// contains all relevant Data for Dijkstra algorithm
					  unsigned int tentativeCost;		
				      int predecessor;  
				    };
	nodeData nodes[maxCitys];							// Collector of all knots with their corresponding data



public:
	// Default Constructor
	Calculator_BestWay();

	// Special Constructor 
	Calculator_BestWay(Map* map);
	
	// Default Deconstructor
	~Calculator_BestWay();


	/*----------------------------------------------------------------------
								Methods
	-----------------------------------------------------------------------*/

	/*
		This is the overwritten virtual method of Way_Calculator which calculates the fastest way within the network from start City to end City. 
		It is based on the Dijkstra algorithm.
		@param	start					start City
				end						end City
		@return bestWay					vector of best ways found
	*/
	virtual vector<Path*> findWay(City* start, City* end);

	/*
		This method initialize the Dijkstra algorithm
		@param	start					start City
				end						end City
		@return bestWay					vector of best ways found
	*/
	void initialize(City * start, City * end);

};


