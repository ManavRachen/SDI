#pragma once

struct Node
{
public:
	~Node() { next = nullptr; }

	Node* next;
	int data;
};
