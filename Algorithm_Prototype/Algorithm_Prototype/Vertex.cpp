#include "pch.h"
#include "Vertex.h"
#include <string>
using namespace::std;


// Default Constructor
Vertex::Vertex() {
	this->cost = -1;	//max unsigned int value (65,335)	
}

// Special Constructor
Vertex::Vertex(unsigned int cost, string name) {
	this->cost = cost;
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
void Vertex::setCost(unsigned int cost) {
	this->cost = cost;
}
void Vertex::setName(string name) {
	this->name = name;
}

//Getter
unsigned int Vertex::getCost() {
	return this->cost;
}
string Vertex::getName() {
	return this->name;
}
