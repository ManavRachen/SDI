#pragma once

namespace SDI {

	/// A simple Binary Search Tree with balance capabilities
	class BinarySearchTree
	{
	public:
		BinarySearchTree();

		/// Finds place within the tree and inserts input data
		void addNode(int data);
		/// Returns a pointer to the node which cointains input data
		DoubleNode<int>* searchFor(int data);

	private:
		/// Pointer to the root node
		DoubleNode<int>* head;
		/// Recursive function first called by public function "searchFor"
		DoubleNode<int>* BinarySearch(int data, DoubleNode<int>* current);


		/// Refactors the binary tree to become balanced
		void BalanceTree();
		/// Calculates how weighted each node branch is
		int BalanceFactor(DoubleNode<int>* node);
		/// Returns true if the nodes' branches are balanced
		bool IsBalanced(DoubleNode<int>* node);
		/// Recursive function to determine the depth of the tree from a given point
		int Height(DoubleNode<int>* node);


		/// Performs one of 4 rotations depending on the balance factor of a given node
		DoubleNode<int>* Rotate(DoubleNode<int>* node);
		/// Peforms a left-left rotation
		DoubleNode<int>* LLrotate(DoubleNode<int>* node);
		/// Peforms a right-right rotation
		DoubleNode<int>* RRrotate(DoubleNode<int>* node);
		/// Peforms a left-right rotation
		DoubleNode<int>* LRrotate(DoubleNode<int>* node);
		/// Peforms a right-left rotation
		DoubleNode<int>* RLrotate(DoubleNode<int>* node);

		/// Performs Post Order Depth First Search
		void DfsPostOrder(Stack<DoubleNode<int>*>* Stack, DoubleNode<int>* node);

	};

}