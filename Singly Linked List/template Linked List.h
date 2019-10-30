#pragma once
#include <iostream>
#include <string>


int Input(int upper, int lower);


template<typename Type>
class LinkedList
{
public:

	//Operators------------------------------------------------------//

	//Destructor
	~LinkedList() {
		Node<Type>* head = this->head;
		Node<Type>* next;

		while (head) {
			next = head->next;
			delete head;
			head = next;
		}
	}

	//Overloads the [] operator ~ calls at()
	Node<Type>* operator[](unsigned int pos) {
		return at(pos);
	} 
	
	//Insertion & Deletion-------------------------------------------//

	//Add node at end of list
	void append(Type data) {
		Node<Type>* node = new Node<Type>();
		node->data = data;

		if (!head) { head = node; }
		else { back()->next = node; }
	}

	//Add node at start of list
	void prepend(Type data) {
		Node<Type>* node = new Node<Type>();
		node->data = data;

		node->next = head;
		head = node;
	}

	//Add node at index x
	void insert(Type data, unsigned int pos) {

		if (!pos) { prepend(data); return; } //Prepend

		Node<Type>* node = new Node<Type>();
		node->data = data;

		if (!head) { head = node; return; } //Empty

		OutOfBounds(pos - 1);

		Node<Type>* previous = at(pos);
		node->next = previous->next;
		previous->next = node;

	}

	//Delete node at end of list
	void popBack() {
		if (!head->next) { popFront(); return; }
		OutOfBounds(size() - 1);

		Node<Type>* previous = at(size() - 2);
		delete previous->next;
		previous->next = nullptr;
	}

	//Delete node at start of list
	void popFront() {
		if (!head) { OutOfBounds(0); }

		Node<Type>* toDelete = head;
		head = head->next;
		delete toDelete;
	}

	//Delete node at index x
	void del(unsigned int pos) {

		if (!pos) { popFront(); return; } //Remove head

		OutOfBounds(pos);

		Node<Type>* previous = at(pos - 1);
		Node<Type>* current = previous->next;

		previous->next = current->next;
		delete current;

	}
	
	//Index and Searching--------------------------------------------//

	//Return final node
	Node<Type>* back() {
		return at(size() - 1);
	}

	//Return first node
	Node<Type>* front() {
		return head;
	}

	//Return node at index x
	Node<Type>* at(unsigned int pos) {
		OutOfBounds(pos);

		Node<Type>* node = this->head;

		if (!node) { return head; };

		for (int count = 0; node->next && (count != pos); ++count) {
			node = node->next;
		}

		return node;
	}

	//Returns size of the list
	unsigned int size() {
		Node<Type>* head = this->head;
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
		Node<Type>* node = head;
		int count = 1;

		while (node) {
			std::cout << count << ": " << node->data << std::endl;
			node = node->next;
			count++;
		}
		std::cout << std::endl;
	}

	//User Interface to modify the list
	void ModifyList() {
		int input, pos, amount;
		Type data;

		while (true) {
			std::cout << "Select an Option" << std::endl;
			std::cout << "1. View List" << std::endl;
			std::cout << "2. View Particular Node" << std::endl;
			std::cout << "3. Show List Size" << std::endl;
			std::cout << "4. Insert Node into List" << std::endl;
			std::cout << "5. Delete Node from List" << std::endl;
			std::cout << "6. Fill List" << std::endl;
			std::cout << "7. Return" << std::endl;

			input = Input(1, 7);

			switch (input) {
			case 1:
				if (!size()) { std::cout << "Empty List" << std::endl; break; }

				print();

				break;
			case 2:
				if (!size()) { std::cout << "Empty List" << std::endl; break; }
				std::cout << "which node?" << std::endl << "~ ";

				pos = Input(1, size());
				std::cout << std::endl << at(pos - 1)->data << std::endl;

				break;
			case 3:
				std::cout << size();

				break;
			case 4:
				std::cout << "what?" << std::endl << "~ ";
				std::cin >> data;

				if (!size()) { prepend(data); break; }

				std::cout << "where?" << std::endl << "~ ";
				pos = Input(1, size() + 1) - 1;

				if (!pos)
				{
					prepend(data);
				}
				else if (pos == size())
				{
					append(data);
				}
				else
				{
					insert(data, pos);
				}

				break;
			case 5:
				if (!size()) { std::cout << "Empty List" << std::endl; break; }

				std::cout << "which?" << std::endl << "~ ";
				pos = Input(1, size()) - 1;

				if (!pos)
				{
					popFront();
				}
				else if (pos == size())
				{
					popBack();
				}
				else
				{
					del(pos);
				}

				break;
			case 6:
				std::cout << "how many?" << std::endl << "~ ";
				std::cin >> amount;

				populate(amount);

				break;
			case 7:
				return;
			}
			std::cout << std::endl;
		}


	}

	
private:	
	Node<Type>* head;

	//Checks if input is in range
	void OutOfBounds(unsigned int pos) {
		if (pos < size()) {
			return;
		}
		throw(std::out_of_range(NULL));
	}
};
