#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    string a,b;
    int test,t;
    size_t found;
    cin>>test;
    while(test--)
    {
        cin>>a;
        cin>>t;
        while(t--)
        {
            cin>>b;
            found=a.find(b);
            if (found!=string::npos)
            cout<<"y"<<endl;
            else
            cout<<"n"<<endl;
        }
    }
    return 0;
}
