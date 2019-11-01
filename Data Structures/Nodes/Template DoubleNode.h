#pragma once

template<typename Type>
struct DoubleNodeT
{
public:
	~DoubleNodeT() { right = nullptr; left = nullptr; }

	DoubleNodeT* left;
	DoubleNodeT* right;
	Type data;
};
