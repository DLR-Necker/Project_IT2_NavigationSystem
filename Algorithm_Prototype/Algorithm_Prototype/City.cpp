#include "pch.h"
#include "City.h"

// Default Constructor
City::City() {};

// Special Constructor
City::City(string name, string country, int population) {
	this->name = name;
	this->country = country;
	this->population = population;
}

// Special Deconstructor
City::~City() {};

/*----------------------------------------------------------------------
							Methods
-----------------------------------------------------------------------*/

/*** Setter ***/
void City::setName(string name) {
	this->name = name;
}
void City::setCountry(string country) {
	this->country = country;
}
void City::setPopulation(int population) {
	this->population = population;
}

/*** Getter ***/
string City::getName() {
	return this->name;
}
string City::getCountry() {
	return this->country;
}
int City::getPopulation() {
	return this->population;
}