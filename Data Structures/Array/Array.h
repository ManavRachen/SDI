#pragma once
#include <initializer_list>

template<typename Type>
class Array : SortingAlgorithms<Array<Type>, Type>
{
public:

	Array() {}	// Empty Constructor
	~Array() { clear(); } // Destructor
	// Initialiser List Constructor
	Array(std::initializer_list<Type> data) {
		int initSize = data.size();
		index = initSize;

		head = (Type*)malloc(initSize * sizeof(Type));
		int count = 0;

		for (Type current : data) {
			Type* addToArray = head + count;
			*addToArray = current;
			count++;
		}

		tail = head + initSize;
	}


	Type& operator[](int pos) { return at(pos); }
	Type& at(int pos) {
		RangeCheck(pos);
		return *(head + pos);
	}
	Type* front() {
		RangeCheck(0);
		return head;
	}
	Type* back() {
		RangeCheck(size() - 1);
		return (head + index - 1);
	}


	// bool check
	bool isEmpty() {
		return (index == 0);
	}
	// sized used by data
	int size() {
		return index;
	}
	// allocated size
	int capacity() {
		return std::abs(head - tail);
	}


	 // Makes sure x amount of elements have been reserved
	void reserve(int size) {
		if (size > capacity()) {
			Relocate(size);
		}
	}
	// Changes the size of the array
	void resize(int size) {
		if (size < capacity()) {
			index = size;
			std::cerr << "Array has been Truncated" << std::endl;
		}
		Relocate(size);
	}
	// Reduce allocated size to fit size used by data
	void shrink() {
		Relocate(index);
	}
	// Remove all elements and reduce size to 0
	void clear() {
		if (capacity()) {
			free(head);
			tail = head;
			index = 0;
		}
	}


	// Inserts an element at the position
	void insert(int pos, Type data) {
		RangeCheck(pos);
		allocCheck();

		// Shift elements past the inserted element up by 1
		for (int current = index; current > pos; current--) {
			memoryAt(current) = memoryAt(current - 1);
		}

		*(head + pos) = data;
		
		index++;
	}
	// Deletes an element at the position
	void erase(int pos) {
		RangeCheck(pos);

		// Shift elements past the deleted element down by 1
		for (int current = pos; current < index - 1; current++) {
			memoryAt(current) = memoryAt(current + 1);
		}

		index--;
	}
	// Removes the data from the back
	void popBack() {
		RangeCheck(0); // Throw if there are no elements
		at(index - 1) = NULL;
		index--;
	}
	// Add data to the end of the array 
	void pushBack(Type data) {
		allocCheck();

		memoryAt(index) = data;

		index++;
	}
	// Swap elements either using the index or a reference
	void swap(Type* first, Type* second) {
		int pos1 = std::abs(head - first);
		int pos2 = std::abs(head - second);

		swap(pos1, pos2);
	}
	void swap(int first, int second) {
		Type fData = at(first);
		Type sData = at(second);

		memoryAt(first) = sData;
		memoryAt(second) = fData;
	}
	

	void print() {
		for (int i = 0; i < index; i++) {
			std::cout << at(i);
		}
	}
	void sort() {
		//this->selectionSort(this);
		this->pen(this);
	}

private:
	Type* head; // The first reserved memory location
	Type* tail; // The last reserved memory location
	int index = 0; // The current ammount of elements that are initialised


	// At function without the range check
	Type& memoryAt(int pos) {
		return *(head + pos);
	}

	// Converts Negative search index to positive
	int change(int pos) {
		if (pos < 0) {
			return size() + (pos);
		}
		return pos;
	}

	// Checks if the value being accessed is in range
	void RangeCheck(int pos) {
		pos = change(pos);
		if (pos >= size() || pos < 0) { 
			throw(std::out_of_range(NULL)); 
		}
	}
	// Checks capacity before adding new elements
	void allocCheck() {
		if (size() == capacity()) {
			Relocate(capacity() + 1);
		}
	}
	// Moves data to new allotted memory with new size
	void Relocate(int size) {
		head = (Type*)realloc(head, sizeof(Type)*size);
		tail = head + size;
	}

};

