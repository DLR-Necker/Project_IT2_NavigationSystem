#include "pch.h"
#include "Calculator_BestWay.h"

// Default Constructor
Calculator_BestWay::Calculator_BestWay(){}

// Special Constructor
Calculator_BestWay::Calculator_BestWay(Map* map):Way_Calculator(map) {}

// Default Deconstructor
Calculator_BestWay::~Calculator_BestWay() {
	delete nodes[maxCitys];
}


/*----------------------------------------------------------------------
							Methods
-----------------------------------------------------------------------*/


void Calculator_BestWay::findWay(City * start, City * end) 
{
	/*** Initialization of Dijkstra ***/
	initialize(start, end);

	Node* currentNode = nodes[start_index];										// Initialization of start node
	pq.push(currentNode);

	/*** Start of Dijkstra ***/

	while ( currentNode->getIndex() != this->end_index ) {						// if current node is set to end point, its shortest distance from start is known
		currentNode = pq.top();													// updates current node to "cheapest" element in pq 
		if (currentNode->getIndex() == this->end_index) {
			break;																// to prevent the algorithm to continue unnecessarily 
		}
		nodes[currentNode->getIndex()]->setVisited(true);						// marks current node as visited
					
		pq.pop();																// deletes "cheapest" element in pq 
		currentNode->setMemberPQ(false);										// sets membership in pq to false -> deleted


		get_unvisitedNeighbours(currentNode);									// searching all unvisited neighbours and inserting them into neighbours vector of current node

		for (unsigned int i = 0; i < currentNode->getNeighbours().size(); i++) {
			Node* neighbour = currentNode->getNeighbours()[i];
			if ((neighbour->getMemberPQ()) 
				&& (check_ShorterDistance(currentNode, neighbour))) {						// retruns true if neighbour is element of pq && tentative cost for neighbour is less via current node 


				update_NodeCost(currentNode, neighbour);
				pq.push(neighbour);
			}
		
		}
	}

	/*** Creating a Path object from the Results stored in the nodes array and printing it to the console
	 nodes[] now contains nodes with all relevant information needed: tentative costs, predecessor 
	*/
	generatePath(end_index);
	
}

void  Calculator_BestWay::initialize(City* start, City* end) {
	// Creating the start and end indices
	this->start_index = cityToIndex(start);
	this->end_index = cityToIndex(end);

	// Initialize knots before algorithm starts; set tentative cost of all knots except start to max unsigned int value (4,294,967,295) 
	for (int i = 0; i < maxCitys; i++) {
		Node* node = new Node();

		if (i == start_index) {
			node->set_tentativeCost(0);	
		}
		else {
			node->set_tentativeCost(-1);		// Max uint value
		}
		
		node->setIndex(i);						// index needed to maintain assignment when used in priority queue
		node->setVisited(false);
		node->setMemberPQ(false);
		nodes[i] = node;
	}
}

void Calculator_BestWay::get_unvisitedNeighbours(Node* currentNode) {
	for (int i = 0; i < maxCitys; i++) {
			if ((map->network[currentNode->getIndex()][i] > 0) && !(nodes[i]->getVisited())) {											// checks network row if entry is greater than 0 -> neighbour of current node and if neighbour has already been visited 		
				currentNode->setNeighbour(nodes[i]);
				nodes[i]->setMemberPQ(true);
			}
	}
}

	
bool Calculator_BestWay::check_ShorterDistance(Node* currentNode, Node* neighbour) {
	if ((neighbour->get_tentativeCost()) > (currentNode->get_tentativeCost())															// checks if tentative cost is less via current node
											+ (map->network[currentNode->getIndex()][neighbour->getIndex()])) {							// and deletes current predecessor from the vector
		if (!(neighbour->getPredecessor().empty()))	{																					// only delete if predecessor element is present
			vector<Node*> p = neighbour->getPredecessor();
			p.clear();
			neighbour->setPredecessor(p);

		}
		return true;
	}
	else if ((neighbour->get_tentativeCost()) == (currentNode->get_tentativeCost())														// checks if tentative cost is equal via current node
												+ (map->network[currentNode->getIndex()][neighbour->getIndex()])) {						// in this case, the current node is also pushed to predecessor vector
		return true;
	}															
		else { return false; }
}

void Calculator_BestWay::update_NodeCost(Node* currentNode, Node* neighbour) {
																								
	neighbour->update_tentativeCost(this->map->network[currentNode->getIndex()][neighbour->getIndex()], currentNode );					// update of tentative cost
	neighbour->addPredecessor(currentNode);
	
}

void Calculator_BestWay::generatePath(int iter) {
	Path result = currentPath;																				// Generate Path object
	Path current = currentPath;
	int startIter = iter;

	result.setTotalCost(nodes[end_index]->get_tentativeCost());												// set its total cost to the value stored in end node -> does not change for different cheapest ways

	result.add_CitytoPath_BW(map->listCitys[iter]);															// adding City on position iter to result citysOnPath variable
	currentPath = result;

	if (iter == start_index) {
		waysFound.push_back(result);																		// adding result path to the waysFound vector 
		return;
	}

	for (unsigned int i = 0; i < nodes[iter]->getPredecessor().size(); i++) {								// checking how many predecessors of the same cost are present
		Node* predecessor = nodes[iter]->getPredecessor()[i];

		iter = predecessor->getIndex();																		// updating the iterator iter to the index of one predecessor of current
		generatePath(iter);																					// and recursively call generatePath() with predecessor index
	
		iter = startIter;																					// resetting the iter variable after recursion successful
		currentPath = current;																				// resetting currentPath after recursion successful
	}
}