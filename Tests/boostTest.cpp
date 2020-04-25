#include "Boost Test Console\pch.h"
#include "pch.h"
#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>

using namespace SDI;


/// Testing Insertion into LinkedList, Double LinkedList and Array
void testInsertion() {

	// Define static dataset to check against
	int numbers[5]{ -23411,0,1,5,103 };

	// Init Data Structures
	LinkedList<int> list;
	DoublyLinkedList<int> dlist;
	Array<int> arr;

	// Iterate through and append dataset to each structure
	for (int i : numbers) {
		list.append(i);
		dlist.append(i);
		arr.pushBack(i);
	}

	// Test if all insertions were correct with all structures
	for (int i = 0; i < 5; i++) {
		BOOST_CHECK(list[i] == numbers[i]);
		BOOST_CHECK(dlist[i] == numbers[i]);
		BOOST_CHECK(arr[i] == numbers[i]);
	}
	
}


/// Testing Deletion from LinkedList, Double LinkedList and Array
void testDeletion() {

	// Define static dataset to check against
	int numbers[5]{ -23411,0,1,5,103 };

	// Init Data Structures
	LinkedList<int> list;
	DoublyLinkedList<int> dlist{};
	Array<int> arr;

	// Iterate through and append dataset to each structure
	for (int i : numbers) {
		list.append(i);
		dlist.append(i);
		arr.pushBack(i);
	}


	// Testing Delete from Index Function
	list.del(2);
	BOOST_CHECK(list[2] == 5);
	dlist.del(2);
	BOOST_CHECK(dlist[2] == 5);
	arr.erase(2);
	BOOST_CHECK(list[2] == 5);
	
	// Testing PopBack Function
	list.popBack();
	BOOST_CHECK(list[2] == 5);
	dlist.popBack();
	BOOST_CHECK(dlist[2] == 5);
	arr.popBack();
	BOOST_CHECK(list[2] == 5);
	
	// Testing PopFront Function
	list.popFront();
	BOOST_CHECK(list[0] == 0);
	dlist.popFront();
	BOOST_CHECK(dlist[0] == 0);

}


/// Testing Swapping data within LinkedList, Double LinkedList and Array
void testSwap() {

	// Define static dataset to check against
	int numbers[5]{ -23411,0,1,5,103 };

	// Init Data Structures
	LinkedList<int> list;
	DoublyLinkedList<int> dlist{};
	Array<int> arr;

	// Iterate through and append dataset to each structure
	for (int i : numbers) {
		list.append(i);
		dlist.append(i);
		arr.pushBack(i);
	}

	// Swap nodes at index 0 and 3
	list.swap(0, 3);
	dlist.swap(0, 3);
	arr.swap(0, 3);


	//Testing if the swaps were successful

	BOOST_CHECK(list[0] == 5);
	BOOST_CHECK(list[3] == -23411);

	BOOST_CHECK(dlist[0] == 5);
	BOOST_CHECK(dlist[3] == -23411);

	BOOST_CHECK(arr[0] == 5);
	BOOST_CHECK(arr[3] == -23411);

}


/// Testing Sorting Algorithms in LinkedList, Double LinkedList and Array
void testSort() {

	// Define static datasets to check against
	int unsorted[5]{ 1,5,103,0,-23411 };
	int sorted[5]{ -23411,0,1,5,103 };

	// Init Data Structures
	LinkedList<int> list;
	DoublyLinkedList<int> dlist;
	Array<int> arr;

	// Iterate through and append dataset to each structure
	for (int i : unsorted) {
		list.prepend(i);
		dlist.prepend(i);
		arr.pushBack(i);
	}


	// Sort Each Structure
	list.sort();
	dlist.sort();
	//arr.sort();


	// Compare against static sorted dataset for correct sort
	for (int i = 0; i < 5; i++) {
		BOOST_CHECK(list[i] == sorted[i]);
		BOOST_CHECK(dlist[i] == sorted[i]);
		//BOOST_CHECK(arr[i] == sorted[i]);
	}
}





BOOST_AUTO_TEST_CASE(myTestCase)
{
	// Test Insertion into data structures
	testInsertion();

	// Test Deletion of elements in data structures
	testDeletion();

	// Test node/element swapping
	testSwap();

	// Test sorting algorithms on data structures
	testSort();


}



