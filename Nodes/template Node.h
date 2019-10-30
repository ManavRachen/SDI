template<typename Type>
struct Node
{
public:
	~Node() { next = nullptr; }

	Node* next;
	Type data;
};
