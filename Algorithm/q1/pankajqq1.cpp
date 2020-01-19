#include <iostream>
#include <cstdlib>
using namespace std;
class sort
{
public:
	int l;
	int *ele;
	int countb, counti, counts, countm, countq;
	sort()
	{
		countb = 0, counti = 0, counts = 0, countm = 0, countq = 0;
	}
	void bubblesort(int[], int);
	void input(int q);
	void random(int n);
	void insertionsort(int[], int);
	int shiftval(int[], int);
	void selectionsort(int[], int);
	int extendsmall(int *ar, int pivot, int low, int highvac);
	int extendlarge(int *ar, int pivot, int lowvac, int high);
	int partition(int *ar, int pivot, int f, int l);
	void quicksort(int *ar, int f, int l);
	void mergesort(int ar[], int low, int high);
	void merge(int *a, int low, int high, int mid);
};
int main()
{
	sort s;
	int choice;
	s.random(0);
	char ch;
	do
	{
		cout << "Enter your choice among following " << endl;
		cout << "1. Bubble sort " << endl;
		cout << "2. Insertion sort " << endl;
		cout << "3. Selection sort " << endl;
		cout << "4. Quick Sort " << endl;
		cout << "5. Merge Sort " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			//	s.random(1);
			s.input(1);
			break;
		case 2:
			//	s.random(2);
			s.input(2);
			break;
		case 3:
			//	s.random(3);
			s.input(3);
			break;
		case 4:
			s.input(4);
			break;
		case 5:
			s.input(5);
			break;
		}
		cout << "If you wish to continue then press y " << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	return 0;
}
void sort::random(int n)
{
	int x = (rand() % 30) + 30;
	int *arr = new int[x];
	for (int i = 0; i < x; i++)
	{
		arr[i] = (rand() % 100) + 30;
	}
	l = x;
	ele = new int[l];
	for (int j = 0; j < x; j++)
		ele[j] = arr[j];
	cout << endl;
	for (int j = 0; j < x; j++)
		cout << arr[j] << "	";
	cout << endl;
	cout << "Number of elements " << x << endl
		 << endl;
	cout << "Bubble sort " << endl;
	bubblesort(arr, x);
	cout << "Insertion sort " << endl;
	for (int j = 0; j < x; j++)
		arr[j] = ele[j];
	insertionsort(arr, x);
	cout << "Selection sort " << endl;
	for (int j = 0; j < x; j++)
		arr[j] = ele[j];
	selectionsort(arr, x);
	cout << "Quick sort " << endl;
	for (int j = 0; j < x; j++)
		arr[j] = ele[j];
	quicksort(arr, 0, x - 1);
	cout << "Array after sorting " << endl;
	for (int i = 0; i < x; i++)
		cout << arr[i] << "	";
	cout << "Number of comparision " << countq << endl;
	cout << endl;

	cout << "Merge sort " << endl;
	mergesort(ele, 0, l - 1);
	cout << "Array after sorting " << endl;
	for (int i = 0; i < l; i++)
		cout << ele[i] << "	";
	cout << "Number of comparision " << countm << endl;
	cout << endl;
	//	if(n==1)
	//	bubblesort(arr,x);
	//	else if(n==2)
	//	insertionsort(arr,x);
	//	else if(n==3)
	//	selectionsort(arr,x);
}
void sort::input(int q)
{
	int x;
	cout << "Enter the limit of array " << endl;
	cin >> x;
	int *ar = new int[x];
	cout << "Enter the numbers of array :" << endl;
	for (int i = 0; i < x; i++)
	{
		cin >> ar[i];
	}
	if (q == 1)
		bubblesort(ar, x);
	else if (q == 2)
		insertionsort(ar, x);
	else if (q == 3)
		selectionsort(ar, x);
	else if (q == 4)
	{
		quicksort(ar, 0, x - 1);
		cout << "Array after sorting " << endl;
		for (int i = 0; i < x; i++)
			cout << ar[i] << "  ";
		cout << "Number of comparision " << countq << endl;
		cout << endl;
	}
	else if (q == 5)
	{
		mergesort(ar, 0, x - 1);
		cout << "Array after sorting " << endl;
		for (int i = 0; i < x; i++)
			cout << ar[i] << "  ";
		cout << "Number of comparision " << countm << endl;
		cout << endl;
	}
}
void sort::bubblesort(int arr[], int n)
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

void sort::insertionsort(int arr[], int n)
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

void sort::selectionsort(int arr[], int n)
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
		cout << arr[i] << "	";
	}
	cout << endl;
}

void sort::quicksort(int *ar, int f, int l)
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
int sort::partition(int *ar, int pivot, int f, int l)
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
int sort::extendlarge(int *ar, int pivot, int lowvac, int high)
{
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
int sort::extendsmall(int *ar, int pivot, int low, int highvac)
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

void sort::merge(int *a, int low, int high, int mid)
{
	countm = 0;
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
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i - low];
	}
}
void sort::mergesort(int ar[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(ar, low, mid);
		mergesort(ar, mid + 1, high);
		merge(ar, low, high, mid);
	}
}
