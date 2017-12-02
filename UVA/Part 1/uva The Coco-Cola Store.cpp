#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    int a;
    while(cin>>a)
    {
        if(a==0)
        break;
        else
        cout<<a/2<<endl;
    }
    return 0;
}
