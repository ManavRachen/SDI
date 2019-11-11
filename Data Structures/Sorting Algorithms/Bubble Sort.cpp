// Bubble Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int a, n, temp, passes = 0;
	int randomNumbers[5] = { 4, 8, 1, 2, 10 };
	cout << "Inputted List of Numbers" << endl;
	for (a = 0; a < 5; a++)
	{
		cout << randomNumbers[a] << "\t";
	}
	cout << endl;
	for (a = 0; a < 5; a++)
	{
		for (n = a + 1; n < 5; n++)
		{
			if (randomNumbers[n] < randomNumbers[a])
			{
				temp = randomNumbers[a];
				randomNumbers[a] = randomNumbers[n];
				randomNumbers[n] = temp;
			}
		}
		passes++;
	}
	cout << "Bubble Sorted Sequence" << endl;
	for (a = 0; a < 5; a++)
	{
		cout << randomNumbers[a] << "\t";
	}
	cout << endl << "Number of passes for the bubble sort was: " << passes << endl;
	return 0;
}
