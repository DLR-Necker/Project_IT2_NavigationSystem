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
		2      initialisiere(Graph, Startknoten, abstand[], vorg�nger[], Q)
		3      solange Q nicht leer :                       // Der eigentliche Algorithmus
	4          u : = Knoten in Q mit kleinstem Wert in abstand[]
		5          entferne u aus Q                                // f�r u ist der k�rzeste Weg nun bestimmt
		6          f�r jeden Nachbarn v von u :
	7              falls v in Q :                            // falls noch nicht berechnet
	8                 distanz_update(u, v, abstand[], vorg�nger[])   // pr�fe Abstand vom Startknoten zu v 
		9      return vorg�nger[]
		Die Initialisierung setzt die Abst�nde auf unendlich und die Vorg�nger als unbekannt.Nur der Startknoten hat die Distanz 0. Die Menge Q enth�lt die Knoten, zu denen noch kein k�rzester Weg gefunden wurde.

		1  Methode initialisiere(Graph, Startknoten, abstand[], vorg�nger[], Q) :
		2      f�r jeden Knoten v in Graph :
	3          abstand[v] : = unendlich
		4          vorg�nger[v] : = null
		5      abstand[Startknoten] : = 0
		6      Q : = Die Menge aller Knoten in Graph
		Der Abstand vom Startknoten zum Knoten v verk�rzt sich dann, wenn der Weg zu v �ber u k�rzer als der bisher bekannte Weg ist.Entsprechend wird u zum Vorg�nger von v auf dem k�rzesten Weg.

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


