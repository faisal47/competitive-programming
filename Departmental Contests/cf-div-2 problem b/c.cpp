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
#define vec_ vector
#define pb push_back
#define sci1(a) scanf(" %d",&a)
#define pri1(a) printf("%d ",a)
#define sz(a) a.size()
#define mt 10000010
using namespace std;
int flag[mt];
vec_<int>v;
int main ()
{
    int n,i,j;
    v.pb(2);
    for(i=3;i<mt;i+=2)
    if(!flag[i])
    {
        flag[i]=1;
        v.pb(i);
        for(j=i+i;j<mt;j+=i)flag[j]=1;
    }
    sci1(n);
    for(i=0;i<n;i++)
    pri1(v[i]);
    return 0;
}

