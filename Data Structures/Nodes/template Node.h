#pragma once

template<typename Type>
struct NodeT
{
public:
	~NodeT() { next = nullptr; }
	NodeT* operator ++ (int) { return next; }

	NodeT* next;
	Type data;
};
