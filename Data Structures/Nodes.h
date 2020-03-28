#pragma once

namespace SDI {

	/// A template typed singly linked node struct
	template<typename Type>
	struct Node
	{
	public:
		Node() { next = nullptr; }
		~Node() { next = nullptr; }

		/// Comparison operator overload
		bool operator == (Type x) { return (data == x); }
		/// Iterate operator overload
		Node* operator ++ (int) { return next; }
		/// De-Iterate operator overload | Needs to be defined for template purposes, will always throw
		Node* operator -- (int) { throw(std::logic_error(NULL)); }


		/// Pointer to the next node
		Node* next;
		/// Held data of defined Type
		Type data;
	};

	/// A template typed doubly linked node struct
	template<typename Type>
	struct DoubleNode
	{
	public:
		DoubleNode() { left = nullptr; right = nullptr; }
		~DoubleNode() { left = nullptr; right = nullptr; }

		/// Comparison operator overload
		bool operator == (Type x) { return (data == x); }
		/// Iterate operator overload
		DoubleNode* operator ++ (int) { return right; }
		/// De-Iterate operator overload 
		DoubleNode* operator -- (int) { return left; }


		/// Pointer to the next node
		DoubleNode* left;
		/// Pointer to previous node
		DoubleNode* right;
		/// Held data of defined Type
		Type data;
	};

}

//Node* operator + (int) { return next; }