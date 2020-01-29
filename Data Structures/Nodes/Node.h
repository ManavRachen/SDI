#pragma once

class Node
{
public:
	~Node() { next = nullptr; }
	Node* operator ++ (int) { return next; }
	Node* operator -- (int) { throw(std::logic_error(NULL)); } // Has to be defined for template purposes

	Node* next;
	int data;
};
