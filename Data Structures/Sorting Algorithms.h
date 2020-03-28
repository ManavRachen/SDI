#pragma once

namespace SDI {

	/// Base class to be inherited by data structure | Gives data structures the ability to sort their elements 
	template<typename ListType, typename NodeType>
	class SortingAlgorithms {


	protected:

		/// Peforms selection sort on an input list
		void selectionSort(ListType* List, bool inAscending = true) {
			Iterator<NodeType> current;

			if (inAscending) {
				for (current = List->front(); current != List->back(); current++) { // Sort by smallest to largest
					NodeType* smallestNode = findSmallest(*current);
					swap(List, *current, smallestNode);
				}
			}
			else {
				for (current = List->front(); current != List->back(); current++) { // Sort by largest to smallest
					NodeType* largestNode = findLargest(*current);
					swap(List, *current, largestNode);
				}
			}

		}

		/// Peforms insertion sort on an input list
		void insertionSort(ListType* List) { // DOES NOT WORK WITH SINGLY LINKED LISTS
			Iterator<NodeType> sortedIndex, compare, current;

			for (sortedIndex = List->front(); sortedIndex != nullptr; sortedIndex++) { // Advance Sorted Marker
				current = sortedIndex;

				for (compare = current; compare != nullptr; compare--) {		// Decend down the sorted elements
					if (current < *compare) {
						swap(List, *current, *compare);
						current--;
					}
				}
			}
		}


	private:

		/// Returns pointer to the smallest node after the starting node
		NodeType* findSmallest(NodeType* start) {
			NodeType* smallest = start;
			Iterator<NodeType> current;
			current = *smallest;

			while (*current) {
				if (current < smallest) {
					smallest = *current;
				}
				current++;
			}

			return smallest;
		}

		/// Returns pointer to the largest node after the starting node
		NodeType* findLargest(NodeType* start) {
			NodeType* largest = start;
			Iterator<NodeType> current;
			current = *largest;

			while (*current) {
				if (current > largest) {
					largest = *current;
				}
				current++;
			}

			return largest;
		}

		/// Calls swap() on a List
		void swap(ListType* List, NodeType* first, NodeType* second) {

			List->swap(first, second);


			//Type temp = first->data;

			//first->data = second->data;
			//second->data = temp;

		}

	};

}

//
//class Heap {
//public:
//
//	//Heap(LinkedList* List) { head = List->front(); }
//	DoubleNode* head;
//
//	DoubleNode* levelOrder() {
//		Queue<DoubleNode*> Q;
//		Q.push(head);
//
//		while (true) {
//			if (Q.bottom()->data->left || Q.bottom()->data->right) 
//			{
//				return Q.bottom()->data; 
//			}
//
//			Q.push(Q.bottom()->data->left);
//			Q.push(Q.bottom()->data->right);
//
//			Q.pop();
//		}
//	}
//
//	void add() {
//		DoubleNode* node = new DoubleNode();
//		DoubleNode* s = levelOrder();
//		if (!s->left) { s->left = node; }
//		else { s->right = node; }
//	}
//
//	void heapify(){
//		
//	}
//	void buildHeap(){
//		
//	}
//	void printHeap(){}
//};
//
//
//template<typename ListType, typename NodeType, typename Type>
//class MergeS {
//
//	void mergeSort(LinkedListT<Type>* List) {
//
//		LinkedListT<LinkedListT<Type>> xx;
//		LinkedListT<LinkedListT<Type>>::iterator a;
//		a = xx.front();
//
//		for (int i = 0; i < List.size(); i++) {
//			LinkedListT<Type>* L = new LinkedListT<Type>;
//			L->head = List.head;
//			xx.append();
//		}
//	}
//
//	void merge() {
//
//		
//
//	}
//
//
//
//};
//