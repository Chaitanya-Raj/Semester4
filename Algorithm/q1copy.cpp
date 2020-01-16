#include <iostream>
#include <cstdlib>
using namespace std;
class sort
{
public:
	int arr[30];
	int size;
	int count;
	void input();
	void bubbleSort();
	void insertionSort();
	int shiftval(int);
	void selectionSort();
	sort()
	{
		size = 30;
		count = 0;
	}
} s;
int main()
{
	int choice;
	char ch;
	do
	{
		cout << "Enter your choice among following " << endl;
		cout << "1. bubble sort " << endl;
		cout << "2. insertion sort " << endl;
		cout << "3. selection sort " << endl;
		cin >> choice;

		for (int i = 0; i < s.size; i++)
			s.arr[i] = i + 1;

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

		cout << "\n\nAfter sort\n";
		for (int i = 0; i < s.size; i++)
			cout << "\t" << s.arr[i];

		cout << "\n\nNumber of comparisons : " << s.count << endl;

		int x = 30;
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
		cout << "\n\nAfter sort\n";
		for (int i = 0; i < s.size; i++)
			cout << "\t" << s.arr[i];

		cout << "\n\nNumber of comparisons : " << s.count << endl;

		cout << "\n\nRandom Cases\n";

		for (int j = 0; j < 8; j++)
		{
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

			cout << "\n\nAfter sort\n";
			for (int i = 0; i < s.size; i++)
				cout << "\t" << s.arr[i];

			cout << "\n\nNumber of comparisons : " << s.count << endl;
		}
		cout << "If you wish to continue then press y " << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	return 0;
}

void sort::bubbleSort()
{
	s.count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			s.count++;
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
	s.count = 0;
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
		s.count++;
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
	s.count = 0;
	int min;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			s.count++;
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
