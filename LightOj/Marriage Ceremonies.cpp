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
#define sz 18
using namespace std;
int arr[sz][sz],dp[sz][sz],n;
bool col[sz];
int recur(int a,int b)
{
    if(a>=n || b>=n)
    return 0;
    int &ret=dp[a][b];
    if(ret!=-1)
    return ret;
    int i;
    ret=0;
    for(i=0;i<n;i++)
    if(!col[i])
    {
        col[i]=1;
        ret=max(ret,arr[a][i]+recur(a+1,i));
        col[i]=0;
    }
    return ret;
}
int main ()
{
    int i,j,test,t=1,ans;
    sci1(test);
    while(test--)
    {
        ans=0;
        ms(dp,-1);
        sci1(n);
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        sci1(arr[i][j]);
        ms(col,0);
//        for(i=0;i<n;i++)
//        {
//            ms(col,0);
//            col[i]=1;
//            ans=max(ans,arr[0][i],recur(1,0));
//        }
        printf("Case %d: %d\n",t++,recur(0,0));
    }
    return 0;
}
