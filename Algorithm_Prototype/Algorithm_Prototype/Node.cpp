#include "pch.h"
#include "Node.h"

// Default Constructor
Node::Node() {}

// Special Constructor 
Node::Node(int index, bool visited, unsigned int tentativeCost, Node* predecessor){}


/*--------------------------------------------------------------
							Methods
----------------------------------------------------------------*/
// Setter
void Node::setIndex(int index) {
	this->index = index;
}

void Node::setVisited(bool visited) {
	this->visited = visited;
}

void Node::setMemberPQ(bool member_pq) {
	this->member_pq = member_pq;
}

void Node::set_tentativeCost(unsigned int tentativeCost) {
	this->tentativeCost += tentativeCost;
}

void Node::setPredecessor(Node* predecessor) {
	this->predecessor = predecessor;
}

void Node::setNeighbour(Node* neighbour) {
	this->neighbours.push_back(neighbour);
}

// Getter
int Node::getIndex() {
	return this->index;
}

bool Node::getVisited(){
	return this->visited;
}

bool Node::getMemberPQ() {
	return this->member_pq;
}

unsigned int Node::get_tentativeCost() {
	return this->tentativeCost;
}

Node* Node::getPredecessor() {
	return this->predecessor;
}

std::vector<Node*> Node::getNeighbours() {
	return this->neighbours;
}


/*--------------------------------------------------------------
						Operators
----------------------------------------------------------------*/
// Allocation
void Node::operator=(const Node& n) {
	index = n.index;
	visited = n.visited;
	tentativeCost = n.tentativeCost;
	predecessor = n.predecessor;
}
// Equality
bool Node::operator==(const Node& n) {
	if (tentativeCost == n.tentativeCost) {
		return true;
	}
	else { return false; }
}

// Greater
bool Node::operator>(const Node& n){
	if (tentativeCost > n.tentativeCost) {
		return true;
	}
	else { return false; }
}

// Less 
bool Node::operator<(const Node& n) {
	if (tentativeCost < n.tentativeCost) {
		return true;
	}
	else { return false; }
}
