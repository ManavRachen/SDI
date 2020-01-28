#pragma once

class Node
{
public:
	~Node() { next = nullptr; }
	Node* operator ++ (int) { return next; }

	Node* next;
	int data;
};
