#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

void floyds(int a[500][500],int n)
{
    for(int k=0;k<n;k++)
    {
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                Sleep(0.05);
                a[i][j]=a[i][j]<(a[i][k]+a[k][j])?a[i][j]:(a[i][k]+a[k][j]);
            }
        }
    }
    printf("\nFloyd's shortest path :");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%c%d\t",j==0?'\n':' ',a[i][j]);
        }
    }
}

int main()
{
    int a[500][500],n;
    clock_t s=0,e=0;
    printf("\nEnter the no of vertices : ");
    scanf("%d",&n);
    printf("\nThe adjacency matrix : \n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        a[i][j]=rand()%100+1;
        if(i==j)
        a[i][j]=0;
        printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    
    printf("\n\n");
    s=clock();
    floyds(a,n);
    e=clock();
    printf("\n\n");
    printf("Time taken to find shortest path using floyd's is %fs",(float)(e-s)/CLK_TCK);
    return 0;
}