#include "pch.h"
#include <string>
#include <array>
#include "Vertex.h"
using namespace::std;


// Default Constructor
Vertex::Vertex() {
	this->totalCost = -1;	//max unsigned int value (65,335)	
}

// Special Constructor
Vertex::Vertex(unsigned int cost, string name) {
	this->totalCost = cost;
	this->name = name;
}

// Copy Constructor --> TO BE IMPLEMENTED

// Default Deconstructor
Vertex::~Vertex() {}

/*----------------------------------------------------------------------
						Methods
-----------------------------------------------------------------------*/

/*
COMMENTARY
*/

//Setter
void Vertex::set_totalCost(unsigned int totalCost) {
	this->totalCost = totalCost;
}
void Vertex::setName(string name) {
	this->name = name;
}

void Vertex::setNeighbours(int city) {
	for (int i = 0; i < maxCitys; i++) {
		if (network_distance[city][i] > 0) {	// checks whether cost value greater than 0 is present -> connection to u exists
			neighbour* u = new neighbour();
			/* creating a new neigbour and initializing name, distance and time costs */
			u->name = citys[i];
			u->cost_distance = network_distance[city][i];
			u->cost_time = network_time[city][i];
			neighbours.push_back(*u);			// adding neighbour u to neighbours vector  
		}
	}

}

//Getter
unsigned int Vertex::get_totalCost() {
	return this->totalCost;
}
string Vertex::getName() {
	return this->name;
}
vector<neighbour> Vertex::getNeighbours() {
	return this->neighbours;
}
