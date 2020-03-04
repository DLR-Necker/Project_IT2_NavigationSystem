#pragma once

#include "Way_Calculator.h"
#include <queue>

class Calculator_BestWay :
	protected Way_Calculator
{
protected:
	vector<Path> waysFound;
	priority_queue<Vertex> priorityQueue;

public:
	// Default Constructor
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
	vector<Path> search_BestWay(Vertex start, Vertex ende);
};


