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

	Node* currentNode = nodes[this->start_index];								// Initialization of start node
	pq.push(currentNode);

	/*** Start of Dijkstra ***/
	cout << "Beginne mit Dijkstra" << endl;

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

	cout << "Pfad gefunden" << endl;
	
	/*** Creating a Path object from the Results stored in the nodes array and printing it to the console
	 nodes[] now contains nodes with all relevant information needed: tentative costs, predecessor 
	*/
	generatePath(nodes);
	
}

void  Calculator_BestWay::initialize(City* start, City* end) {
	// Creating the start and end indices
	this->start_index = cityToIndex(start);
	this->end_index = cityToIndex(end);

	// Initialize knots before algorithm starts; set tentative cost of all knots except start to max unsigned int value (4,294,967,295) 
	cout << "Initializiere Dijekstra..." << endl;
	for (int i = 0; i < maxCitys; i++) {
		Node* node = new Node();

		if (i == start_index) {
			//cout << "Start gefunden" << endl;
			node->set_tentativeCost(0);	
		}
		else {
			node->set_tentativeCost(-1);		// Max uint value
		}
		//cout << "Set index" << endl;
		node->setIndex(i);						// index needed to maintain assignment when used in priority queue
		node->setVisited(false);
		node->setMemberPQ(false);
		node->setPredecessor(NULL);				// NULL: no predecesor at the moment; only set when shortest way found from start to current node via predecessor
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
	if ((neighbour->get_tentativeCost()) > (currentNode->get_tentativeCost())					// checks if tentative cost is less via current node
															+ (map->network[currentNode->getIndex()][neighbour->getIndex()])) {
			return true;
	}
		else { return false; }
}

void Calculator_BestWay::update_NodeCost(Node* currentNode, Node* neighbour) {

	neighbour->setPredecessor(currentNode);																							// update of predecessor must stand before set_tentativeCost!!
	neighbour->update_tentativeCost(map->network[currentNode->getIndex()][neighbour->getIndex()]);									// update of tentative cost
	
}

void Calculator_BestWay::generatePath(Node* nodes[]) {
	cout << "Generiere nun den Pfad " << endl;
	Path result = Path();																					// Generate Path object 

	result.setTotalCost(nodes[end_index]->get_tentativeCost());												// set its total cost to the value stored in end node
	cout << "Gesamtkosten: " << result.getTotalCost() << endl;

	int iter = end_index;																					// create iterator and set it to end_index

	while (nodes[iter]->getPredecessor() != NULL) {															// Iteration over nodes[] array; NULL: start node found (no predecessor)
		Node* current = nodes[iter];
		Node* predecessor = nodes[iter]->getPredecessor();
		cout << "Fuege Node hinzu: " << map->listCitys[current->getIndex()]->getName() << endl;
		result.add_CitytoPath_BW(map->listCitys[current->getIndex()]);											// uses index of current node to retrieve pointer to city from listCitys 
		iter = predecessor->getIndex();
		cout << "Vorgaenger Node: " << predecessor->getIndex() << endl;
	}

	result.add_CitytoPath_BW(map->listCitys[nodes[start_index]->getIndex()]);
	cout << "Fuege Start node hinzu: " << map->listCitys[nodes[start_index]->getIndex()]->getName() << endl;
																			
	waysFound.push_back(result);																			// add result path to vector waysFound
}