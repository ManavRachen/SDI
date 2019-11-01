#pragma once
#include <iostream>
#include <string>


template<typename Type>
class LinkedList
{
public:

	//Operators------------------------------------------------------//
	
	//Constructor
	LinkedList() { 
		head = nullptr; 
	}

	//Destructor
	~LinkedList() {
		NodeT<Type>* head = this->head;
		NodeT<Type>* next;

		while (head) {
			next = head->next;
			delete head;
			head = next;
		}
	}

	//Overloads the [] operator ~ calls at()
	NodeT<Type>* operator[](unsigned int pos) {
		return at(pos);
	} 
	
	//Insertion & Deletion-------------------------------------------//

	//Add node at end of list
	void append(Type data) {
		NodeT<Type>* node = new Node<Type>();
		node->data = data;

		if (!head) { head = node; }
		else { back()->next = node; }
	}

	//Add node at start of list
	void prepend(Type data) {
		NodeT<Type>* node = new NodeT<Type>();
		node->data = data;

		node->next = head;
		head = node;
	}

	//Add node at index x
	void insert(Type data, unsigned int pos) {

		if (!pos) { prepend(data); return; } //Prepend

		NodeT<Type>* node = new NodeT<Type>();
		node->data = data;

		if (!head) { head = node; return; } //Empty

		OutOfBounds(pos - 1);

		NodeT<Type>* previous = at(pos);
		node->next = previous->next;
		previous->next = node;

	}

	//Delete node at end of list
	void popBack() {
		if (!head->next) { popFront(); return; }
		OutOfBounds(size() - 1);

		NodeT<Type>* previous = at(size() - 2);
		delete previous->next;
		previous->next = nullptr;
	}

	//Delete node at start of list
	void popFront() {
		if (!head) { OutOfBounds(0); }

		NodeT<Type>* toDelete = head;
		head = head->next;
		delete toDelete;
	}

	//Delete node at index x
	void del(unsigned int pos) {

		if (!pos) { popFront(); return; } //Remove head

		OutOfBounds(pos);

		NodeT<Type>* previous = at(pos - 1);
		NodeT<Type>* current = previous->next;

		previous->next = current->next;
		delete current;

	}
	
	//Index and Searching--------------------------------------------//

	//Return final node
	NodeT<Type>* back() {
		return at(size() - 1);
	}

	//Return first node
	NodeT<Type>* front() {
		return head;
	}

	//Return node at index x
	NodeT<Type>* at(unsigned int pos) {
		OutOfBounds(pos);

		NodeT<Type>* node = this->head;

		if (!node) { return head; };

		for (int count = 0; node->next && (count != pos); ++count) {
			node = node->next;
		}

		return node;
	}

	//Returns size of the list
	unsigned int size() {
		NodeT<Type>* head = this->head;
		int count = 0;

		while (head) {
			head = head->next;
			count++;
		}

		return count;
	}

	//User Features--------------------------------------------------//

	//Add x amount of nodes to end of list
	void populate(unsigned int size) {
		for (int i = 0; i <= size - 1; ++i) {
			Type a;
			prepend(a);
		}
	}

	//Prints the list
	void print() {
		NodeT<Type>* node = head;
		int count = 1;

		while (node) {
			std::cout << count << ": " << node->data << std::endl;
			node = node->next;
			count++;
		}
		std::cout << std::endl;
	}


	
private:	
	NodeT<Type>* head;

	//Checks if input is in range
	void OutOfBounds(unsigned int pos) {
		if (pos < size()) {
			return;
		}
		throw(std::out_of_range(NULL));
	}
};
