#include <iostream>
using namespace std;

int count = 0;

int ShiftVac(int E[], int index, int current)
{
	int vacant = index, xloc = 0;
	while (vacant > 0)
	{
		count++;
		if (E[vacant - 1] <= current)
		{
			xloc = vacant;
			break;
		}
		E[vacant] = E[vacant - 1];
		vacant--;
	}
	return xloc;
}

void InsertionSort(int E[], int n)
{
	int xloc;
	for (int i = 1; i < n; i++)
	{
		int current = E[i];
		xloc = ShiftVac(E, i, current);
		E[xloc] = current;
	}
	return;
}

int main()
{
	int size;
	cout << "\nEnter size of array : ";
	cin >> size;

	int arr[size];
	cout << "\nEnter elements : \n";
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	cout << "\n\nBefore sort\n";
	for (int i = 0; i < size; i++)
		cout << "\t" << arr[i];

	InsertionSort(arr, size);

	cout << "\n\nAfter sort\n";
	for (int i = 0; i < size; i++)
		cout << "\t" << arr[i];

	cout << "\n\nNumber of comparisons : " << count << endl;

	return 0;
}