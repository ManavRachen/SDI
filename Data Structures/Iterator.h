#pragma once

template<typename NodeType>
class Iterator {
public:
	void operator = (NodeType* node) { current = node; }
	//NodeType* operator () { return current; }
	int operator < (NodeType* rhs) { return (current->data < rhs->data); }
	int operator > (NodeType* rhs) { return (current->data > rhs->data); }
	void operator ++ (int) { current = next(); }
	void operator + (int rhs) {
		for (int i = 0; i < rhs; i++) {
			current = next();
		}
	}
	NodeType* operator * () {
		return current;
	}

	


private:
	
	NodeType* current;

	NodeType* next() {
		if (current) { return (*current)++; }
		throw(std::out_of_range(NULL));
	}

};