#pragma once

class Comparator_greater {
public:
	template<typename Node>
	bool operator()(Node *n1, Node *n2) {
		return (*n1) > (*n2);
	}
};