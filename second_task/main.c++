#include "list.c++"

#include <iostream>
#include <time.h>

using std::cin;
using std::cout;

template<typename T>
bool FillList(List<T>*& list);

template<typename T>
void PrintList(List<T>*& list);

template<typename T>
bool CompareLists(List<T>*& first_list, List<T>*& second_list);

template<typename T>
bool CompareElements(List<T>*& first_list, List<T>*& second_list, 
	const size_t current_pos);

int main()
{
	srand(time(0));

	List<int>* first_list = new List<int>("First_list");
	List<int>* second_list = new List<int>("Second_list");

	if (!FillList(first_list))
	{
		return 1;
	}

	cout << '\n';

	if (!FillList(second_list))
	{
		return 1;
	}

	PrintList(first_list);
	PrintList(second_list);

	if (CompareLists(first_list, second_list))
	{
		cout << "\nLists are equal.\n";
	}
	else
	{
		cout << "\nLists aren't equal.\n";
	}

	std::system("pause");

	return 0;
}

template<typename T>
bool FillList(List<T>* &list)
{
	cout << "Enter the number of elements in the " << list->get_name() << ":\n";
	size_t list_size = 0;
	cin >> list_size;

	if (list_size <= 0)
	{
		std::cerr << "\nIncorrect list size. Try again.\n";
		return 0;
	}

	cout << "\nEnter the way to fill the " << list->get_name() << ":\n"
		<< "Enter <1> to fill the list with random numbers.\n"
		<< "Enter <2> to fill the list by yourself.\n"
		<< "Your choise is:\n";
	int path = 0;
	cin >> path;

	switch (path)
	{
	case 1:
	{
		for (size_t i = 0; i < list_size; i++)
		{
			list->PushFront(rand() % 100);
		}
		break;
	}
	case 2:
	{
		cout << "\nEnter the list of elements:\n";

		for (size_t i = 0; i < list_size; i++)
		{
			int temp_variable = 0;
			cin >> temp_variable;

			list->PushFront(temp_variable);
		}
		break;
	}
	default:
		std::cerr << "\nIncorrect path number. Try again.\n";
		return 0;
		break;
	}

	return 1;
}

template<typename T>
void PrintList(List<T>*& list)
{
	cout << "\nThe " << list->get_name() << " is:\n";

	for (size_t i = 0; i < list->get_size(); i++)
	{
		cout << (*list)[i] << '\t';
	}

	cout << '\n';
}

template<typename T>
bool CompareElements(List<T>*& first_list, List<T>*& second_list, 
	const size_t current_pos)
{
	if (!(current_pos + 1))
	{
		return true;
	}
	else if ((*first_list)[current_pos] != (*second_list)[current_pos])
	{
		return false;
	}
	else
	{
		return CompareElements(first_list, second_list, current_pos - 1);
	}
}

template<typename T>
bool CompareLists(List<T>* &first_list, List<T>* &second_list)
{
	if (first_list->get_size() != second_list->get_size())
	{
		return false;
	}

	return CompareElements(first_list, second_list, 
		first_list->get_size() - 1);
}
