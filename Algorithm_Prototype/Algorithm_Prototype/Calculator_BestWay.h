#ifndef _CalcBW_
#define _CalcBW_



#include <queue>
#include <iostream>
#include "Way_Calculator.h"
#include "Node.h"
using namespace::std;


class Calculator_BestWay :
	public Way_Calculator
{
protected:
	priority_queue<Node*, vector<Node*>, less<Node*> > pq;								// Priority Queue needed for Dijekstra algorithm
	Node* nodes[maxCitys];										// Collector of all knots with their corresponding data



public:
	// Default Constructor
	Calculator_BestWay();

	// Special Constructor 
	Calculator_BestWay(Map* map);
	
	// Default Deconstructor
	~Calculator_BestWay(// über nodes Array iterieren und Knotenobjekte löschen
	);


	/*----------------------------------------------------------------------
								Methods
	-----------------------------------------------------------------------*/

	/*
		This is the overwritten virtual method of Way_Calculator which calculates the fastest way within the network from start City to end City. 
		It is based on the Dijkstra algorithm.
		@param	start					start City
				end						end City
		@return bestWay					vector of best ways found
	*/
	void findWay(City* start, City* end);

	/*
		This method initialize the Dijkstra algorithm
		@param	start					start City
				end						end City
		@return bestWay					vector of best ways found
	*/
	void initialize(City * start, City * end);

	/*
	This method searches all unvisited neighbours of a Node Object
	@param	currentNode		pointer on current node
	@return void
	*/
	void get_unvisitedNeighbours(Node* currentNode);

	/*
	This method checks if a neighbour object of the current node can be reached faster via the latter.
	@param	currentNode		pointer on current node
	@return void
	*/
	bool check_ShorterDistance(Node* currentNode, Node* neighbour);

	/*
	This method updates cost and predecessor of a neighbour
	@param	currentNode		pointer on current node
	@return void
	*/
	void update_NodeCost(Node* currentNode, Node* neighbour);

	void generatePath(Node* nodes[]);
};

#endif 

