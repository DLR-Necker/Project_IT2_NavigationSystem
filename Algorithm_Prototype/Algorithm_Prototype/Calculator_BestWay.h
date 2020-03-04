#pragma once

#include "Way_Calculator.h"
#include <queue>

class Calculator_BestWay :
	public Way_Calculator
{
protected:
	priority_queue<int> priorityQueue;

public:
	// Default Constructor
	Calculator_BestWay();

	// Special Constructor
	Calculator_BestWay();

    // Default Deconstructor
	~Calculator_BestWay();

	/*----------------------------------------------------------------------
							Methods
	-----------------------------------------------------------------------*/

	/*
	This method determines the way with the least amount of costs - either distance- or time-wise - from a starting point (City) to an end point (City) based on the Dijkstra-Algorithm.
	@param	start		starting point
			end			end point
	@return bestWay		result of the Dijksta-Algorithm
	*/
	vector<Path> search_BestWay(int start, int ende);
};


