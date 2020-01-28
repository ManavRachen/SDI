#pragma once

struct DoubleNode
{

	~DoubleNode() { right = nullptr; left = nullptr; }
	DoubleNode* operator ++ (int) { return right; }
	int operator < (DoubleNode rhs) { return (data < rhs.data); }
	// (*a < *b) //

	DoubleNode* left;
	DoubleNode* right;
	int data;
};