#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define ll long long
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
//int bigmod(int a,int b,int m)
//{
//    if(b == 0) return 1%m;
//    int x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
#define sz 53
using namespace std;
int dp[sz][sz];
vec_<int>v;
int khoroch(int s,int e)
{
    if(dp[s][e]!=-1)
        return dp[s][e];
    int i,x=inf;
    bool flag=0;
    for(i=s; i<=e; i++)
    {
        if(v[i]>v[s] && v[i]<v[e])
        {
            flag=1;
            x=min(x,v[e]-v[s]+khoroch(s,i)+khoroch(i,e));
        }
    }
    if(!flag)
        return 0;
    return dp[s][e]=x;
}

int main()
{
    int i,j,n;
    while(cin>>n)
    {
        if(n==0)
            break;
        clr(v);
        cin>>j;
        v.pb(0);
        while(j--)
        {
            cin>>i;
            v.pb(i);
        }
        v.pb(n);
        ms(dp,-1);
        cout<<"The minimum cutting is "<<khoroch(0,v.size()-1)<<'.'<<endl;
    }
    return 0;
}
