#include <iostream>
//#include<conio.h>
#include <cstdlib>
using namespace std;
class sort
{
public:
	int count2, countq, countm;
	sort()
	{
		countm = 0;
	}
	void input();
	void input1();
	void input2();
	void bubble();
	void insertion();
	int shiftvac(int[], int);
	void selection();
	void bubblesort(int[], int);
	void insertionsort(int[], int);
	void selectionsort(int[], int);
	void mergef();
	void merge(int[], int, int, int);
	void mergesort(int[], int, int);
	void quick();
	void quicksort(int[], int, int);
	int partition(int[], int, int, int);
	int extendlarge(int[], int, int, int);
	int extendsmall(int[], int, int, int);
};
void sort::input()
{
	int a, b;
	char ch1;
	cout << "\n enter the size of array : ";
	cin >> a;
	int ar1[a];
	for (int i = 0; i < a; i++)
		cin >> ar1[i];
	for (int i = 0; i < a; i++)
		cout << " " << ar1[i];
	do
	{
		cout << "choose among sorting :";
		cout << "\n 1)bubble\n 2)selection\n 3)insertion\n 4)quicksort\n 5) mergesort : ";
		cin >> b;
		switch (b)
		{
		case 1:
			bubblesort(ar1, a);
			break;
		case 2:
			selectionsort(ar1, a);
			break;
		case 3:
			insertionsort(ar1, a);
			break;
		case 4:
			quicksort(ar1, 0, a - 1);
			cout << "\n size os array " << a << " \n";
			//cout<<"\n no. of comparison "<<count1<<"\n";
			for (int i = 0; i < a; i++)
				cout << ar1[i] << "  ";
			cout << "************************";
			break;
		case 5:
			mergesort(ar1, 0, a - 1);
			cout << "\n size os array " << a << " \n";
			cout << "\n no. of comparison " << countm << "\n";
			for (int i = 0; i < a; i++)
				cout << ar1[i] << "  ";
			cout << "************************";
			break;

		default:
			cout << "\n wrong entry ";
		}
		cout << "\n to continue : ";
		cin >> ch1;
	} while (ch1 == 'y' || ch1 == 'Y');
}
void sort::bubble()
{
	int x = (rand() % 30) + 30;
	int *ar = new int[x];
	for (int i = 0; i < x; i++)
	{
		ar[i] = rand() % 1000;
	}
	bubblesort(ar, x);
}
void sort::bubblesort(int arr[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			count++;
			if (arr[j] < arr[i])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << "\n size os array " << n;
	cout << "\n no. of comparison " << count << "\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";
	cout << "************************";
}
void sort::insertion()
{
	int x = (rand() % 30) + 30;
	int *ar = new int[x];
	for (int i = 0; i < x; i++)
	{
		ar[i] = rand() % 1000;
	}
	insertionsort(ar, x);
}
void sort::insertionsort(int ar2[], int n)
{
	int xloc, val;

	count2 = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		val = ar2[i];
		xloc = shiftvac(ar2, i);
		ar2[xloc] = val;
	}
	cout << "\n size os array " << n;
	cout << "\n no. of comparison " << count2 << "\n";
	for (int i = 0; i < n; i++)
		cout << ar2[i] << "  ";
	cout << "************************";
}
int sort::shiftvac(int arr[], int i)
{ //cout<<count2;
	int vacant = i, xloc = 0, m = arr[i];
	while (vacant > 0)
	{
		count2++;
		if (arr[vacant - 1] <= m)
		{
			xloc = vacant;
			break;
		}
		arr[vacant] = arr[vacant - 1];
		vacant--;
	}
	//cout<<count2;
	return xloc;
}
void sort::selection()
{
	int x = (rand() % 30) + 30;
	int *ar = new int[x];
	for (int i = 0; i < x; i++)
	{
		ar[i] = rand() % 1000;
	}
	selectionsort(ar, x);
}
void sort::selectionsort(int ar2[], int n)
{
	int min, count1 = 0;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			count1++;
			if (ar2[j] < ar2[min])
				min = j;
		}
		int temp = ar2[i];
		ar2[i] = ar2[min];
		ar2[min] = temp;
	}
	cout << "\n size os array " << n;
	cout << "\n no. of comparison " << count1 << "\n";
	for (int i = 0; i < n; i++)
		cout << ar2[i] << "  ";
	cout << "************************";
}
void sort::quick()
{
	int x = (rand() % 30) + 30;
	int *ar = new int[x];
	for (int i = 0; i < x; i++)
	{
		ar[i] = rand() % 1000;
	}
	quicksort(ar, 0, x - 1);
	cout << "\n size os array " << x << " \n";
	//cout<<"\n no. of comparison "<<count1<<"\n";
	for (int i = 0; i < x; i++)
		cout << ar[i] << "  ";
	cout << "************************";
}
void sort::quicksort(int ar[], int f, int l)
{
	int pivot;
	if (f < l)
	{
		pivot = ar[f];
		int spilit = partition(ar, pivot, f, l);
		ar[spilit] = pivot;
		quicksort(ar, f, spilit - 1);
		quicksort(ar, spilit + 1, l);
	}
}
int sort::partition(int ar[], int pivot, int f, int l)
{
	int low = f, high = l;
	while (low < high)
	{
		int highvac = extendlarge(ar, pivot, low, high);
		int lowvac = extendsmall(ar, pivot, low + 1, highvac);
		low = lowvac;
		high = highvac - 1;
	}
	return low;
}
int sort::extendlarge(int ar[], int pivot, int lowvac, int high)
{
	countq = 0;
	int highvac = lowvac, curr = high;
	while (curr > lowvac)
	{
		countq++;
		if (ar[curr] < pivot)
		{
			ar[lowvac] = ar[curr];
			highvac = curr;
			break;
		}
		curr--;
	}
	return highvac;
}
int sort::extendsmall(int ar[], int pivot, int low, int highvac)
{
	int lowvac = highvac, curr = low;
	while (curr < highvac)
	{
		countq++;
		if (ar[curr] >= pivot)
		{
			ar[highvac] = ar[curr];
			lowvac = curr;
			break;
		}
		curr++;
	}
	return lowvac;
}
void sort::mergef()
{
	int x = (rand() % 30) + 30;
	int *ar = new int[x];
	for (int i = 0; i < x; i++)
	{
		ar[i] = rand() % 1000;
	}
	mergesort(ar, 0, x - 1);
	cout << "\n size os array " << x << " \n";
	cout << "\n no. of comparison " << countm << "\n";
	for (int i = 0; i < x; i++)
		cout << ar[i] << "  ";
	cout << "************************";
}
void sort::merge(int a[], int low, int high, int mid)
{
	int i, j, k, temp[high - low + 1];
	i = low;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			countm++;
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			countm++;
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{ //countm++;
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{ //countm++;
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i - low];
	}
}
void sort::mergesort(int a[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(a, low, mid);
		mergesort(a, mid + 1, high);
		merge(a, low, high, mid);
	}
}
int main()
{
	sort ob;
	int choice;
	char ch;
	do
	{
		cout << "\n ******choose among the following *******";
		cout << "\n1)bubble sort "
			 << "\n2)insertion sort "
			 << "\n3)selection sort \n4)quicksort \n 5)mergesort : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			for (int i = 0; i < 8; i++)
				ob.bubble();
			for (int k = 0; k < 2; k++)
				ob.input();
			break;
		case 2:
			for (int i = 0; i < 8; i++)
				ob.insertion();
			for (int k = 0; k < 2; k++)
				ob.input();
			break;
		case 3:
			for (int i = 0; i < 8; i++)
				ob.selection();
			for (int i = 0; i < 2; i++)
				ob.input();
			break;
		case 4:
			for (int i = 0; i < 8; i++)
				ob.quick();
			for (int i = 0; i < 2; i++)
				ob.input();
			break;
		case 5:
			for (int i = 0; i < 8; i++)
				ob.mergef();
			for (int i = 0; i < 2; i++)
				ob.input();
			break;
		default:
			cout << "\n this is wrong entry ";
		}
		cout << "\n do u want to continue ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	//getch();
	return 0;
}
