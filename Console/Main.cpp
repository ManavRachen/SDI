#include "pch.h"
#include <iostream>

#include <time.h>

using namespace SDI;

void main() {

	Array<int> boxes;
	//boxes.reserve(10);
	boxes.pushBack(1);
	boxes.clear();
	boxes.pushBack(2);

	for (int box : boxes) {
		std::cout << *boxes.back();
	}


	//Array<int> a;
	//a.reserve(9);

	//LinkedList<int> b;

	//srand(time(NULL));
	//for (int i = 0; i <= 10; i++) {
	//	b.append(rand());
	//	a.pushBack(rand());
	//}
	//
	//b.sort();
	//b.print();

	//BinarySearchTree bb;
}