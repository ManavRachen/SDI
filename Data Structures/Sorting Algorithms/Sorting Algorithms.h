#pragma once

template<typename ListType, typename NodeType, typename Type>
class SortingAlgorithms {


public:

	void selectionSort(ListType* List) {
		int size = List->size();

		for (int current = 0; current < size; current++) {
			NodeType* smallNode = findSmallest(List->at(current));
			swap(List->at(current), smallNode);
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

