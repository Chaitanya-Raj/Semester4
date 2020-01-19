#include<iostream>
#include<cstdlib>
using namespace std;
class sort
{
	public:
		int n,x,countb,counti,counts,countq,countm;
		int *arr,*arr1;
		sort()
		{ countb=0,counti=0,counts=0,countm=0,countq=0;}
		void input(int s);
		void display(int [],int);
		void displayrand();
		void random();
		void bubblesort(int [],int );
		void insertion(int [],int);
		int shiftval(int [],int);
		void selectionsort(int [],int);
		void mergesort(int [],int,int);
		void merge(int *,int ,int ,int);
		void quicksort(int *,int f,int l);
		int partition(int *ar,int pivot,int f,int l);
		int extendlarge(int *ar,int pivot,int lowvac,int high);
		int extendsmall(int *ar,int pivot,int low,int highvac);
};
void sort::input(int s)
{
	cout<<"Enter the limit of array "<<endl;
	cin>>n;
	arr=new int[n];
	cout<<"Enter the elements of array "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int v=x;
	int array[v];
	if(s==1)
	{
		for(int i=0;i<v;i++)
		array[i]=arr1[i];
		bubblesort(arr,n);
		cout<<"Number of comparision "<<countb<<endl;
		bubblesort(array,v);
		cout<<"Number of comparision "<<countb<<endl;
	}
	else if(s==2)
	{	int array1[v];
		for(int i=0;i<v;i++)
		array1[i]=arr1[i];
		insertion(arr,n);
		cout<<"Number of comparision "<<counti<<endl;
		insertion(array1,v);
		cout<<"Number of comparision "<<counti<<endl;
	}
	else if(s==3)
	{	
		for(int i=0;i<v;i++)
		array[i]=arr1[i];
		selectionsort(arr,n);
		cout<<"Number of comparision "<<counts<<endl;
		selectionsort(array,v);
		cout<<"Number of comparision "<<counts<<endl;
	}
	else if(s==4)
	{
		for(int i=0;i<v;i++)
		array[i]=arr1[i];
		quicksort(arr,0,n-1);
		cout<<"Number of elements "<<n<<endl;
		cout<<"\nArray after sorting "<<endl;
		for(int i=0;i<n;i++)
			cout<<arr[i]<<"  ";
		cout<<endl;
		cout<<"Number of comparision "<<countq<<endl;
//		quicksort(array,0,v-1);
//		display(array,v);
//		cout<<"Number of comparision "<<countq<<endl;
	}
	else
	{
		for(int i=0;i<v;i++)
		array[i]=arr1[i];
		mergesort(arr,0,n-1);
		 cout<<"Number of elements "<<n<<endl;
		cout<<"\nArray after sorting "<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<"  ";
		}
		cout<<endl;
		cout<<"Number of comparision "<<countm<<endl;
		mergesort(array,0,v-1);
		 cout<<"Number of elements "<<v<<endl;
		cout<<"\nArray after sorting "<<endl;
		for(int i=0;i<v;i++)
		{
			cout<<array[i]<<"  ";
		}
		cout<<endl;
		cout<<"Number of comparision "<<countm<<endl;
	}
	
}
void sort::display(int arrr[],int b)
{
	cout<<"Number of elements "<<b<<endl;
	cout<<"Array after sorting "<<endl;
	for(int i=0;i<b;i++)
	{
		cout<<arrr[i]<<"  ";
	}
	cout<<endl;
}
void sort::random()
{
	x=(rand()%30)+30;
	arr1=new int[x];
	for(int i=0;i<x;i++)
	{
		arr1[i]=(rand()%100)+30;
	}
}
void sort::bubblesort(int ar[],int m)
{
	countb=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m-i-1;j++)
		{	countb++;
			if(ar[j]>ar[j+1])
			{
				int temp=ar[j+1];
				ar[j+1]=ar[j];
				ar[j]=temp;
			}
		}
	}
	cout<<"Number of elements "<<m<<endl;
	cout<<"\nArray after sorting "<<endl;
	for(int i=0;i<m;i++)
	{
		cout<<ar[i]<<"  ";
	}
	cout<<endl;
}
void sort::insertion(int ar[],int m)
{	counti=0;
	int xloc;
	for(int i=1;i<=m-1;i++)
	{
		int curr=ar[i];
		xloc=shiftval(ar,i);
		ar[xloc]=curr;
	}
	cout<<"Number of elements "<<m<<endl;
	cout<<"\nArray after sorting "<<endl;
	for(int i=0;i<m;i++)
	{
		cout<<ar[i]<<"  ";
	}
	cout<<endl;
}

int sort::shiftval(int ar[],int a)
{
	int vacant=a;
	int loc=0,m=ar[a];
	while(vacant>0)
	{	counti++;
		if(ar[vacant-1]<=m)
		{	
			loc=vacant;
			break;
		}
		ar[vacant]=ar[vacant-1];
		vacant--;
	}
	return loc;
}

void sort::selectionsort(int ar[],int m)
{	counts=0;
	int min;
	for(int i=0;i<m-1;i++)
	{
		min=i;
		for(int j=i+1;j<m;j++)
		{	counts++;
			if(ar[j]<ar[min])
			{
				min=j;
			}
		}
		int temp=ar[i];
		ar[i]=ar[min];
		ar[min]=temp;
	}
	cout<<"Number of elements "<<m<<endl;
	cout<<"\nArray after sorting "<<endl;
	for(int i=0;i<m;i++)
		cout<<ar[i]<<"  ";
	cout<<endl;
}

void sort::merge(int *a,int low,int high,int mid)
{
	countm=0;
	int i,j,k,temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= high)
	{	countm++;
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{	countm++;
		temp[k] = a[i];
		k++;i++;
	}
	while (j <= high)
	{	countm++;
		temp[k] = a[j];
		k++;j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
void sort::mergesort(int ar[],int low,int high)
{
  int mid;
  if (low < high)
  {
	mid=(low+high)/2;
	mergesort(ar,low, mid);
	mergesort(ar,mid+1, high);
	merge(ar, low, high, mid);
  }
}

void sort::quicksort(int *ar,int f,int l)
{
	int pivot;
	if(f<l)
	{
		pivot=arr[f];
		int spilit=partition(ar,pivot,f,l);
		arr[spilit]=pivot; 
		quicksort(ar,f,spilit-1);
		quicksort(ar,spilit+1,l);  
	}
	
}
int sort::partition(int *ar,int pivot,int f,int l)
{
	int low=f,high=l;
	while(low<high)
	{	countq++;
		int highvac=extendlarge(ar,pivot,low,high);
		int lowvac=extendsmall(ar,pivot,low+1,highvac);
		low=lowvac;
		high=highvac-1;		
	}
	return low;
}
int sort:: extendlarge(int *ar,int pivot,int lowvac,int high)
{
	int highvac=lowvac,curr=high;
	while(curr>lowvac)
	{
		if(ar[curr]<pivot)
		{
			ar[lowvac]=ar[curr];
			highvac=curr;
			break;
		}
		curr--;
	}
	return highvac;
}
int sort::extendsmall(int *ar,int pivot,int low,int highvac)
{
	int lowvac=highvac,curr=low;
	while(curr<highvac)
	{
		if(ar[curr]>=pivot)
		{
			ar[highvac]=ar[curr];
			lowvac=curr;
			break;
		}
		curr++;
	}
	return lowvac;
}

int main()
{
	int j;
	sort ob;
	ob.random();
	char ch;
	do
	{
		cout<<"Enter Which Sorting Algorithm You Want To Perform "<<endl;
		cout<<"1. Bubble Sort "<<endl<<"2. Insertion Sort "<<endl<<"3. Selection Sort "<<endl<<"4. Quick Sort "<<endl<<"5. Merge Sort ";
		cout<<endl;
		cin>>j;
		switch(j)
		{
			case 1:
				ob.input(1);
				break;
			case 2:
				ob.input(2);
				break;
			case 3:
				ob.input(3);
				break;
			case 4:
				ob.input(4);
				break;
			case 5:
				ob.input(5);
				break;
		}
		cout<<"Press y to continue "<<endl;
		cin>>ch;
	}while(ch=='Y' || ch=='y');
	return 0;
}
