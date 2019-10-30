#include "pch.h"

//Operators--------------------------------------------------------------------------------------//

//Constructor
BinarySearchTree::BinarySearchTree() {
	head = nullptr;
}


//Insertion and Deletion-------------------------------------------------------------------------//

//Add node
void BinarySearchTree::addNode(int data) {
	DoubleNode* node = new DoubleNode();
	node->data = data;

	if (!head) {
		head = node;
		return;
	}

	DoubleNode* current = head;

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


//Balancing tree---------------------------------------------------------------------------------//

//Balances each node in the tree
void BinarySearchTree::BalanceTree() {
	LinkedList<DoubleNode*> Stack;
	DfsPostOrder(&Stack, head);
	DoubleNode* current;

	while (Stack.front()) {
		current = Stack.front()->data;
		current->left = Rotate(current->left);
		current->right = Rotate(current->right);
		Stack.popFront();
	}

}

//Compare the difference in height in each branch then return the difference
int BinarySearchTree::BalanceFactor(DoubleNode* node) {
	if (!node) { return 0; }
	int difference = Height(node->left) - Height(node->right);
	return difference;
}

//Return if the part of the tree is balanced at a given node
bool BinarySearchTree::IsBalanced(DoubleNode* node) {
	if ((BalanceFactor(node) >= -1) && (BalanceFactor(node) <= 1)) { return true; }
	return false;
}

//Return the height of the tree at a given node
int BinarySearchTree::Height(DoubleNode* node) {
	if (!node) { return 0; }
	int sizeLeft = Height(node->left);
	int sizeRight = Height(node->right);

	if (sizeLeft > sizeRight) { return sizeLeft + 1; }
	return sizeRight + 1;
}

//Decides which rotation to use
DoubleNode* BinarySearchTree::Rotate(DoubleNode * node) {	
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
DoubleNode* BinarySearchTree::LLrotate(DoubleNode * node) {
	DoubleNode* left = node->left;
	node->left = left->right;
	left->right = node;
	return left;
}

//Right of right inbalance Rotation
DoubleNode* BinarySearchTree::RRrotate(DoubleNode * node) {
	DoubleNode* right = node->right;
	node->right = right->left;
	right->left = node;
	return right;
}

//Left of right inbalance Rotation
DoubleNode* BinarySearchTree::LRrotate(DoubleNode * node) {
	DoubleNode* left = node->left;
	node->left = RRrotate(left);
	return LLrotate(node);
}

//Right of left inbalance Rotation
DoubleNode* BinarySearchTree::RLrotate(DoubleNode * node) {
	DoubleNode* right = node->right;
	node->right = LLrotate(right);
	return RRrotate(node);
}

//Add all elements in tree into a stack in post order
void BinarySearchTree::DfsPostOrder(LinkedList<DoubleNode*>* Stack, DoubleNode* node) {
	if (node == nullptr) { return; }

	DfsPostOrder(Stack, node->left);
	DfsPostOrder(Stack, node->right);

	Stack->append(node);
}