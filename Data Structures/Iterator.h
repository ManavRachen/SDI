#pragma once

namespace SDI {

	/// A class that is able to iterate through different types of data structures
	template<typename NodeType>
	class Iterator {

	public:
		
		/// Dereference operator overload | Returns data stored in iterator
		NodeType* operator * () { return current; }

		/// Comparison operator overload | compare against Node Type
		void operator = (NodeType& node) { current = &node; }
		/// Comparison operator overload | compare against Iterator
		void operator = (Iterator itr) { current = itr.current; }

		/// Less than operator overload
		int operator < (NodeType* rhs) { return (current->data < rhs->data); }
		/// Greater than operator overload
		int operator > (NodeType* rhs) { return (current->data > rhs->data); }
		/// Not Equal to operator overload
		bool operator != (NodeType& rhs) { return (current != &rhs); }

		/// Iterate operator overload | Returns node at index +1
		NodeType* operator ++ (int) { current = next(); return current; }
		/// De-Iterate operator overload | Returns node at index -1
		NodeType* operator -- (int) { current = previous(); return current; }

		/// Addition operator overload | Iterates current 'x' times
		void operator + (int rhs) {
			for (int i = 0; i < rhs; i++) {
				current = next();
			}
		}


	private:

		/// Pointer to current node
		NodeType* current;


		/// Returns pointer to next node
		NodeType* next() {
			if (current) { return (*current)++; }
			throw(std::out_of_range(NULL));
		}
		///Returns pointer to previous node
		NodeType* previous() {
			if (current) { return (*current)--; }
			throw(std::out_of_range(NULL));
		}

	};

}