#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

using namespace std;

void printArray(int *array, int n)
{
    for (int i = 0; i < n; ++i)
    cout<< array[i] <<endl;
}

void merge(int *array, int low, int mid, int high)
{
    int temp[high + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high)
    {
        Sleep(0.6);
        if (array[i] <= array[j])
        temp[k++] = array[i++];
        else
        temp[k++] = array[j++];
    }

    while (i <= mid)

    temp[k++] = array[i++];
    while (j <= high)
    temp[k++] = array[j++];
    k--;
    while (k >= 0)
    {
        array[k + low] = temp[k];
        k--;
    }
}
void mergeSort(int *array, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}
int main()
{
    int n,i;
    srand(time(NULL));
    cout<<"Enter the number of elements to be sorted: ";
    cin>>n;
    int a[n];
    cout<<"\nArray before sorting: ";
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100000;
        cout<<a[i]<<" ";
    }
    float start=clock();
    mergeSort(a,0,n-1);
    float end=clock();
    float timetaken=(((float)(end-start))/CLOCKS_PER_SEC)*10;
    cout<<endl<<"\n\nElements after sorting: ";

    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl<<"Time taken: "<<timetaken<<endl;
    return 0;
}