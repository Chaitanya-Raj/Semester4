#include <iostream>
#include <cstdlib>
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
	int size = 30;
	// cout << "\nEnter size of array : ";
	// cin >> size;

	int arr[size];
	//cout << "\nEnter elements : \n";
	for (int i = 0; i < size; i++)
		arr[i] = i + 1;

	cout << "\n\nBest Case\n";
	cout << "\n\nBefore sort\n";
	for (int i = 0; i < size; i++)
		cout << "\t" << arr[i];

	InsertionSort(arr, size);

	cout << "\n\nAfter sort\n";
	for (int i = 0; i < size; i++)
		cout << "\t" << arr[i];

	cout << "\n\nNumber of comparisons : " << count << endl;

	count = 0;

	int ar[30];
	int x = 30;
	for (int i = 0; i < size; i++)
		ar[i] = x--;

	cout << "\n\nWorst Case\n";
	cout << "\n\nBefore sort\n";
	for (int i = 0; i < size; i++)
		cout << "\t" << ar[i];

	InsertionSort(ar, size);

	cout << "\n\nAfter sort\n";
	for (int i = 0; i < size; i++)
		cout << "\t" << ar[i];

	cout << "\n\nNumber of comparisons : " << count << endl;

	cout << "\n\nRandom Cases\n";

	for (int j = 0; j < 8; j++)
	{
		count = 0;
		int x = 30;
		int a[x];
		for (int i = 0; i < x; i++)
		{
			a[i] = (rand() % 100) + 20;
		}
		cout << "\n\nBefore sort\n";
		for (int i = 0; i < size; i++)
			cout << "\t" << a[i];

		InsertionSort(a, size);

		cout << "\n\nAfter sort\n";
		for (int i = 0; i < size; i++)
			cout << "\t" << a[i];

		cout << "\n\nNumber of comparisons : " << count << endl;
	}

	return 0;
}