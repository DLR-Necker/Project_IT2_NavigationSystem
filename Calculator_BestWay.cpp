#include "pch.h"
#include "Calculator_BestWay.h"

// Default Constructor
Calculator_BestWay::Calculator_BestWay(){}

// Special Constructor
Calculator_BestWay::Calculator_BestWay(Map* map):Way_Calculator(map) {}

// Default Deconstructor
Calculator_BestWay::~Calculator_BestWay() {}


/*----------------------------------------------------------------------
							Methods
-----------------------------------------------------------------------*/


vector<Path*> Calculator_BestWay::findWay(City * start, City * end) 
{
	/*** Initialization of Dijkstra ***/
	initialize(start, end);
	
	Node* currentNode = nodes[start_index];
	pq.push(currentNode);
	/*
	1  Funktion Dijkstra(Graph, Startknoten) :
		2      initialisiere(Graph, Startknoten, abstand[], vorgänger[], Q)
		3      solange Q nicht leer :                       // Der eigentliche Algorithmus
	4          u : = Knoten in Q mit kleinstem Wert in abstand[]
		5          entferne u aus Q                                // für u ist der kürzeste Weg nun bestimmt
		6          für jeden Nachbarn v von u :
	7              falls v in Q :                            // falls noch nicht berechnet
	8                 distanz_update(u, v, abstand[], vorgänger[])   // prüfe Abstand vom Startknoten zu v 
		9      return vorgänger[]
		Die Initialisierung setzt die Abstände auf unendlich und die Vorgänger als unbekannt.Nur der Startknoten hat die Distanz 0. Die Menge Q enthält die Knoten, zu denen noch kein kürzester Weg gefunden wurde.

		1  Methode initialisiere(Graph, Startknoten, abstand[], vorgänger[], Q) :
		2      für jeden Knoten v in Graph :
	3          abstand[v] : = unendlich
		4          vorgänger[v] : = null
		5      abstand[Startknoten] : = 0
		6      Q : = Die Menge aller Knoten in Graph
		Der Abstand vom Startknoten zum Knoten v verkürzt sich dann, wenn der Weg zu v über u kürzer als der bisher bekannte Weg ist.Entsprechend wird u zum Vorgänger von v auf dem kürzesten Weg.

		1  Methode distanz_update(u, v, abstand[], vorgänger[]) :
		2      alternativ : = abstand[u] + abstand_zwischen(u, v)   // Weglänge vom Startknoten nach v über u
		3      falls alternativ < abstand[v] :
		4          abstand[v] : = alternativ
		5          vorgänger[v] : = u
		Falls man nur am kürzesten Weg zwischen zwei Knoten interessiert ist, kann man den Algorithmus nach Zeile 5 der Dijkstra - Funktion abbrechen lassen, falls u = Zielknoten ist.

		Den kürzesten Weg zu einem Zielknoten kann man nun durch Iteration über die vorgänger ermitteln :

	1  Funktion erstelleKürzestenPfad(Zielknoten, vorgänger[])
		2   Weg[] : = [Zielknoten]
		3   u : = Zielknoten
		4   solange vorgänger[u] nicht null :   // Der Vorgänger des Startknotens ist null
	5       u : = vorgänger[u]
		6       füge u am Anfang von Weg[] ein
		7   return Weg[]
	
	*/
	



	return vector<Path*>();
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
			node->set_tentativeCost(-1);
		}
		node->setIndex(i);						// index needed to maintain assignment when used in priority queue
		node->setVisited(false);
		node->setPredecessor(NULL);				// NULL: no predecesor at the moment; only set when shortest way found from start to current node via predecessor
		nodes[i] = node;
	}
}


