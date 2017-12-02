#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
    double n,a,i,result;
    while(cin>>n>>a)
    {
        result=0;
        for(i=1;i<=n;i++)
        {
            cout<<i*pow(a,i)<<endl;
            result+=i*pow(a,i);
        }
        cout<<result<<endl;
    }
    return 0;
}
