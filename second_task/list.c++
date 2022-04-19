#include "list.h"

template<typename T>
inline List<T>::List(string name) 
{
	// constructor
	// class List fields initialization
	this->size_ = 0;
	this->head_obj_ptr = nullptr;
	this->name_ = name;
}

template<typename T>
inline List<T>::~List() 
{
	// destructor
	Clear(); // deleting the list
}

template<typename T>
void List<T>::PushFront(T data) 
{
	// creating new head Node object and head pointer update 
	head_obj_ptr = new Node<T>(data, head_obj_ptr);
	size_++;
}

template<typename T>
void List<T>::PushBack(T data)
{
	if (!head_obj_ptr)
	{
		head_obj_ptr = new Node<T>(data);
	}
	else
	{
		Node<T>* current_obj_ptr = this->head_obj_ptr;

		while (current_obj_ptr->next_obj_ptr)
		{
			current_obj_ptr = current_obj_ptr->next_obj_ptr;
		}

		current_obj_ptr->next_obj_ptr = new Node<T>(data);
	}

	size_++;
}

template<typename T>
void List<T>::Remove(size_t index, size_t range) 
{
	// deleting Nodes obj in selected range starting from the selected index
	while (range) 
	{
		if (!index) 
		{
			// deleting from the beginning of the list
			PopFront();
			range--;
		}
		else 
		{
			Node<T>* previous = this->head_obj_ptr;

			// searching for the element previous to needed:
			for (size_t i = 0; i < index - 1; i++) 
			{
				previous = previous->next_obj_ptr;
			}

			// creating temp object pointer
			Node<T>* toDelete = previous->next_obj_ptr;
			// removing an object from the list
			previous->next_obj_ptr = toDelete->next_obj_ptr;
			// deleting removed object
			delete toDelete;

			size_--;
			range--;
		}
	}
}

template<typename T>
void List<T>::PopFront() 
{
	Node<T>* temp = head_obj_ptr; // creating temp object pointer

	head_obj_ptr = head_obj_ptr->next_obj_ptr; // removing an object from the list

	delete temp; // deleting removed object

	size_--;
}

template<typename T>
void List<T>::Clear() 
{
	while (size_) 
	{
		PopFront();
	}
}

template<typename T>
T& List<T>::operator[](const size_t index)
{
	size_t counter = 0;
	Node<T>* current = this->head_obj_ptr;

	while (current) 
	{
		if (counter == index)
		{
			return current->data_;
		}
		current = current->next_obj_ptr;
		counter++;
	}
}
