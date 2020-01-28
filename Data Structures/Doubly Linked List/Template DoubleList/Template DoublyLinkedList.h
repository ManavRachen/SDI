#pragma once
#include <iostream>
#include <string>

template<typename Type = int>
class DoublyLinkedListT : SortingAlgorithms< LinkedListT<Type>, NodeT<Type>, Type >
{
public:

	//Operators------------------------------------------------------//

	//Constructor
	DoublyLinkedListT() {
		head = nullptr;
		tail = nullptr;
	}

	//Destructor
	~DoublyLinkedListT() {
		DoubleNodeT<Type>* head = this->head;
		DoubleNodeT<Type>* next;

		while (head) {
			next = head->right;
			delete head;
			head = next;
		}
	}

	//Overloads the [] operator ~ calls at()
	DoubleNodeT<Type>* operator[](int pos) {
		return at(pos);
	}


	//Insertion & Deletion-------------------------------------------//

	//Add node at end of list
	void append(Type data) {
		DoubleNodeT<Type>* node = new DoubleNodeT<Type>();
		node->data = data;

		node->left = tail;
		if (tail) { tail->right = node; }
		else { head = node; }
		tail = node;
	}

	//Add node at start of list
	void prepend(Type data) {
		DoubleNodeT<Type>* node = new DoubleNodeT<Type>();
		node->data = data;

		node->right = head;
		if (head) { head->left = node; }
		else { tail = node; }
		head = node;
	}

	//Add node at index x
	void insert(Type data, int pos) {

		if (!pos) { prepend(data); return; } //Prepend
		if (pos == size()) { append(data); return; } //Append

		DoubleNodeT<Type>* node = new DoubleNodeT<Type>();
		node->data = data;

		if (!head) { head = node; tail = node; return; } //Empty

		OutOfBounds(pos - 1);

		DoubleNodeT<Type>* previous = at(pos - 1);
		DoubleNodeT<Type>* after = previous->right;
		node->right = after;
		node->left = previous;
		previous->right = node;
		after->left = node;

	}

	//Delete node at end of list
	void popBack() {
		if (!tail) { OutOfBounds(0); }

		DoubleNodeT<Type>* toDelete = tail;
		DoubleNodeT<Type>* previous = tail->left;
		tail = previous;
		if (previous) { previous->right = nullptr; }
		else { head = nullptr; }
		delete toDelete;
	}

	//Delete node at start of list
	void popFront() {
		if (!head) { OutOfBounds(0); }

		DoubleNodeT<Type>* toDelete = head;
		DoubleNodeT<Type>* next = head->right;
		head = next;
		if (next) { next->left = nullptr; }
		else { tail = nullptr; }
		delete toDelete;
	}

	//Delete node at index x
	void del(int pos) {

		if (!pos) { popFront(); return; } //Remove head
		if (pos == (size() - 1)) { popBack(); return; } //Remove back

		OutOfBounds(pos);

		DoubleNodeT<Type>* previous = at(pos - 1);
		DoubleNodeT<Type>* current = previous->right;

		previous->right = current->right;
		current->right->left = previous;
		delete current;

	}


	//Index and Searching--------------------------------------------//

	//Return final node
	DoubleNodeT<Type>* back() {
		return tail;
	}

	//Return first node
	DoubleNodeT<Type>* front() {
		return head;
	}

	//Return node at index x
	DoubleNodeT<Type>* at(int pos) {

		OutOfBounds(pos);

		if (pos >= 0) {
			DoubleNodeT<Type>* node = head;

			//if (!node) { return head; };

			for (int count = 0; node->right && (count != pos); ++count) {
				node = node->right;
			}

			return node;
		}
		else {
			DoubleNodeT<Type>* node = tail;

			//if (!node) { return tail; };

			for (int count = -1; node->left && (count != pos); --count) {
				node = node->left;
			}

			return node;
		}

	}

	//Returns size of the list
	unsigned int size() {
		DoubleNodeT<Type>* head = this->head;
		int count = 0;

		while (head) {
			head = head->right;
			count++;
		}

		return count;
	}


	//Sorting

	void sort() {
		this->selectionSort(this);
	}

private:
	DoubleNodeT<Type>* head;
	DoubleNodeT<Type>* tail;

	//Checks if input is in range
	void OutOfBounds(int pos) {
		if (pos < size()) {
			return;
		}
		throw(std::out_of_range(NULL));
	}
};
