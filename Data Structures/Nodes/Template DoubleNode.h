#pragma once

template<typename Type>
struct DoubleNodeT
{
public:
	~DoubleNodeT() { right = nullptr; left = nullptr; }
	DoubleNodeT* operator ++ (int) { return right; }
	DoubleNode* operator -- (int) { return left; }

	DoubleNodeT* left;
	DoubleNodeT* right;
	Type data;
};
