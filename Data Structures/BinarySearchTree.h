#pragma once

class BinarySearchTree
{
public:
	BinarySearchTree();
	void addNode(int data);
	DoubleNode<int>* searchFor(int data);

private:
	DoubleNode<int>* head;
	DoubleNode<int>* BinarySearch(int data, DoubleNode<int>* current);

	void BalanceTree();		
	int BalanceFactor(DoubleNode<int>* node);
	bool IsBalanced(DoubleNode<int>* node);
	int Height(DoubleNode<int>* node);
	
	DoubleNode<int>* Rotate(DoubleNode<int>* node);
	DoubleNode<int>* LLrotate(DoubleNode<int>* node);
	DoubleNode<int>* RRrotate(DoubleNode<int>* node);
	DoubleNode<int>* LRrotate(DoubleNode<int>* node);
	DoubleNode<int>* RLrotate(DoubleNode<int>* node);

	void DfsPostOrder(Stack<DoubleNode<int>*>* Stack, DoubleNode<int>* node);

};
