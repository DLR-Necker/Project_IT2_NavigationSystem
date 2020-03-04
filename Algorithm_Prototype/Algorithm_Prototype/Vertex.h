#pragma once
#include <vector>
#include "Neighbours.h"
#include "Network.h"
using namespace::std;

class Vertex
{

private:
	string name;
	unsigned int totalCost;				// holding total cost to reach this vertix from start vertix
	vector<neighbour> neighbours;		// muss für einen Vector der Zuweisungsoperator angepasst werden; wird dieser als pointer behandelt?
	bool visited;


public:
	// Default Constructor
	Vertex();

	// Special Constructor
	Vertex(unsigned int totalCost, string name);

	// Copy Constructor 
	Vertex(const Vertex &v);

	// Default Deconstructor
	~Vertex();

	/*----------------------------------------------------------------------
							Operators
	-----------------------------------------------------------------------*/
	// Allocator
	Vertex operator=(const Vertex &V);

	/*
	The following overloading of comparing operators is neded for the operation with priority queues for the Dijkstra algorithm.
	The key value for the insertion of a Vertex into the priority queue is its tentative totalCost
	*/
	// Equality
	bool operator==(const Vertex &v);

	// Greater 
	bool operator>(const Vertex &v);

	// Less
	bool operator<(const Vertex& v);

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
	void set_totalCost(unsigned int totalCost);
	void setName(string name);

	/*
	This method searches for the neighbours of city based on the adjacent matrice provided in "Network.h"
	@param	city		row of the city in the matrice for which neighbours are to be searched
	@return void
	*/
	void setNeighbours(int city);

	//Getter
	unsigned int get_totalCost();
	string getName();
	vector<neighbour> getNeighbours();
};

