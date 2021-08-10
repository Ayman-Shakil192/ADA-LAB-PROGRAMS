#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

int temp;

void heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < size && arr[left] >arr[largest])
    largest = left;
    if (right < size && arr[right] > arr[largest])
    largest = right;
    if (largest != i)
    {
        temp = arr[i];
        arr[i]= arr[largest];
        arr[largest] = temp;
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
    heapify(arr, size, i);
    for (i=size-1; i>=0; i--)
    {
        Sleep(1);
        temp = arr[0];
        arr[0]= arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main()
{
    clock_t s=0,e=0;
    int no;
    printf("\nEnter no of elements in an array:");
    scanf("%d", &no);
    int heap[no];
    printf("\nEnter the elements of an array : ");

    for (int i = 0; i < no; i++)
    {
        heap[i]=rand()%1000;
    }
    for (int i = 0; i < no; i++)
    {
        printf("%d\t",heap[i]);
    }

    int c;
    s=clock();
    heapSort(heap,no);
    e=clock();
    printf("\n\nThe sorted array is : ");
    for (int i = 0; i < no; i++)
    {
        printf(" %d\t", heap[i]);
    }
    printf("\n\n");
    printf("Time taken to sort the arrray is %f sec\t",(double)((e-s)/CLK_TCK));
}