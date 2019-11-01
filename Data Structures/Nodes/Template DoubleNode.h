#pragma once

template<typename Type>
struct DoubleNode
{
public:
	~DoubleNode() { right = nullptr; left = nullptr; }

	DoubleNode* left;
	DoubleNode* right;
	Type data;
};