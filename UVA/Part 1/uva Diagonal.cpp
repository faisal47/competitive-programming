#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
    int t=1;
    double n,a;
    long long b;
    while(cin>>n)
    {
        if(n==0)
        break;
       // a=(n-3)/2;
        a=(sqrt((8.*n)+9.)+3.)/2.;
        //cout<<a<<endl;
        b=(int)a;
        if(b<a)
        b++;
        printf("Case %d: %lld\n",t++,b);
    }
    return 0;
}
