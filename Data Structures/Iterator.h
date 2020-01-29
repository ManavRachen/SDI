#pragma once

template<typename NodeType>
class Iterator {

public:
	void operator = (NodeType* node) { current = node; }
	void operator = (Iterator itr) { current = itr.current; }

	NodeType* operator * () { return current; }

	int operator < (NodeType* rhs) { return (current->data < rhs->data); }
	int operator > (NodeType* rhs) { return (current->data > rhs->data); }
	bool operator != (NodeType* rhs) { return (current != rhs); }

	NodeType* operator ++ (int) { current = next(); return current; }
	NodeType* operator -- (int) { current = previous(); return current; }
	void operator + (int rhs) {
		for (int i = 0; i < rhs; i++) {
			current = next();
		}
	}


private:
	
	NodeType* current;

	NodeType* next() {
		if (current) { return (*current)++; }
		throw(std::out_of_range(NULL));
	}

	NodeType* previous() {
		if (current) { return (*current)--; }
		throw(std::out_of_range(NULL));
	}

};