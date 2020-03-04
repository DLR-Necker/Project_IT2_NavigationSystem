#pragma once
#include <string>
using namespace::std;

//City Def:
/*
0: K�ln
1: Berlin
2: Rostock
3: Frankfurt
4: M�nchen
5: Friedrichshafen
*/

const int maxCitys = 6;
string citys[maxCitys] = { "Koeln", "Berlin", "Rostock", "Frankfurt", "Muenchen", "Friedrichshafen" };

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