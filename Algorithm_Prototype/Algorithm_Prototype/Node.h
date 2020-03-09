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
	vector<Node*> neighbours;
	
public:
	// Attributes
	vector<Node*> predecessor;

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
	void setPredecessor(vector<Node*> predecessor);
	void setNeighbour(Node* neighbour);
	

	// Getter
	int getIndex();
	bool getVisited();
	bool getMemberPQ();
	unsigned int get_tentativeCost();
	vector<Node*> getPredecessor();
	vector<Node*> getNeighbours();


	/*
	This method updates the tentative cost of a Node Object
	@param	tentativeCost		(UINT) value to be added
	@return void
	*/
	void update_tentativeCost(unsigned int tentativeCost, Node* predecessor);

	/*
	This method adds a predecessor to the predecessor vector of a Node Object
	@param	predecessor		
	@return void
	*/
	void addPredecessor(Node* predecessor);

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
