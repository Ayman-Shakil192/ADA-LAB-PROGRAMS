#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <windows.h>

using namespace std;

#define MAX 500
#define CLOCKS_PER_SEC 1000 

int t[MAX];
void shifttable(string p)
{
    int i, j, m;
    m = p.length();
    for (i = 0; i < MAX; i++)
        t[i] = m;
    for (j = 0; j < m - 1; j++)
        t[p[j]] = m - 1 - j;
}

int horspool(string str, string p)
{
    int i, j, k, m, n;
    n = str.length();
    m = p.length();
    printf("\nLength of text= %d", n);
    printf("\nLength of pattern= %d", m);
    i = m - 1;
    while (i < n)
    {
        k = 0;
        while ((k < m) && (p[m - 1 - k] == str[i - k]))
            k++;
        if (k == m)
            return (i - m + 1);
        else
            i += t[str[i]];
    }
    return -1;
}

int main()
{
    clock_t start,end;
    int pos,c;
    cout << "Reading from file :" << endl;

    string str,p;
    ifstream infile;
    infile.open("input.txt"); // taking file as input

    if(infile.fail())
    {
        cout << "Unable to open the file!" << endl; // throws exception if opening the file fails
    }
    else
    {
        while(getline(infile,str))
        {
            cout << str << endl;
            c += str.length();
        }
    }
    
    cout << "\nEnter the pattern to be searched: " << endl;
    getline(cin, p);

    start = clock();
    shifttable(p);
    pos = horspool(str, p);
    end = clock();

    if (pos >= 0)
        printf("\nThe desired pattern was found starting from position %d\n", pos + 1);
    else
        printf("\nThe pattern was not found in the given text\n");
        
    cout<<"\nTime taken: " << ((double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}