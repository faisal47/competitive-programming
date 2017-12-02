#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <utility>
#define scll1(a) scanf(" %I64d",&a)
#define prll1(a) printf("%I64d ",a)
using namespace std;
typedef long long ll;
int main ()
{
    ll j,n,m,ans=0,pre=1;
    scll1(n);
    scll1(m);
    while(m--)
    {
        scll1(j);
        if(pre<=j)ans+=(j-pre);
        else ans+=(n-pre+j);
        pre=j;
    }
    prll1(ans);
    return 0;
}

