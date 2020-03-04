#include "pch.h"
#include <iostream>
#include "Map.h"
using namespace::std;

int main()
{

	// adjacent matrix representing travel times
	unsigned int network_time[maxCitys][maxCitys] = { {0, 2, 0, 2, 0, 0},
													  {2, 0, 1, 3, 0, 0},
													  {0, 1, 0, 0, 5, 8},
													  {2, 3, 0, 0, 10, 4},
													  {0, 0, 5, 10, 0, 2},
													  {0, 0, 8, 4, 2, 0} };

	// adjacent matrix representing travel distances
	unsigned int network_distance[maxCitys][maxCitys] = { {0, 3, 0, 1, 0, 0},
														  {3, 0, 2, 5, 0, 0},
														  {0, 2, 0, 0, 7, 9},
														  {1, 5, 0, 0, 6, 4},
														  {0, 0, 7, 6, 0, 3},
														  {0, 0, 9, 4, 3, 0} };
	// Generatin Map object
	Map map_time = Map();
	Map map_dist = Map();

	// Generating City* List for testing purpose
	for (int i = 0; i < maxCitys; i++) {
		City* c = new City();			// pointer on new City object
		c->setName = citys[i];			// setting name of new City object
		map_time.listCitys[i] = c;
		map_dist.listCitys[i] = c;
	}
}


