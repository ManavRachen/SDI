#pragma once

struct DoubleNode
{

	~DoubleNode() { right = nullptr; left = nullptr; }
	DoubleNode* operator ++ (int) { return right; }
	DoubleNode* operator -- (int) { return left; }
	int operator < (DoubleNode rhs) { return (data < rhs.data); }
	// (*a < *b) //

	DoubleNode* left = nullptr;
	DoubleNode* right = nullptr;
	int data;
};