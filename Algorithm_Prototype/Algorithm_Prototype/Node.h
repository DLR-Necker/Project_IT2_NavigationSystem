#pragma once
class Node
{
private:
	int index;
	bool visited;
	unsigned int tentativeCost;
	int predecessor;

public:
	// Default Constructor
	Node();

	// Special Constructor 
	Node(int index, bool visited, unsigned int tentativeCost, int predecessor);

	/*--------------------------------------------------------------
							Methods
	----------------------------------------------------------------*/
	// Setter
	void setIndex(int index);
	void setVisited(bool visited);
	void set_tentativeCost(unsigned int tentativeCost);
	void setPredecessor(int predecessor);

	// Getter
	int getIndex();
	bool getVisited();
	unsigned int get_tentativeCost();
	int getPredecessor();

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

