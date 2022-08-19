#include <iostream>
using namespace std;

void printArray (int n, int arr[]){
    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void inputArray(int n, int* arr) {
    for(int i = 0; i<n; i++)
    {
        cin >> *(arr + i);
    }
}

void bubbleSortArray (int n, int arr[])
{
    int i, j;
    for(i = 0; i<n; i++)
    {
        for(j = 0; j< n- i - 1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSortArray (int n, int arr[])
{
    int i, j;
    for(i = 0; i<n; i++)
    {
        int min = i;
        for(j = i; j< n; j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }

            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main()
{
    cout << "Enter size of array - \n";
    int n;
    cin >> n;
    cout << "Enter array elements - \n";
    int arr[n];

    inputArray(n, arr);
    printArray(n, arr);

    cout << "Array after BUBBLE SORTING -> ";
    selectionSortArray(n, arr);
    printArray(n, arr);
}
