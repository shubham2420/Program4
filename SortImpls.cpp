#include <iostream>
#include <vector>
#include <string>
#include <sys/time.h>
#include "SortImpls.h"

using namespace std;

void InitArray(vector<int>&, int);
void PrintArrayDetails(const vector<int>&, string);
int elapsed(timeval& startTime, timeval& endTime);

int main(int argc, char* argv[])
{
	int size = 0;
	string sort_name = "";
	bool printOut = true;
	if ((argc != 3) && (argc != 4))
	{
		cerr << "Usage: Sorter SORT_TYPE ARRAY_SIZE [YES|NO]" << endl;
		return -1;
	}
	sort_name = string(argv[1]);
	size = atoi(argv[2]);
	if (size <= 0)
	{
		cerr << "Array size must be positive" << endl;
		return -1;
	}
	if (argc == 4)
	{
		string printArr = string(argv[3]);
		if (printArr == "NO")
		{
			printOut = false;
		}
		else if (printArr == "YES")
		{
			printOut = true;
		}
		else
		{
			cerr << "Usage: Sorter SORT_TYPE ARRAY_SIZE [YES|NO]" << endl;
			return -1;
		}
	}
	srand(1);
	vector<int> items(size);
	InitArray(items, size);

	if (printOut)
	{
		cout << "Initial:" << endl;
		PrintArrayDetails(items, string("items"));
	}

	// GetTickCount is windows specific.
	// For linux use gettimeofday. As shown::
	struct timeval startTime, endTime;

	gettimeofday(&startTime, 0);

	SortImpls SortingStuff;
	if (sort_name == "BubbleSort")
	{
		SortingStuff.BubbleSort(items, size);
	}
	else if (sort_name == "InsertionSort")
	{
		SortingStuff.InsertionSort(items, size);
	}
	else if (sort_name == "MergeSort")
	{
		SortingStuff.MergeSort(items, 0, size - 1);
	}
	else if (sort_name == "IterativeMergeSort")
	{
		SortingStuff.IterativeMergeSort(items, size);
	}
	else if (sort_name == "QuickSort")
	{
		SortingStuff.QuickSort(items, 0, size - 1);
	}
	else if (sort_name == "ShellSort")
	{
		SortingStuff.ShellSort(items, size);
	}
	else
	{
		cout << "Unknown sorting name" << endl;
	}

	gettimeofday(&endTime, 0);

	if (printOut)
	{
		cout << "Sorted:" << endl;
		PrintArrayDetails(items, string("items"));
	}

	cout << "Time (microseconds): " << elapsed(startTime, endTime) << endl;
	return 0;
}

void InitArray(vector<int>& array, int randMax)
{
	if (randMax < 0)
	{
		return;
	}
	vector<int> pool(randMax);
	for (int i = 0; i < randMax; i++)
	{
		pool[i] = i;
	}
	int spot;
	for (int i = 0; i < randMax; i++)
	{
		spot = rand() % (pool.size());
		array[i] = pool[spot];
		pool.erase(pool.begin() + spot);
	}
}

void PrintArrayDetails(const vector<int>& array, string name)
{
	int size = array.size();
	for (int i = 0; i < size; i++)
		cout << name << "[" << i << "] = " << array[i] << endl;
}

// Function to calculate elapsed time if using gettimeofday (linux)
int elapsed(timeval& startTime, timeval& endTime)
{
	return (endTime.tv_sec - startTime.tv_sec) * 1000000
		+ (endTime.tv_usec - startTime.tv_usec);
}