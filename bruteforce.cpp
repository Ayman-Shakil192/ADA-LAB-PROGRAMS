#include<iostream>
#include<time.h>
#include<dos.h>
#include<windows.h>
#include <string.h>

using namespace std;

int BFSM(string t,string p)
{
    int n=t.length();
    int m=p.length();
    for(int i=0;i<=n-m;i++)
    {
        int j=0;

        Sleep(0.5);
        while(j<m && p[j]==t[i+j])
        {
            j=j+1;
            if(j==m)
            return i;
        }
    }
    return -1;
    }
string randomstring(int n)
{
    srand(time(NULL));
    string s="";

    for(int i=0;i<n;i++)
    {
        char c =(rand()%26)+97;
        s += c;
    }
    return s;
}

int main()
{
    clock_t start,end;
    int t1,p1;
    string t,p;
    cout<<"Enter the text length : ";
    cin>>t1;
    t=randomstring(t1);
    cout<<"\nText = "<<t<<endl;
    cout<<"Enter the pattern to be searched : ";
    //p= t.substr((t1/2), (t1/2)+5); //for average case
    cin>>p;
    start=clock();
    int i=BFSM(t,p);
    end=clock();
    if(i==-1)
    cout<<"\nPattern not found"<<endl;
    else
    cout<<"\nPattern found at index "<<i<<endl;
    cout<<"\ntime taken: "<<((double)(end-start)/CLK_TCK);
    return 0;
}