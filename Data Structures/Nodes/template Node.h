#pragma once

template<typename Type>
struct NodeT
{
public:
	~NodeT() { next = nullptr; }

	NodeT* next;
	Type data;
};
