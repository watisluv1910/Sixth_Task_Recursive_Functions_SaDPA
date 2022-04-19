#ifndef LIST_H
#define LIST_H

#include <string>

using std::string;

template <typename T>
class List {
public:

	List(string name);
	~List();

	void PushFront(T data);
	void PushBack(T data);
	void Remove(size_t index, size_t range);
	void PopFront(); // removes first node of the list
	void Clear(); // removes all nodes of the list
	size_t get_size() { return size_; }
	string get_name() { return name_; }

	T& operator[](const size_t index); // operator [] override

private:

	// inserted class Node describes an element of the list
	template <typename T>
	class Node {
	public:

		Node* next_obj_ptr; // pointer to the next Node object
		T data_; // info in a list cell

		// T() means zero value for template type
		Node(T data = T(), Node* pNext = nullptr) {

			this->data_ = data;
			this->next_obj_ptr = pNext;
		};

		~Node() {};
	};

	size_t size_; // the size of the list
	Node<T>* head_obj_ptr; // pointer to the head Node object
	string name_; // name of the list
};

#endif // !LIST_H
