#pragma once
#include <iostream>
#include <string>

namespace SDI {

	/// A template typed singly linked list | Inherits the sorting algorithm class
	template<typename Type>
	class LinkedList : SortingAlgorithms< LinkedList<Type>, Node<Type>>
	{
	public:



		//Operators------------------------------------------------------//


		//Constructor
		LinkedList() {
			head = nullptr;
		}

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

		/// Overloads the [] operator ~ calls at()
		Node<Type>& operator[](unsigned int pos) {
			return at(pos);
		}

		//Insertion & Deletion-------------------------------------------//

		/// Add node at end of list
		void append(Type data) {
			Node<Type>* node = new Node<Type>();
			node->data = data;

			if (!head) { head = node; }
			else { back().next = node; }
		}

		/// Add node at start of list
		void prepend(Type data) {
			Node<Type>* node = new Node<Type>();
			node->data = data;

			node->next = head;
			head = node;
		}

		/// Add node at index x
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

		/// Swaps the data found in 2 given nodes | Note: this does not switch the node objects in memory
		void swap(Node<Type>* first, Node<Type>* second) {
			Type fData = first->data;

			first->data = second->data;
			second->data = fData;
		}

		/// Swap but using index
		void swap(int first, int second){
			Node<Type>* f = &at(first);
			Node<Type>* s = &at(second);

			Type temp = f->data;

			f->data = s->data;
			s->data = temp;
		}

		/// Delete node at end of list
		void popBack() {
			if (!head->next) { popFront(); return; }
			OutOfBounds(size() - 1);

			Node<Type>* previous = &at(size() - 2);
			delete previous->next;
			previous->next = nullptr;
		}

		/// Delete node at start of list
		void popFront() {
			if (!head) { OutOfBounds(0); }

			Node<Type>* toDelete = head;
			head = head->next;
			delete toDelete;
		}

		/// Delete node at index x
		void del(unsigned int pos) {

			if (!pos) { popFront(); return; } //Remove head

			OutOfBounds(pos);

			Node<Type>* previous = &at(pos - 1);
			Node<Type>* current = previous->next;

			previous->next = current->next;
			delete current;

		}

		//Index and Searching--------------------------------------------//

		/// Return final node
		Node<Type>& back() {
			return at(size() - 1);
		}

		/// Return first node
		Node<Type>& front() {
			return *head;
		}

		/// Return node at index x
		Node<Type>& at(unsigned int pos) {
			OutOfBounds(pos);

			Node<Type>* node = this->head;

			if (!node) { return *head; };

			for (int count = 0; node->next && (count != pos); ++count) {
				node = node->next;
			}

			return *node;
		}

		/// Returns size of the list
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

		/// Add x amount of nodes to end of list
		void populate(unsigned int size) {
			for (unsigned int i = 0; i <= size - 1; ++i) {
				Type a = NULL;
				prepend(a);
			}
		}

		/// Prints the list
		/// Requires list to contain elements with std::<< operator overloads
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



		/// Calls selection sort
		void sort(bool inAscending = true) {
			this->selectionSort(this, inAscending);
		}


	private:
		/// Pointer to front of list
		Node<Type>* head;

		/// Checks if input is in range
		void OutOfBounds(unsigned int pos) {
			if (pos < size()) {
				return;
			}
			throw(std::out_of_range(NULL));
		}
	};

}