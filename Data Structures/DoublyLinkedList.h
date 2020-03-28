#pragma once
#include <iostream>
#include <string>

namespace SDI {

	/// A template typed doubly linked list | Inherits the sorting algorithm class
	template<typename Type>
	class DoublyLinkedList : SortingAlgorithms< DoublyLinkedList<Type>, DoubleNode<Type>>
	{
	public:

		//Operators------------------------------------------------------//

		//Constructor
		DoublyLinkedList() {
			head = nullptr;
			tail = nullptr;
		}

		//Destructor
		~DoublyLinkedList() {
			DoubleNode<Type>* head = this->head;
			DoubleNode<Type>* next;

			while (head) {
				next = head->right;
				delete head;
				head = next;
			}
		}

		/// Overloads the [] operator ~ calls at()
		DoubleNode<Type>& operator[](int pos) {
			return at(pos);
		}


		//Insertion & Deletion-------------------------------------------//

		/// Add node at end of list
		void append(Type data) {
			DoubleNode<Type>* node = new DoubleNode<Type>();
			node->data = data;

			node->left = tail;
			if (tail) { tail->right = node; }
			else { head = node; }
			tail = node;
		}

		/// Add node at start of list
		void prepend(Type data) {
			DoubleNode<Type>* node = new DoubleNode<Type>();
			node->data = data;

			node->right = head;
			if (head) { head->left = node; }
			else { tail = node; }
			head = node;
		}

		/// Add node at index x
		void insert(Type data, int pos) {

			if (!pos) { prepend(data); return; } //Prepend
			if (pos == size()) { append(data); return; } //Append

			DoubleNode<Type>* node = new DoubleNode<Type>();
			node->data = data;

			if (!head) { head = node; tail = node; return; } //Empty

			OutOfBounds(pos - 1);

			DoubleNode<Type>* previous = at(pos - 1);
			DoubleNode<Type>* after = previous->right;
			node->right = after;
			node->left = previous;
			previous->right = node;
			after->left = node;

		}

		/// Swaps the data found in 2 given nodes | Note: this does not switch the node objects in memory
		void swap(DoubleNode<Type>* first, DoubleNode<Type>* second) {
			Type fData = first->data;

			first->data = second->data;
			second->data = fData;
		}

		/// Swap but using index
		void swap(int first, int second) {
			DoubleNode<Type>* f = &at(first);
			DoubleNode<Type>* s = &at(second);

			Type temp = f->data;

			f->data = s->data;
			s->data = temp;
		}

		/// Delete node at end of list
		void popBack() {
			if (!tail) { OutOfBounds(0); }

			DoubleNode<Type>* toDelete = tail;
			DoubleNode<Type>* previous = tail->left;
			tail = previous;
			if (previous) { previous->right = nullptr; }
			else { head = nullptr; }
			delete toDelete;
		}

		/// Delete node at start of list
		void popFront() {
			if (!head) { OutOfBounds(0); }

			DoubleNode<Type>* toDelete = head;
			DoubleNode<Type>* next = head->right;
			head = next;
			if (next) { next->left = nullptr; }
			else { tail = nullptr; }
			delete toDelete;
		}

		/// Delete node at index x
		void del(int pos) {

			if (!pos) { popFront(); return; } //Remove head
			if (pos == (size() - 1)) { popBack(); return; } //Remove back

			OutOfBounds(pos);

			DoubleNode<Type>* previous = &at(pos - 1);
			DoubleNode<Type>* current = previous->right;

			previous->right = current->right;
			current->right->left = previous;
			delete current;

		}


		//Index and Searching--------------------------------------------//

		/// Return final node
		DoubleNode<Type>& back() {
			return *tail;
		}

		/// Return first node
		DoubleNode<Type>& front() {
			return *head;
		}

		/// Return node at index x
		DoubleNode<Type>& at(int pos) {

			OutOfBounds(pos);

			if (pos >= 0) {
				DoubleNode<Type>* node = head;

				//if (!node) { return head; };

				for (int count = 0; node->right && (count != pos); ++count) {
					node = node->right;
				}

				return *node;
			}
			else {
				DoubleNode<Type>* node = tail;

				//if (!node) { return tail; };

				for (int count = -1; node->left && (count != pos); --count) {
					node = node->left;
				}

				return *node;
			}

		}

		/// Returns size of the list
		unsigned int size() {
			DoubleNode<Type>* head = this->head;
			int count = 0;

			while (head) {
				head = head->right;
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
		void print() {
			DoubleNode<Type>* node = head;
			int count = 1;

			while (node) {
				std::cout << count << ": " << node->data << std::endl;
				node = node->right;
				count++;
			}
			std::cout << std::endl;
		}

		/// Calls insertion sort
		void sort() {
			this->selectionSort(this);
		}

	private:
		/// Pointer to front of list
		DoubleNode<Type>* head;
		/// Pointer to back of list
		DoubleNode<Type>* tail;

		/// Checks if input is in range
		void OutOfBounds(unsigned int pos) {
			if (pos < size()) {
				return;
			}
			throw(std::out_of_range(NULL));
		}
	};

}