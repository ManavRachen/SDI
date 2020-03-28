#include "pch.h"
#include "../Console/pch.h"

using namespace SDI;

//Operators--------------------------------------------------------------------------------------//

//Constructor
BinarySearchTree::BinarySearchTree() {
	head = nullptr;
}


//Insertion and Deletion-------------------------------------------------------------------------//

//Add node
void BinarySearchTree::addNode(int data) {
	DoubleNode<int>* node = new DoubleNode<int>();
	node->data = data;

	if (!head) {
		head = node;
		return;
	}

	DoubleNode<int>* current = head;

	while (true) {

		if (data < current->data) {
			if (!current->left) { current->left = node; return; }
			current = current->left;
			
		}
		else if (data >= current->data) {
			if (!current->right) { current->right = node; return; }
			current = current->right;
		}

	}
	
}


//Search Algorithm-------------------------------------------------------------------------------//

//Returns the node that holds the input data, or a null pointer if its not in the list
DoubleNode<int>* BinarySearchTree::searchFor(int data) {
	return BinarySearch(data,head);
}

//Recursive binary search function
DoubleNode<int>* BinarySearchTree::BinarySearch(int data, DoubleNode<int>* current) {

	if (!current) { return nullptr; }

	if (data < current->data) {
		current = BinarySearch(data, current->left);

	}
	else if (data > current->data) {
		current = BinarySearch(data, current->right);
	}

	return current;

}



//Balancing tree---------------------------------------------------------------------------------//

//Balances each node in the tree
void BinarySearchTree::BalanceTree() {
	Stack<DoubleNode<int>*> stack;
	DfsPostOrder(&stack, head);
	DoubleNode<int>* current;

	while (stack.top()) {
		current = stack.top()->data;
		current->left = Rotate(current->left);
		current->right = Rotate(current->right);
		stack.pop();
	}

}

//Compare the difference in height in each branch then return the difference
int BinarySearchTree::BalanceFactor(DoubleNode<int>* node) {
	if (!node) { return 0; }
	int difference = Height(node->left) - Height(node->right);
	return difference;
}

//Return if the part of the tree is balanced at a given node
bool BinarySearchTree::IsBalanced(DoubleNode<int>* node) {
	if ((BalanceFactor(node) >= -1) && (BalanceFactor(node) <= 1)) { return true; }
	return false;
}

//Return the height of the tree at a given node
int BinarySearchTree::Height(DoubleNode<int>* node) {
	if (!node) { return 0; }
	int sizeLeft = Height(node->left);
	int sizeRight = Height(node->right);

	if (sizeLeft > sizeRight) { return sizeLeft + 1; }
	return sizeRight + 1;
}

//Decides which rotation to use
DoubleNode<int>* BinarySearchTree::Rotate(DoubleNode<int>* node) {
	if (!node) { return nullptr; }
	int parent = BalanceFactor(node);

	bool isHead = false;
	if (head == node) { isHead = true; }
	
	if (parent > 1) {
		int left = BalanceFactor(node->left);

		if (left > 0) {
			node = LLrotate(node);
		}
		else {
			node = LRrotate(node);
		}
	}
	else if (parent < -1) {
		int right = BalanceFactor(node->right);

		if (right > 0) {
			node = RLrotate(node);
		}
		else {
			node = RRrotate(node);
		}
	}
	if (isHead) { head = node; }
	return node;
}

//Left of left inbalance Rotation
DoubleNode<int>* BinarySearchTree::LLrotate(DoubleNode<int>* node) {
	DoubleNode<int>* left = node->left;
	node->left = left->right;
	left->right = node;
	return left;
}

//Right of right inbalance Rotation
DoubleNode<int>* BinarySearchTree::RRrotate(DoubleNode<int>* node) {
	DoubleNode<int>* right = node->right;
	node->right = right->left;
	right->left = node;
	return right;
}

//Left of right inbalance Rotation
DoubleNode<int>* BinarySearchTree::LRrotate(DoubleNode<int>* node) {
	DoubleNode<int>* left = node->left;
	node->left = RRrotate(left);
	return LLrotate(node);
}

//Right of left inbalance Rotation
DoubleNode<int>* BinarySearchTree::RLrotate(DoubleNode<int>* node) {
	DoubleNode<int>* right = node->right;
	node->right = LLrotate(right);
	return RRrotate(node);
}

//Add all elements in tree into a stack in post order
void BinarySearchTree::DfsPostOrder(Stack<DoubleNode<int>*>* Stack, DoubleNode<int>* node) {
	if (node == nullptr) { return; }

	DfsPostOrder(Stack, node->left);
	DfsPostOrder(Stack, node->right);

	Stack->push(node);
}
