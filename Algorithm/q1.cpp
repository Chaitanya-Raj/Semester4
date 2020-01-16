#include <iostream>
#include <cstdlib>
using namespace std;
class sort
{
public:
	int countb, counti, counts;
	void bubbleSort(int[], int);
	void input(int q);
	void random(int n);
	void insertionSort(int[], int);
	int shiftval(int[], int);
	void selectionSort(int[], int);
	void partition();
};
int main()
{
	sort s;
	int choice;
	char ch;
	do
	{
		cout << "Enter your choice among following " << endl;
		cout << "1. bubble sort " << endl;
		cout << "2. insertion sort " << endl;
		cout << "3. selection sort " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			for (int i = 0; i < 8; i++)
				s.random(1);
			cout << endl;
			cout << "Enter the elements of array in best and worst case " << endl;
			for (int i = 0; i < 2; i++)
				s.input(1);
			break;
		case 2:
			for (int i = 0; i < 8; i++)
				s.random(2);
			cout << "Enter the elements of array in best and worst case " << endl;
			for (int i = 0; i < 2; i++)
				s.input(2);
			break;
		case 3:
			for (int i = 0; i < 8; i++)
				s.random(3);
			cout << "Enter the elements of array in best and worst case " << endl;
			for (int i = 0; i < 2; i++)
				s.input(3);
			break;
		}
		cout << "If you wish to continue then press y " << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	getch();
	return 0;
}
void sort::random(int n)
{
	int x = 30;
	int arr[x];
	for (int i = 0; i < x; i++)
	{
		arr[i] = (rand() % 100) + 30;
	}
	if (n == 1)
		bubbleSort(arr, x);
	else if (n == 2)
		insertionSort(arr, x);
	else if (n == 3)
		selectionSort(arr, x);
}
void sort::input(int q)
{
	int x;
	cout << "Enter the limit of array " << endl;
	cin >> x;
	int ar[x];
	cout << "Enter the numbers of array :" << endl;
	for (int i = 0; i < x; i++)
	{
		cin >> ar[i];
	}

	if (q == 1)
		bubbleSort(ar, x);
	else if (q == 2)
		insertionSort(ar, x);
	else
		selectionSort(ar, x);
}
void sort::bubbleSort(int arr[], int n)
{
	int countb = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			countb++;
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << "No of elements is array " << n << endl;
	cout << "Number of comparision " << countb << endl;
	cout << "Bubble sort " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "	 ";
	}
	cout << endl;
}

void sort::insertionSort(int arr[], int n)
{
	int xloc;
	counti = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		int curr = arr[i];
		xloc = shiftval(arr, i);
		arr[xloc] = curr;
	}
	cout << "Number of comparision " << counti << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "	 ";
	}
	cout << endl;
}

int sort::shiftval(int arr[], int n)
{
	int vacant = n;
	int loc = 0, m = arr[n];
	while (vacant > 0)
	{
		counti++;
		if (arr[vacant - 1] <= m)
		{
			loc = vacant;
			break;
		}
		arr[vacant] = arr[vacant - 1];
		vacant--;
	}
	return loc;
}

void sort::selectionSort(int arr[], int n)
{
	int min;
	counts = 0;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			counts++;
			if (arr[j] < arr[min])
			{
				min = j;
			}
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}

	cout << "Number of comparision " << counts << endl;
	cout << "Array after bubble sort " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}
