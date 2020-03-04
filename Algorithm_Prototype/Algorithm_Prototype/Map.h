#pragma once

#include <vector>
#include <array>
#include "City.h"
#include "Network.h"
#include "Vertex.h"
using namespace::std;


class Map
{
private:
	// enum type { none, distance, time };						// wird wahrscheinlich nicht benötigt; Map sollte beide Netzwerke initialisieren, um zur Laufzeit damit arbeiten zu könnnen
	// type mapType; 

	array<Vertex, maxCitys> network;							// array of vertices representing the map 

public:
	// Attributes
	array<City*, maxCitys> listCitys;							// use of array<T,n> because usual Arrays can not be a return value -> needed for Constructor 

	// Default Constructor
	Map();

	//Special Constructor
	Map(/*type mapType,*/ array<City*, maxCitys> listCitys, array<Vertex, maxCitys> network);

	// Default Deconstructor
	~Map();

	// !!!!!!!! METHODS NEED TO BE MODIFIED!!!!!//

	/*----------------------------------------------------------------------
							Methods
	-----------------------------------------------------------------------*/
	/*
	This method generates a network based on the Map information given (see "Network.h") by creating Vertices holding a key variable for both distance and time, as well as a structure containing neighbours and corresponding costs.
	@param
	@return void
	*/
	void generate_Network();

	/*
	This method determines the way with the least amount of costs - either distance- or time-wise - from a starting point (City) to an end point (City) based on the Dijkstra-Algorithm.
	@param	start		starting point
			end			end point
	@return bestWay		result of the Dijksta-Algorithm
	*/
	vector<Vertex> searchBestWay(Vertex start, Vertex end);

	/*
	This method determines every possible way from a starting point (City) to an end point (City) excluding loops.
	@param	start		starting point
			end			end point
	@return everyWay	result of the search
	*/
	vector<City*> searchEveryWay(City* start, City* end);


};
