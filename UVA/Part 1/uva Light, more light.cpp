#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main ()
{
    long long int a,n;
    while(cin>>n)
    {
        if(n==0)
        break;
        a=sqrt(n);
        if((a*a)==n)
        cout<<"yes"<<endl;
        else
        cout<<"no"<<endl;
    }
    return 0;
}
