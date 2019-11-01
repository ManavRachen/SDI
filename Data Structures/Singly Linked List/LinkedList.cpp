//#include "stdAfx.h"
//#include "pch.h"
#include <iostream>
#include <ctime>

//Operators
LinkedList::LinkedList() {
	this->head = NULL;
}
LinkedList::~LinkedList() {
	Node* head = this->head;
	Node* next;

	while (head) {
		next = head->next;
		delete head;
		head = next;
	}
}
Node* LinkedList::operator[](unsigned int pos) {
	return at(pos);
}

//Public Functions
void LinkedList::append(int data) {
	Node* node = new Node();
	node->data = data;

	if (!head) { head = node; }
	else { back()->next = node; }
}
void LinkedList::prepend(int data) {
	Node* node = new Node();
	node->data = data;

	node->next = head;
	head = node;
}
void LinkedList::insert(int data, unsigned int pos) {

	if (!pos) { prepend(data); return; } //Prepend
	if (pos == size()) { append(data); return; } //Append

	Node* node = new Node();
	node->data = data;

	if (!head) { head = node; return; } //Empty

	OutOfBounds(pos - 1);

	Node* previous = at(pos);
	node->next = previous->next;
	previous->next = node;

}

void LinkedList::popBack() {
	if (!head->next) { popFront(); return; }
	OutOfBounds(size() - 1);
	
	Node* previous = at(size() - 2);
	delete previous->next;
	previous->next = nullptr;
}
void LinkedList::popFront() {
	if (!head) { OutOfBounds(0); }

	Node* toDelete = head;
	head = head->next;
	delete toDelete;
}
void LinkedList::del(unsigned int pos) {

	if (!pos) { popFront(); return; } //Remove head

	OutOfBounds(pos);

	Node* previous = at(pos - 1);
	Node* current = previous->next;

	previous->next = current->next;
	delete current;

}

Node* LinkedList::at(unsigned int pos) {
	OutOfBounds(pos);

	Node* node = this->head;

	if (!node) { return head; };

	for (int count = 0; node->next && (count != pos); ++count) {
		node = node->next;
	}

	return node;
}
Node* LinkedList::front(){
	return head;
}
Node* LinkedList::back(){
	return at(size() - 1);
}

void LinkedList::populate(unsigned int size) {
	srand( (int) std::time(NULL) );

	for (int i = 0; i <= size - 1; ++i) {
		prepend(rand());
	}
}

unsigned int LinkedList::size() {
	Node* head = this->head;
	int count = 0;

	while (head) {
		head = head->next;
		count++;
	}

	return count;
}
void LinkedList::print() {
	Node* node = head;
	int count = 1;

	while (node) {
		std::cout << count << ": " << node->data << std::endl;
		node = node->next;
		count++;
	}
	std::cout << std::endl;
}


//Private Functions
void LinkedList::OutOfBounds(unsigned int pos) {
	if (pos < size()) {
		return;
	}
	throw(std::out_of_range(NULL));
}



//IO Loop
void ModifyList(LinkedList* L) {
	int input, pos, data, amount;

	while (true) {
		std::cout << "Select an Option" << std::endl;
		std::cout << "1. View List" << std::endl;
		std::cout << "2. View Particular Node" << std::endl;
		std::cout << "3. Show List Size" << std::endl;
		std::cout << "4. Insert Node into List" << std::endl;
		std::cout << "5. Delete Node from List" << std::endl;
		std::cout << "6. Fill List with Random Numbers" << std::endl;
		std::cout << "7. Return" << std::endl;
		
		input = Input(1, 7);

		switch (input) {
		case 1:
			if (!L->size()) { std::cout << "Empty List" << std::endl; break; }

			L->print();

			break;
		case 2:
			if (!L->size()) { std::cout << "Empty List" << std::endl; break; }
			std::cout << "which node?" << std::endl << "~ ";

			pos = Input(1,L->size());
			std::cout << std::endl << L->at(pos - 1)->data << std::endl;

			break;
		case 3:
			std::cout << L->size();

			break;
		case 4:
			std::cout << "what?" << std::endl << "~ ";
			std::cin >> data;

			if (!L->size()) { L->prepend(data); break; }

			std::cout << "where?" << std::endl << "~ ";
			pos = Input(1, L->size() + 1) - 1;

			if (!pos)
				{ L->prepend(data); }
			else if (pos == L->size())
				{ L->append(data);}
			else
				{ L->insert(data, pos); }

			break;
		case 5:
			if (!L->size()) { std::cout << "Empty List" << std::endl; break; }

			std::cout << "which?" << std::endl << "~ ";
			pos = Input(1, L->size()) - 1;

			if (!pos)
				{ L->popFront(); }
			else if (pos == L->size())
				{ L->popBack(); }
			else
				{ L->del(pos); }

			break;
		case 6:
			std::cout << "how many?" << std::endl << "~ ";
			std::cin >> amount;

			L->populate(amount);

			break;
		case 7:
			return;
		}
		std::cout << std::endl;
	}

	
}

int Input(int lower, int upper) {
	int inp;
	do {
		std::cout << "Input a number between " << lower << " and " << upper << std::endl << "~ ";
		std::cin >> inp;
	} while (!(inp <= upper) || !(inp >= lower));

	return inp;
}

void MemLeakTest(LinkedList* L) {
	while (true) {
		L->populate(30000);

		int size_ = L->size() - 1;
		for (int i = size_; i >= 0; i--) {
			L->del(i);
		}
	}
}
