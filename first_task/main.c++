#include <iostream>

using std::cin;
using std::cout;

int Power(long long number, unsigned pow);
int AddDigit(int number, unsigned new_digit, unsigned current_power);

int main() 
{
	cout << "Enter the original number:\n";
	int number = 0;
	cin >> number;

	while (number)
	{
		cout << "\nEnter the digit you would like to add:\n";
		int new_digit = 0;
		cin >> new_digit;

		cout << "\nThe new number is:\n"
			<< AddDigit(number, new_digit, 1);

		cout << "\n\nEnter the new original number:\n";
		cin >> number;
	}

	cout << "\nProgramm has been completed.";

	return 0;
}

int Power(long long number, unsigned pow) 
{
	return (pow) ? number * Power(number, pow - 1) : 1;
}

int AddDigit(int number, unsigned new_digit, unsigned current_power) 
{
	if (!(number / Power(10U, current_power)))
	{
		number += 
			(new_digit * Power(10U, current_power)) * (number / labs(number));

		return number;
	}
	else
	{
		AddDigit(number, new_digit, current_power + 1);
	}
}
