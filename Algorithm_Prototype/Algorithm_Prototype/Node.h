#ifndef _NODE_
#define _NODE_

#include "Network.h"
#include <vector>

class Node
{
private:
	unsigned int index;
	bool visited;
	bool member_pq = false;							// becomes true when inserted into priority queue (pq)
	unsigned int tentativeCost;
	Node* predecessor = new Node();
	vector<Node*> neighbours;

public:
	// Default Constructor
	Node();

	// Special Constructor 
	Node(int index, bool visited, unsigned int tentativeCost, Node* predecessor);

	/*--------------------------------------------------------------
							Methods
	----------------------------------------------------------------*/
	// Setter
	void setIndex(int index);
	void setVisited(bool visited);
	void setMemberPQ(bool member_pq);
	void set_tentativeCost(unsigned int tentativeCost);
	void setPredecessor(Node* predecessor);
	void setNeighbour(Node* neighbour);
	

	// Getter
	int getIndex();
	bool getVisited();
	bool getMemberPQ();
	unsigned int get_tentativeCost();
	Node* getPredecessor();
	vector<Node*> getNeighbours();

	

	/*--------------------------------------------------------------
							Operators
	----------------------------------------------------------------*/
	// Allocation
	void operator=(const Node& n);

	// Equality
	bool operator==(const Node& n);

	// Greater
	bool operator>(const Node& n);

	// Less 
	bool operator<(const Node& n);
};
#endif
