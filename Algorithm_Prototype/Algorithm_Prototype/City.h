#ifndef _CITY_
#define _CITY_


#include <string>
using namespace::std;

class City
{
private:
	std::string name;
	std::string country;
	int population;

public:
	// Default Constructor
	City();

	// Special Constructor
	City(std::string name, std::string country, int population);

	// Default Deconstructor
	~City();

	/*----------------------------------------------------------------------
							Methods
	-----------------------------------------------------------------------*/
	/*** Setter ***/
	void setName(std::string name);
	void setCountry(std::string country);
	void setPopulation(int population);

	/*** Getter ***/
	std::string getName();
	std::string getCountry();
	int getPopulation();
};

#endif