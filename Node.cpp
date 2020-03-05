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

void Node::set_tentativeCost(unsigned int tentativeCost) {
	this->tentativeCost = tentativeCost;
}

void Node::setPredecessor(Node* predecessor) {
	this->predecessor = predecessor;
}

// Getter
int Node::getIndex() {
	return this->index;
}

bool Node::getVisited(){
	return this->visited;
}

unsigned int Node::get_tentativeCost() {
	return this->tentativeCost;
}

Node* Node::getPredecessor() {
	return this->predecessor;
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
