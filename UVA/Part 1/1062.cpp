#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define sz
using namespace std;
int main ()
{
    int test;
    double a,b,c,pi=acos(-1);
    cin>>test;
    while(test--)
    {
        cin>>a;
        b=(3./5.)*a;
        c=(1./5.)*a;
        c=pi*c*c;
        b=(a*b)-c;
        printf("%.2lf %.2lf\n",c,b);
    }
    return 0;
}
