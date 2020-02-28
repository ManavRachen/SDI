#pragma once

template<typename ListType, typename NodeType>
class SortingAlgorithms {


protected:

	void selectionSort(ListType* List) {
		Iterator<NodeType> current;

		for (current = List->front(); current != List->back(); current++) { // Iterate through the list
			NodeType* smallestNode = findSmallest(*current);
			swap(List, *current, smallestNode);
		}
	}

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

	void pen(ListType* List) {
		Iterator<NodeType> current;

		current = List->front();
		current++;
		current != List->back();
		
	}


private:

	NodeType* findSmallest(NodeType* start) {
		NodeType* smallest = start;
		Iterator<NodeType> current;
		current = smallest;
		
		while (*current) {
			if (current < smallest) {
				smallest = *current;
			}
			current++;
		}

		return smallest;
	}


	void swap(ListType* List, NodeType* first, NodeType* second) {

		List->swap(first, second);


		//Type temp = first->data;

		//first->data = second->data;
		//second->data = temp;

	}

};

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