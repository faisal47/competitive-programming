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
#define sz
using namespace std;
int m,n,dp[20][20];
vector<int>v;
int maan(int pos,int last_digit)
{
    if(pos==n)
    return 1;
    if(dp[pos][last_digit]!=-1)
    return dp[pos][last_digit];
    int res=0;
    if(pos==0)
    {
        for(int i=0;i<m;i++)
        res+=maan(pos+1,v[i]);
    }
    else
    {
        for(int i=0;i<m;i++)
        if(abs(v[i]-last_digit)<=2)
        res+=maan(pos+1,v[i]);
    }
    return dp[pos][last_digit]=res;
}
int main ()
{
    int test,t,i,j,a;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        v.clear();
        cin>>m>>n;
        for(i=0;i<m;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        ms(dp,-1);
        printf("Case %d: %d\n",t,maan(0,0));
    }
    return 0;
}
