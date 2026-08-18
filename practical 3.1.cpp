#include <iostream>
using namespace std;


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        swap(arr[i], arr[min]);
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{

    int n = 5;
    int arr[n];

    cout<<"Enter elements of array"<<endl;


    for(int i=0;i<n;i++)
    {
cin>>arr[i];
    }



    int bubble[6], selection[6], insertion[6];


    for (int i = 0; i < n; i++)
    {
        bubble[i] = arr[i];
        selection[i] = arr[i];
        insertion[i] = arr[i];
    }

    bubbleSort(bubble, n);
    cout << "Bubble Sort: ";
    printArray(bubble, n);

    selectionSort(selection, n);
    cout << "Selection Sort: ";
    printArray(selection, n);

    insertionSort(insertion, n);
    cout << "Insertion Sort: ";
    printArray(insertion, n);

    return 0;
}
