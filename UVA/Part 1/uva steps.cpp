#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int main ()
{
    int test;
    double a,b;
    cin>>test;
    while(test--)
    {
        cin>>a>>b;
        a=b-a;
        a=(sqrt(1.+(4.*2.*a))-1)/2.;
        printf("%.0lf\n",a+1);
    }
    return 0;
}
