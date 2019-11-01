#pragma once

template<typename Type>
class Stack {
public:
	Stack() { head = nullptr; }

	void push(Type data) {
		Node<Type>* node = new Node<Type>();
		node->data = data;
		node->next = head;
		head = node;
	}
	
	void pop() {
		Node<Type>* toDelete = head;
		head = head->next ;
		delete toDelete;
	}

	Node<Type>* top() {
		return head;
	}

private:
	Node<Type>* head;
};
