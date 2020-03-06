#include "pch.h"
#include "Calculator_BestWay.h"

// Default Constructor
Calculator_BestWay::Calculator_BestWay(){}

// Special Constructor
Calculator_BestWay::Calculator_BestWay(Map* map):Way_Calculator(map) {}

// Default Deconstructor
Calculator_BestWay::~Calculator_BestWay() {
	// Delete nodes[] --> Pointer Array	
}


/*----------------------------------------------------------------------
							Methods
-----------------------------------------------------------------------*/


Path* Calculator_BestWay::findWay(City * start, City * end) 
{
	/*** Initialization of Dijkstra ***/
	initialize(start, end);

	Node* currentNode = nodes[this->start_index];								// Initialization of start node
	pq.push(currentNode);


	while ( currentNode->getIndex() != this->end_index ) {						// if current node is set to end point, its shortest distance from start is known
		currentNode = pq.top();													// updates current node to "cheapest" element in pq 
		nodes[currentNode->getIndex()]->setVisited(true);						// marks current node as visited
					
		pq.pop();																// deletes "cheapest" element in pq

		get_unvisitedNeighbours(currentNode);									// searching all unvisited neighbours and inserting them into neighbours vector of current node

		for (int i = 0; i < currentNode->getNeighbours().size(); i++) {
			if (currentNode->getNeighbours()[i]->getMemberPQ() 
				&& check_ShorterDistance(currentNode, i)) {						// retruns true if neighbour is element of pq && tentative cost for neighbour is less via current node 

				update_NodeCost(currentNode, i);

			}

			else {
				update_NodeCost(currentNode, i);
			}

			currentNode->getNeighbours()[i]->setMemberPQ(true);
			pq.push(currentNode->getNeighbours()[i]);																	// inserting neighbour in pq
			
		}
	}

	/*

		1  Methode distanz_update(u, v, abstand[], vorg�nger[]) :
		2      alternativ : = abstand[u] + abstand_zwischen(u, v)   // Wegl�nge vom Startknoten nach v �ber u
		3      falls alternativ < abstand[v] :
		4          abstand[v] : = alternativ
		5          vorg�nger[v] : = u
		Falls man nur am k�rzesten Weg zwischen zwei Knoten interessiert ist, kann man den Algorithmus nach Zeile 5 der Dijkstra - Funktion abbrechen lassen, falls u = Zielknoten ist.

		Den k�rzesten Weg zu einem Zielknoten kann man nun durch Iteration �ber die vorg�nger ermitteln :

	1  Funktion erstelleK�rzestenPfad(Zielknoten, vorg�nger[])
		2   Weg[] : = [Zielknoten]
		3   u : = Zielknoten
		4   solange vorg�nger[u] nicht null :   // Der Vorg�nger des Startknotens ist null
	5       u : = vorg�nger[u]
		6       f�ge u am Anfang von Weg[] ein
		7   return Weg[]
	
	*/
	



	return new Path();
}

void  Calculator_BestWay::initialize(City* start, City* end) {
	// Creating the start and end indices
	this->start_index = cityToIndex(start);
	this->end_index = cityToIndex(end);

	// Initialize knots before algorithm starts; set tentative cost of all knots except start to max unsigned int value (4,294,967,295) 
	for (int i = 0; i < maxCitys; i++) {
		Node* node = new Node();

		if (i = this->start_index) {
			node->set_tentativeCost(0);	
		}
		else {
			node->set_tentativeCost(-1);		// Max uint value
		}
		node->setIndex(i);						// index needed to maintain assignment when used in priority queue
		node->setVisited(false);
		node->setMemberPQ(false);
		node->setPredecessor(NULL);				// NULL: no predecesor at the moment; only set when shortest way found from start to current node via predecessor
		nodes[i] = node;
	}
}

void Calculator_BestWay::get_unvisitedNeighbours(Node* currentNode) {
	for (int i = 0; i < maxCitys; i++) {
			if (this->map[currentNode->getIndex][i] > 0 && !nodes[i]->getVisited) {											// checks network row if entry is greater than 0 -> neighbour of current node and if neighbour has already been visited 		
				currentNode->setNeighbour(nodes[i]);
			}
	}
}

	
bool Calculator_BestWay::check_ShorterDistance(Node* currentNode, int i) {
	if (currentNode->getNeighbours()[i]->get_tentativeCost > currentNode->getNeighbours()[i]->get_tentativeCost()		// checks if tentative cost is less via current node
															+ this->map->network[currentNode->getIndex()][i]) {
			return true;
	}
		else { return false; }
}

void Calculator_BestWay::update_NodeCost(Node* currentNode, int i) {

	currentNode->getNeighbours()[i]->set_tentativeCost(this->map->network[currentNode->getIndex()][i]);			// update of tentative cost
	currentNode->getNeighbours()[i]->setPredecessor(currentNode);												// update of predecessor
}