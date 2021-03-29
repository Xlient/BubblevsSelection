#include<iostream>
#include<Windows.h>

/*
Author: La'Kaleigh Harris
Date: 4/30/19
Demo the bubble sort and selection sort on Arrays!
Output: On each pass the whole Array will be printed showing any changes made.
Input: None
Main algorithm: 2 Arrays of Integers were made, the first one is printed to the console
then passed to Bubblesort function which uses a pair of nested loops to pass through and
compare each value  then swaps places and saves in to a temp variable.
The selectSort function demonstates a selection sort and like the bubble sort
it uses nested loops to find the least value at its index then makes comparisons.
Main displays the orginal two Arrays and prints  whole Array after the swaps are done after each pass
then displays the number of passes and swaps each sorting algoritm took to sort the Array.

*/
void BubbleSort(int arr[] ,int SIZE);
void SelectionSort(int arr[], int SIZE);
void printArray(int a[], int Size);

int main() {
	const int SIZE = 20;
	int  firstArr[SIZE] = { 48,24,13,17,56,54,27,98,356,254, 73, 45, 67, 90,34,11,9,55, 45,18 };
	int  secondArr[SIZE] = { 84,42,31,71,65,45,72,82,536,247, 37, 53, 87, 0,349,11,111,595, 405,108 };

	std::cout << "\n \n ----------------- \n \n Bubble Sort  \n";
	printArray(firstArr, SIZE);
	std::cout << "\n -----------------\n";
	BubbleSort(firstArr, SIZE);

	std::cout << "\n \n ----------------- \n \n Selection Sort \n";
	printArray(secondArr, SIZE);
	std::cout << "\n -----------------\n";
	SelectionSort(secondArr, SIZE);
	std::cout << "\n";
	system("pause");
}

void BubbleSort(int arr[], int SIZE)
{
	int temp, swapCount = 0, pass = 0;
	bool swap;

	do
	{
		swap = false;

		for (int count = 0; count < (SIZE- 1); count++) {
			pass++;
			if (arr[count] > arr[count + 1])
			{
				temp = arr[count];
				arr[count] = arr[count + 1];
				arr[count + 1] = temp;
				swap = true;
				swapCount++;
				printArray(arr, SIZE);
			}
		}
	} while (swap);


	std::cout << "Swaps made: " << swapCount;
	std::cout << " \n Passes :" << pass;
}

void SelectionSort(int arr[], int SIZE)
{
	int startScan, minValue, minIndex;
	int  swapCount = 0, pass = 0;
	
	for (startScan  = 0; startScan < (SIZE - 1); startScan++)
	{
		pass++;
		minIndex = startScan;
		minValue = arr[startScan];

		for ( int index = 0; index < SIZE; index++)
		{
			if (arr[index] < minValue)
			{
				minValue = arr[index];
				minIndex = index;
				swapCount++;
			}
		}
		arr[minIndex] = arr[startScan];
		arr[startScan] = minValue;
		printArray(arr, SIZE);
	}
	std::cout << "Swaps made: " << swapCount;
	std::cout << " \n Passes :" << pass;
}

void printArray(int a[], int sz)
{
	
	for (int i = 0; i < sz; i++)
	{
		std::cout << "\t" << a[i];
	}
	std::cout << "\n \n ------------------------------------------------------------- \n";
}
