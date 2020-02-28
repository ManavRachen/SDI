#pragma once

template<typename Type>
struct Node
{
public:
	~Node() { next = nullptr; }

	bool operator == (Type x) { return (data == x); }

	Node* operator + (int) { return next; }

	Node* operator ++ (int) { return next; }
	Node* operator -- (int) { throw(std::logic_error(NULL)); } // Has to be defined for template purposes

	Node* next;
	Type data;
};


template<typename Type>
struct DoubleNode
{
public:
	~DoubleNode() { right = nullptr; left = nullptr; }
	DoubleNode* operator ++ (int) { return right; }
	DoubleNode* operator -- (int) { return left; }

	DoubleNode* left;
	DoubleNode* right;
	Type data;
};
