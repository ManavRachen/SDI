#include "pch.h"
#include <iostream>

void program1() {
	LinkedList L;
	L.append(1);
	std::cout << L.back()->data;
}



int main()
{
	program1();


    std::cout << "\n END \n"; 
}