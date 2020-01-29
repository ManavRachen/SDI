#pragma once

template<typename ListType, typename NodeType, typename Type>
class SortingAlgorithms {


protected:

	void selectionSort(ListType* List) {
		Iterator<NodeType> current;

		for (current = List->front(); current != List->back(); current++) {
			NodeType* smallestNode = findSmallest(*current);
			swap(*current, smallestNode);
		}
	}

	void insertionSort(ListType* List) { // DOES NOT WORK WITH SINGLY LINKED LISTS
		Iterator<NodeType> sortedIndex, compare, current;

		for (sortedIndex = List->front(); sortedIndex != nullptr; sortedIndex++) { // Iterate through the list
			current = sortedIndex;

			for (compare = current; compare != nullptr; compare--) {		// Decend down the sorted elements
				if (current < *compare) {
					swap(*current, *compare);
					current--;
				}	
			}
		}
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


	void swap(NodeType* first, NodeType* second) {
		Type temp = first->data;

		first->data = second->data;
		second->data = temp;


	}
};

