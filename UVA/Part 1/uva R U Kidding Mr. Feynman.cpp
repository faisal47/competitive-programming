#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
    double a;
    while(cin>>a)
    {
        if(a==0)
        break;
        a=pow(a,1/3.);
       printf("%.4lf\n",a);
    }
    return 0;
}
