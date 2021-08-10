#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>

int bfs(int n,int a[600][600],int source,int s[600])
{
    int q[600],f=0,r=0,u,i;
    q[r]=source;
    s[source]=1;
    printf("The BFS sequence is %d ->",source);
    while(f<=r)
    {
        u=q[f];
        f=f+1;
        Sleep(0.5);
        for(i=0;i<n;i++)
        {
            Sleep(0.5);
            if(s[i]==0&&a[u][i]==1)
            {
                r=r+1;
                q[r]=i;
                s[i]=1;
                printf(" %d ->",i);
            }
        }
    }
    return 0;
}

int main()
{
    clock_t start,end;
    int n,a[600][600],i,j,source,s[600];
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("The adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)

        {
            a[i][j]=rand()%2;
            printf("%d\t",a[i][j]);
        }
    }
    printf("\nEnter the source\n");
    scanf("%d",&source);

    for(i=0;i<n;i++)
    {
        s[i]=0;
    }

    start = clock();
    bfs (n,a,source,s);
    end = clock();
    printf("\n");
    printf("Time taken is %f",(float)(end-start)/CLOCKS_PER_SEC);
    return 0;
}