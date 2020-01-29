#pragma once

template<typename Type>
struct NodeT
{
public:
	~NodeT() { next = nullptr; }
	NodeT* operator ++ (int) { return next; }
	Node* operator -- (int) { throw(std::logic_error(NULL)); } // Has to be defined for template purposes

	NodeT* next;
	Type data;
};
