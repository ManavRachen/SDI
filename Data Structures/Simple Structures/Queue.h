#pragma once

template<typename Type>
class Queue {
public:
	Queue() { head = nullptr; tail = nullptr; }

	void push(Type data) {
		NodeT<Type>* node = new NodeT<Type>();
		node->data = data;

		node->next = nullptr;
		if (!head) { head = node; tail = node;  }
		else { tail->next = node; }
		
		tail = node;
	}

	void pop() {
		NodeT<Type>* toDelete = head;
		head = head->next;
		delete toDelete;
		if (!head) { tail = nullptr; }
	}

	NodeT<Type>* bottom() {
		return head;
	}

private:
	NodeT<Type>* head;
	NodeT<Type>* tail;
};
