#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <stack>
#include <utility>
#include <queue>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
using namespace std;
vec_<int>v;
int n,w,c1,c2,d;
void init()
{
    c1=c2=0;
    clr(v);
}
void process()
{
    c1++;
    d=v[0]+w;
    for(n=1; n<v.size(); n++)
        if(d<v[n])
        {
            d=v[n]+w;
            c1++;
        }
    c2++;
    d=v[v.size()-1]-w;
    for(n=v.size()-1;n>=0;n--)
    if(d>v[n])
    {
        d=v[n]-w;
        c2++;
    }
}
int main ()
{
    int test,t=1,a;
    sci1(test);
    while(test--)
    {
        init();
        sci2(n,w);
        while(n--)
        {
            sci2(a,a);
            v.pb(a);
        }
        sort(v.begin(),v.end());
        process();
        printf("Case %d: %d\n",t++,min(c1,c2));
    }
    return 0;
}

