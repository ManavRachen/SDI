#include "pch.h"
#include <iostream>
#include <ctime>

#include <vector>





int main()
{

	LinkedListT<int> a;
	a.append(2); a.append(1); a.append(3); a.append(1); a.append(4); a.append(1); a.append(9); a.append(6);	

	a.print();
	a.sort();	
	a.print();

    std::cout << "\n END \n"; 
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

//void a() {
//	LinkedListT<int> List;
//	srand((int)std::time(NULL));
//
//	for (unsigned int i = 0; i <= 10000; ++i) {
//		List.prepend(rand());
//	}
//
//
//	List.sort();
//}