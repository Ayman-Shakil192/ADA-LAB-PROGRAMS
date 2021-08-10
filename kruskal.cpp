#include <bits/stdc++.h>
#include<time.h>

using namespace std;

class Edge
{
    public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2) {
    return e1.weight<e2.weight;
}

int findParent(int v, int *parent)
{
    if(parent[v] == v)
    {
    return v;
    }
    return findParent(parent[v], parent);
}

void krushkals1(Edge *input, int n, int E) 
{
//sort the input array in ascending order
    sort(input, input+E, compare);
    Edge *output= new Edge[n-1];
    int *parent=new int[n];

    for(int i=0;i<n;i++)
    {
    parent[i]=i;
    }

    int count = 0;
    int i =0;
    while(count!=n-1)
    {
        Edge currentEdge = input[i];
        //check if we can add the current edge to mst
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);
        if(sourceParent != destParent)
        {
            output[count] = currentEdge;
            count++;
            parent[sourceParent]=destParent;
        }
        
        i++;
    }

    cout<<"After krushkals algorithm :"<<endl;
    for(int i=0; i<n-1;i++) 
    {
        if(output[i].source<output[i].dest)
        {
            cout<< output[i].source<<"-"<<output[i].dest<<"-" <<output[i].weight<<endl;
        }      
        else
        {
            cout<< output[i].dest<<" "<<output[i].source<<" " <<output[i].weight<<endl;
        }
    }
}
int main() 
{
    int n, E;
    clock_t end,start;
    cout<<"Enter the number of vertices :"<<endl;
    cin>>n;
    E=((n-1)*n)/2;
    cout<<"Number of edges= "<<E<<endl;
    Edge *input = new Edge[E];
    cout<<"The source - destination - weight of the edges in the graph is: "<<endl;

    int e=0;
    for(int i=1; i<=n-1;i++) {
        for(int j=i+1;j<=n;j++)
        {
            input[e].source=i;
            input[e].dest=j;
            input[e].weight=rand()%10;
            cout<<input[e].source<<"-"<<input[e].dest<<"-"<<input[e].weight<<endl;
            e++;
        }
    }
    cout<<endl<<endl;
    start = clock();
    krushkals1(input, n, E);
    end = clock();
    cout<<"\ntime taken: "<<((double)(end-start)/CLK_TCK);
}