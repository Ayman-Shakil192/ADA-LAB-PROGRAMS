#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

using namespace std;

void selectionSort(int a[], int n)
{
    int min;
    for(int i=0;i<=n-2;i++)
    {
        min=i;
        for(int j=i+1;j<=n-1;j++)
        {
            Sleep(0.7);
            if(a[j]<a[min])
            min=j;
        }
        int t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
}

int main()
{
    clock_t start,endd;
    int a[100001],n;
    cout<<"Enter the array size:"<<endl;
    cin>>n;
    cout<<"\n\nEnter the array elements:"<<endl;

    for(int i=0; i<n;i++)
    {
        a[i]=rand()%1000;
        cout<<a[i]<<"\t";
    }
    
    start=clock();
    selectionSort(a,n);
    endd=clock();
    
    cout<<"\n\nThe array elements after sorting are:"<<endl;
    for(int i=0; i<n;i++)
    cout<<a[i]<<"\t";
    cout<<"\n\nTime taken: "<<((double)(endd-start))/CLOCKS_PER_SEC;
    return 0;
}
