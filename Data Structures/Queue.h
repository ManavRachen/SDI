#pragma once

namespace SDI {

	/// A simple queue for basic operaton
	template<typename Type>
	class Queue {
	public:
		Queue() { head = nullptr; tail = nullptr; }

		/// Push data to end of queue
		void push(Type data) {
			Node<Type>* node = new Node<Type>();
			node->data = data;

			node->next = nullptr;
			if (!head) { head = node; tail = node; }
			else { tail->next = node; }

			tail = node;
		}

		/// Remove data from front of queue
		void pop() {
			Node<Type>* toDelete = head;
			head = head->next;
			delete toDelete;
			if (!head) { tail = nullptr; }
		}

		/// Return front of queue
		Node<Type>* bottom() {
			return head;
		}

	private:
		/// Pointer to front of queue
		Node<Type>* head;
		/// Pointer to back of queue
		Node<Type>* tail;
	};

}