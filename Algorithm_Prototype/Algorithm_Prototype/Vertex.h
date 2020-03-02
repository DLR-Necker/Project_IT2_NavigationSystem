#pragma once
#include "Map.h"

class Vertex
{

private:
	unsigned int cost;
	string name;			// To be retrieved from listCitys[]

public:
	// Default Constructor
	Vertex();
	
	// Special Constructor
	Vertex(unsigned int cost, string name);

	// Copy Constructor --> TO BE IMPLEMENTED

	// Default Deconstructor
	~Vertex();

	/*----------------------------------------------------------------------
							Methods
	-----------------------------------------------------------------------*/

	/*
	This method determines the way with the least amount of costs - either distance- or time-wise - from a starting point (City) to an end point (City) based on the Dijkstra-Algorithm.
	@param	start		starting point
			end			end point
	@return bestWay		result of the Dijksta-Algorithm
	*/

	//Setter
	void setCost(unsigned int cost);
	void setName(string name);

	//Getter
	unsigned int getCost();
	string getName();
};

