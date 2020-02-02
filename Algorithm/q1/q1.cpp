#include <iostream>
#include <cstdlib>
using namespace std;

class sort
{
public:
	int *arr;
	int size;
	int count;
	void input();
	void bubbleSort();
	void insertionSort();
	int shiftval(int);
	void selectionSort();
	int extendLargeRegion(int[], int, int, int);
	int extendSmallRegion(int[], int, int, int);
	int partition(int[], int, int, int);
	void quickSort(int[], int, int);
	void merge(int[], int, int, int);
	void mergeSort(int[], int, int);
	void generate(int[], int, int);
	void swap(int[], int, int);
	sort()
	{
		count = 0;
	}
} s;

int main()
{
	int casechoice, choice;
	char ch;
	do
	{
		cout << "Enter the size of array :";
		cin >> s.size;
		s.arr = new int[s.size];
		cout << "Enter your choice among following " << endl;
		cout << "1. bubble sort " << endl;
		cout << "2. insertion sort " << endl;
		cout << "3. selection sort " << endl;
		cout << "4. quick sort " << endl;
		cout << "5. merge sort " << endl;
		cin >> choice;

		cout << "\n\nWhich case do you want to see:" << endl;
		cout << "1. Best Case" << endl;
		cout << "2. Worst Case" << endl;
		cout << "3. Average Case" << endl;
		cin >> casechoice;

		int x = s.size;

		switch (casechoice)
		{
		case 1:
			for (int i = 0; i < s.size; i++)
				s.arr[i] = i + 1;
			if (choice == 4)
			{
				s.generate(s.arr, 0, s.size - 1);
				for (int i = 0; i < s.size; i++)
					cout << s.arr[i];
			}

			cout << "\n\nBest Case\n";
			cout << "\n\nBefore sort\n";
			for (int i = 0; i < s.size; i++)
				cout << "\t" << s.arr[i];

			if (choice == 1)
				s.bubbleSort();
			else if (choice == 2)
				s.insertionSort();
			else if (choice == 3)
				s.selectionSort();
			else if (choice == 4)
			{
				s.count = 0;
				s.quickSort(s.arr, 0, s.size - 1);
			}
			else if (choice == 5)
			{
				s.count = 0;
				s.mergeSort(s.arr, 0, s.size - 1);
			}

			cout << "\n\nAfter sort\n";
			for (int i = 0; i < s.size; i++)
				cout << "\t" << s.arr[i];

			cout << "\n\nNumber of comparisons : " << s.count << endl;

			break;

		case 2:
			for (int i = 0; i < s.size; i++)
				s.arr[i] = x--;

			cout << "\n\nWorst Case\n";
			cout << "\n\nBefore sort\n";
			for (int i = 0; i < s.size; i++)
				cout << "\t" << s.arr[i];

			if (choice == 1)
				s.bubbleSort();
			else if (choice == 2)
				s.insertionSort();
			else if (choice == 3)
				s.selectionSort();
			else if (choice == 4)
			{
				s.count = 0;
				s.quickSort(s.arr, 0, s.size - 1);
			}
			else if (choice == 5)
			{
				s.count = 0;
				s.mergeSort(s.arr, 0, s.size - 1);
			}

			cout << "\n\nAfter sort\n";
			for (int i = 0; i < s.size; i++)
				cout << "\t" << s.arr[i];

			cout << "\n\nNumber of comparisons : " << s.count << endl;

			break;

		case 3:
			cout << "\n\nRandom Case\n";
			s.count = 0;
			for (int i = 0; i < s.size; i++)
			{
				s.arr[i] = (rand() % 100) + 20;
			}
			cout << "\n\nBefore sort\n";
			for (int i = 0; i < s.size; i++)
				cout << "\t" << s.arr[i];

			if (choice == 1)
				s.bubbleSort();
			else if (choice == 2)
				s.insertionSort();
			else if (choice == 3)
				s.selectionSort();
			else if (choice == 4)
			{
				s.count = 0;
				s.quickSort(s.arr, 0, s.size - 1);
			}
			else if (choice == 5)
			{
				s.count = 0;
				s.mergeSort(s.arr, 0, s.size - 1);
			}

			cout << "\n\nAfter sort\n";
			for (int i = 0; i < s.size; i++)
				cout << "\t" << s.arr[i];

			cout << "\n\nNumber of comparisons : " << s.count << endl;

			break;

		default:
			cout << "invalid choice";
		}
		cout << "If you wish to continue then press y " << endl;
		cin >> ch;
		cout << "\n\n";
	} while (ch == 'y' || ch == 'Y');
	return 0;
}

void sort::bubbleSort()
{
	count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			count++;
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void sort::insertionSort()
{
	count = 0;
	int xloc;
	for (int i = 1; i <= size - 1; i++)
	{
		int curr = arr[i];
		xloc = shiftval(i);
		arr[xloc] = curr;
	}
}

int sort::shiftval(int n)
{
	int vacant = n;
	int loc = 0, m = arr[n];
	while (vacant > 0)
	{
		count++;
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

void sort::selectionSort()
{
	count = 0;
	int min;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			count++;
			if (arr[j] < arr[min])
			{
				min = j;
			}
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

int sort::extendLargeRegion(int E[], int pivot, int lowVac, int high)
{
	int highVac, curr;
	highVac = lowVac;
	curr = high;
	while (curr > lowVac)
	{
		count++;
		if (E[curr] < pivot)
		{
			E[lowVac] = E[curr];
			highVac = curr;
			break;
		}
		curr--;
	}
	return highVac;
}

int sort::extendSmallRegion(int E[], int pivot, int low, int highVac)
{
	int lowVac, curr;
	lowVac = highVac;
	curr = low;
	while (curr < highVac)
	{
		count++;
		if (E[curr] >= pivot)
		{
			E[highVac] = E[curr];
			lowVac = curr;
			break;
		}
		curr++;
	}
	return lowVac;
}

int sort::partition(int E[], int pivot, int first, int last)
{
	int low, high;
	low = first;
	high = last;
	while (low < high)
	{

		int highVac = extendLargeRegion(E, pivot, low, high);
		int lowVac = extendSmallRegion(E, pivot, low + 1, highVac);
		low = lowVac;
		high = highVac - 1;
	}
	return low;
}

void sort::quickSort(int E[], int first, int last)
{
	int pivot;
	if (first < last)
	{
		pivot = E[first];
		int splitpt = partition(E, pivot, first, last);
		E[splitpt] = pivot;
		quickSort(E, first, splitpt - 1);
		quickSort(E, splitpt + 1, last);
	}
}

void sort::generate(int arr[], int start, int end)
{
	int c = end - start;
	if (c < 3)
		return;
	int mid = (start + end) / 2;
	generate(arr, start, mid);
	swap(arr, start, mid);
	generate(arr, ++mid, end);
}

void sort::swap(int arr[], int i, int j)
{
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void sort::merge(int a[], int low, int high, int mid)
{
	count = 0;
	int i, j, k, temp[high - low + 1];
	i = low;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		count++;
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		count++;
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		count++;
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i - low];
	}
}
void sort::mergeSort(int a[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergeSort(a, low, mid);
		mergeSort(a, mid + 1, high);
		merge(a, low, high, mid);
	}
}