Q3.write a c++ program for perform Merge sort to sort the elements

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) 
{
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int *leftArr = new int[size1];
    int *rightArr = new int[size2];

    for (int i = 0; i < size1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < size2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0; 
    int k = left;    


    while (i < size1 && j < size2) 
    {
        if (leftArr[i] <= rightArr[j]) 
        {
            arr[k] = leftArr[i];
            i++;
        } 
        else 
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < size1) 
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < size2) 
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int start, int end) 
{
    if (start >= end) 
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    cout << "\nOriginal array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}

Output:

Enter the number of elements in the array: 10

Enter the elements of the array: 2 5 6 3 1 4 7 0 8 10

Original array: 10 2 5 6 3 1 4 7 0 8 

Sorted array: 0 1 2 3 4 5 6 7 8 1