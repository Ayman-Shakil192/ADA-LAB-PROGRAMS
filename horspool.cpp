#include<iostream>
#include<time.h>
#include<unistd.h>
# define NO_OF_CHARS 256

using namespace std;

void badCharHeuristic( string str, int size,int badchar[NO_OF_CHARS])
{
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
    badchar[i] = -1;
    for (i = 0; i < size; i++)
    badchar[(int) str[i]] = i;
}

void search( string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();
    int i = 0;
    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar);
    int s = 0;
    while(s <= (n - m))
    {
        int j = m - 1;
        sleep(0.5);
        while(j >= 0 && pat[j] == txt[s + j])
        j--;
        if (j < 0)
        {
            cout << "\npattern occurs at index = " << s << endl;
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;
            break;
        }
        else
        s += max(1, j - badchar[txt[s + j]]);
        if(s >= (n-m))
        {
            cout<<"\nPattern not found"<<endl;
            break;
        }
    }
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
    clock_t start,endd;
    int t1,p1;
    string t,p;
    cout<<"Enter the text length : ";
    cin>>t1;
    t=randomstring(t1);
    cout<<"\nText = "<<t<<endl;
    cout<<"\nEnter the pattern to be searched : ";
    cin>>p;
    start=clock();
    search(t,p);
    endd=clock();
    cout<<"\ntime taken: "<<((float)(endd-start)/CLOCKS_PER_SEC);
    return 0;
}