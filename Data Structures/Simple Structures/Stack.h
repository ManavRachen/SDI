#pragma once

template<typename Type>
class Stack {
public:
	Stack() { head = nullptr; }

	void push(Type data) {
		NodeT<Type>* node = new NodeT<Type>();
		node->data = data;
		node->next = head;
		head = node;
	}
	
	void pop() {
		NodeT<Type>* toDelete = head;
		head = head->next ;
		delete toDelete;
	}

	NodeT<Type>* top() {
		return head;
	}

private:
	NodeT<Type>* head;
};
