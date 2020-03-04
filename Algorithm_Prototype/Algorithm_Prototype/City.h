#pragma once

#include <string>
#include "pch.h"


using namespace::std;

class City
{
private:
	string name;
	string country;
	int population;

public:
	// Default Constructor
	City();

	// Special Constructor
	City(string name, string country, int population);

	// Default Deconstructor
	~City();

	/*----------------------------------------------------------------------
							Methods
	-----------------------------------------------------------------------*/
	/*** Setter ***/
	void setName(string name);
	void setCountry(string country);
	void setPopulation(int population);

	/*** Getter ***/
	string getName();
	string getCountry();
	int getPopulation();
};

