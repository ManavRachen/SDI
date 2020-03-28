#pragma once

namespace SDI {

	/// A simple stack for basic operaton
	template<typename Type>
	class Stack {
	public:
		Stack() { head = nullptr; }

		/// Push data to top of stack
		void push(Type data) {
			Node<Type>* node = new Node<Type>();
			node->data = data;
			node->next = head;
			head = node;
		}

		/// Remove data from top of stack
		void pop() {
			Node<Type>* toDelete = head;
			head = head->next;
			delete toDelete;
		}

		/// Return top of stack
		Node<Type>* top() {
			return head;
		}

	private:

		/// Pointer to top of stack
		Node<Type>* head;
	};

}