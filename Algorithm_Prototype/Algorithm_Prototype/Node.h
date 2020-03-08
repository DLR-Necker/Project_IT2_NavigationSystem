#ifndef _NODE_
#define _NODE_

#include "Network.h"
#include <vector>

class Node
{
private:
	unsigned int index;
	bool visited;							// becomes true when retrieved from priority queue (pq)
	bool member_pq;							// becomes true when inserted into pq
	unsigned int tentativeCost;
	Node* predecessor;
	vector<Node*> neighbours;

public:
	// Default Constructor
	Node();

	// Special Constructor 
	Node(int index, bool visited, unsigned int tentativeCost, Node* predecessor);

	// Special Destructor
	~Node();

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


	/*
	This method updates the tentative cost of a Node Object
	@param	tentativeCost		(UINT) value to be added
	@return void
	*/
	void update_tentativeCost(unsigned int tentativeCost);

	/*--------------------------------------------------------------
							Operators
	----------------------------------------------------------------*/
	// Allocation
	Node& operator=(const Node& n);

	// Equality
	bool operator==(const Node& n);

	// Greater
	bool operator>(const Node& n);

	// Less 
	bool operator<(const Node& n);
};

#endif
