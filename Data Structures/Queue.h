#pragma once

template<typename Type>
class Queue {
public:
	Queue() { head = nullptr; tail = nullptr; }

	void push(Type data) {
		Node<Type>* node = new Node<Type>();
		node->data = data;

		node->next = nullptr;
		if (!head) { head = node; tail = node;  }
		else { tail->next = node; }
		
		tail = node;
	}

	void pop() {
		Node<Type>* toDelete = head;
		head = head->next;
		delete toDelete;
		if (!head) { tail = nullptr; }
	}

	Node<Type>* bottom() {
		return head;
	}

private:
	Node<Type>* head;
	Node<Type>* tail;
};
