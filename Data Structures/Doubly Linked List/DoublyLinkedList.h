#pragma once

class DoublyLinkedList : SortingAlgorithms< DoublyLinkedList, DoubleNode, int >
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	DoubleNode* operator[](int pos); //Overloads the [] operator ~ calls Search()

	void append(int data); //Add node at end of list
	void prepend(int data); //Add node at start of list
	void insert(int data, int pos); //Add node at index x
	void popBack(); //Delete node at end of list
	void popFront(); //Delete node at start of list
	void del(int pos); //Delete node at index x

	DoubleNode* at(int pos); //Return node at index x
	DoubleNode* front(); //Return first node
	DoubleNode* back(); //Return final node

	void populate(unsigned int size); //Add x amount of random nodes to end of list

	void sort();

	unsigned int size();
	void print();

private:
	DoubleNode* head;
	DoubleNode* tail;
	void OutOfBounds(int pos); //Checks if input is in range
};