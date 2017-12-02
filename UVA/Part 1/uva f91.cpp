#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
#include <ctype.h>
using namespace std;
#define inf 1<<28
long long call(long long n)
{
    if(n<=100)
    return call(call(n+11));
    else
    return n-10;
}
int main ()
{
    long long n;
    while(cin>>n)
    {
        if(n==0)
        break;
        printf("f91(%lld) = %lld\n",n,call(n));
    }
    return 0;
}

