#include "pch.h"
#include <iostream>
#include "Map.h"			
#include <string>			
using namespace::std;

int main()
{

	// adjacent matrix representing travel times	// K  B  R  S  F  M  F
	unsigned int network_time[maxCitys][maxCitys] = { {0, 2, 0, 0, 2, 0, 0},	//K
													  {2, 0, 1, 0, 3, 0, 0},	//B
													  {0, 1, 0, 1, 0, 5, 8},	//R
													  {0, 0, 1, 0, 0, 0, 0},	//S
													  {2, 3, 0, 0, 0, 10, 4},	//F
													  {0, 0, 5, 0, 10, 0, 2},	//M
													  {0, 0, 8, 0, 4, 2, 0} };	//F

	// adjacent matrix representing travel distances	// K  B  R  S  F  M  F
	unsigned int network_distance[maxCitys][maxCitys] = { {0, 3, 0, 0, 1, 0, 0},	//K
														  {3, 0, 2, 0, 5, 0, 0},	//B
														  {0, 2, 0, 1, 0, 7, 9},	//R
														  {0, 0, 1, 0, 0, 0, 0},	//S
														  {1, 5, 0, 0, 0, 6, 4},	//F
														  {0, 0, 7, 0, 6, 0, 3},	//M
														  {0, 0, 9, 0, 4, 3, 0} };	//F
	// Generating Map object
	Map map_time = Map();
	Map map_dist = Map();

	// Generating City* List for testing purpose
	for (int i = 0; i < maxCitys; i++) {
		City* c = new City();			// pointer on new City object
		c->setName(citys[i]);			// setting name of new City object
		map_time.listCitys[i] = c;
		map_dist.listCitys[i] = c;
	}

	// Initializing network variable of map
	for (int i = 0; i < maxCitys; i++) {
		for (int j = 0; j < maxCitys; j++) {
			map_time.network[i][j] = network_time[i][j];
			map_dist.network[i][j] = network_distance[i][j];
		}
	}

	// Declaring Map types
	map_dist.mapType = Map::type::distance;
	map_time.mapType = Map::type::time;

	//map_dist.searchBestWay(map_dist.listCitys[0], map_dist.listCitys[4]);
	map_time.searchBestWay(map_dist.listCitys[0], map_dist.listCitys[5]);

}

