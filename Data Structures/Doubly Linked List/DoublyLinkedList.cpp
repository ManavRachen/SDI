#include "pch.h"
#include "../../Console/pch.h"
#include <iostream>
#include <ctime>

//Operators
DoublyLinkedList::DoublyLinkedList() {
	head = nullptr;
	tail = nullptr;
}
DoublyLinkedList::~DoublyLinkedList() {
	DoubleNode* head = this->head;
	DoubleNode* next;

	while (head) {
		next = head->right;
		delete head;
		head = next;
	}
}
DoubleNode* DoublyLinkedList::operator[](int pos) {
	return at(pos);
}


//Public Functions
void DoublyLinkedList::append(int data) {
	DoubleNode* node = new DoubleNode();
	node->data = data;

	node->left = tail;
	if (tail) { tail->right = node; }
	else { head = node; }
	tail = node;
}
void DoublyLinkedList::prepend(int data) {
	DoubleNode* node = new DoubleNode();
	node->data = data;

	node->right = head;
	if (head) { head->left = node; }
	else { tail = node; }
	head = node;
}
void DoublyLinkedList::insert(int data, int pos) {

	if (!pos) { prepend(data); return; } //Prepend
	if (pos == size()) { append(data); return; } //Append

	DoubleNode* node = new DoubleNode();
	node->data = data;

	if (!head) { head = node; tail = node; return; } //Empty

	OutOfBounds(pos - 1);

	DoubleNode* previous = at(pos - 1);
	DoubleNode* after = previous->right;
	node->right = after;
	node->left = previous;
	previous->right = node;
	after->left = node;
}

void DoublyLinkedList::popBack() {
	if (!tail) { OutOfBounds(0); }

	DoubleNode* toDelete = tail;
	DoubleNode* previous = tail->left;
	tail = previous;
	if (previous) { previous->right = nullptr; }
	else { head = nullptr; }
	delete toDelete;
}
void DoublyLinkedList::popFront() {
	if (!head) { OutOfBounds(0); }

	DoubleNode* toDelete = head;
	DoubleNode* next = head->right;
	head = next;
	if (next) { next->left = nullptr; }
	else { tail = nullptr; }
	delete toDelete;
}
void DoublyLinkedList::del(int pos) {

	if (!pos) { popFront(); return; } //Remove head
	if (pos == (size() - 1)) { popBack(); return; } //Remove back

	OutOfBounds(pos);

	DoubleNode* previous = at(pos - 1);
	DoubleNode* current = previous->right;

	previous->right = current->right;
	current->right->left = previous;
	delete current;

}

DoubleNode* DoublyLinkedList::at(int pos) {

	OutOfBounds(pos);

	if (pos >= 0) {
		DoubleNode* node = head;

		//if (!node) { return head; };

		for (int count = 0; node->right && (count != pos); ++count) {
			node = node->right;
		}

		return node;
	}
	else {
		DoubleNode* node = tail;

		//if (!node) { return tail; };

		for (int count = -1; node->left && (count != pos); --count) {
			node = node->left;
		}

		return node;
	}

}
DoubleNode* DoublyLinkedList::front() {
	return head;
}
DoubleNode* DoublyLinkedList::back() {
	return tail;
}

void DoublyLinkedList::populate(unsigned int size) {
	srand((int)std::time(NULL));

	for (unsigned int i = 0; i <= size - 1; ++i) {
		prepend(rand());
	}
}

unsigned int DoublyLinkedList::size() {
	DoubleNode* head = this->head;
	int count = 0;

	while (head) {
		head = head->right;
		count++;
	}

	return count;
}
void DoublyLinkedList::print() {
	DoubleNode* node = head;
	int count = 1;

	while (node) {
		std::cout << count << ": " << node->data << std::endl;
		node = node->right;
		count++;
	}
	std::cout << std::endl;
}

//Sorting

void DoublyLinkedList::sort() {
	this->selectionSort(this);
}

//Private Functions
void DoublyLinkedList::OutOfBounds(int pos) {
	if (pos < 0) { pos = abs(pos) - 1; }

	if ((unsigned)pos < size()) {
		return;
	}
	throw(std::out_of_range(NULL));
}
