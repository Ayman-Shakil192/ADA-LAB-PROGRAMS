#include <iostream>
#include<time.h>
#include<dos.h>
#include<windows.h>

using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        Sleep(1);
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main()
{
    int i,n;
    clock_t start,finish;
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    int arr[n];
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        arr[i]=rand()%10000;
    }
    cout<<"Unsorted array:"<<endl;
    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
    start=clock();
    quickSort(arr,0,n-1);
    finish=clock();
    cout<<"\n\nSorted array:"<<endl;
    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl<<"Time taken :"<<((double)(finish-start))/CLK_TCK;

    return 0;
}