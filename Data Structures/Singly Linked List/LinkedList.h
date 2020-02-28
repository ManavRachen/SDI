#pragma once

class LinkedList : SortingAlgorithms< LinkedList, Node>
{
public:
	LinkedList();
	~LinkedList();
	Node* operator[](unsigned int pos); //Overloads the [] operator ~ calls at()

	void append(int data); //Add node at end of list
	void prepend(int data); //Add node at start of list
	void insert(int data, unsigned int pos); //Add node at index x

	void swap(Node* first, Node* second) {

	}

	void popBack(); //Delete node at end of list
	void popFront(); //Delete node at start of list
	void del(unsigned int pos); //Delete node at index x

	Node* at(unsigned int pos); //Return node at index x
	Node* front(); //Return first node
	Node* back(); //Return final node

	void populate(unsigned int size); //Add x amount of random nodes to end of list

	void sort();

	unsigned int size();
	void print();
	
private:	
	Node* head;
	void OutOfBounds(unsigned int pos); //Checks if input is in range
};

void ModifyList(LinkedList* L);
int Input(int upper, int lower);

void MemLeakTest(LinkedList* L);
