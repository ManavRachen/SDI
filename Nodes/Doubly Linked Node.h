#pragma once

struct DoubleNode
{
	~DoubleNode() { right = nullptr; left = nullptr; }

	DoubleNode* left;
	DoubleNode* right;
	int data;
};
