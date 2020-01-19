#include <iostream>
using namespace std;

int count = 0;

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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

    BubbleSort(arr, size);

    cout << "\n\nAfter sort\n";
    for (int i = 0; i < size; i++)
        cout << "\t" << arr[i];

    cout << "\n\nNumber of comparisons : " << count << endl;

    return 0;
}