#include "pch.h"
#include <iostream>
#include "Node.h"


// Default Constructor
Node::Node() {}

// Special Constructor 
Node::Node(int index, bool visited, unsigned int tentativeCost, Node* predecessor){}

// Special Destructor
Node::~Node() {
	//delete predecessor;
}

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
	this->tentativeCost = tentativeCost;
}

void Node::setPredecessor(vector<Node*> predecessor) {
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

vector<Node*> Node::getPredecessor() {
	return this->predecessor;
}

vector<Node*> Node::getNeighbours() {
	return this->neighbours;
}


void Node::update_tentativeCost(unsigned int tentativeCost, Node* predecessor) {
	this->tentativeCost = predecessor->get_tentativeCost() + tentativeCost;			
}

void Node::addPredecessor(Node* predecessor) {
	this->predecessor.push_back(predecessor);
}

/*--------------------------------------------------------------
						Operators
----------------------------------------------------------------*/
// Allocation
Node& Node::operator=(const Node& n) {
	if (this != &n) {
		index = n.index;
		visited = n.visited;
		tentativeCost = n.tentativeCost;
		//predecessor = new Node();						// deep copy
		predecessor = n.predecessor;
	}
	return *this;
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
