#include "pch.h"
#include <iostream>

#include <time.h>

void main() {
	Array<int> a;
	a.reserve(9);

	LinkedListT<int> b;

	srand(time(NULL));
	for (int i = 0; i <= 10; i++) {
		b.append(rand());
		a.pushBack(rand());
	}
	
	b.sort();
	b.print();
}