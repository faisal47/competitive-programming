#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
    unsigned long long a,b;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)
        break;
        a=pow(a,b);
        printf("%llu\n",a);
    }
    return 0;
}
