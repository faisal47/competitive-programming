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
int dp[1010][1010],len;
int check[1010][1010];
string a;
int bana(int s,int e)
{
    if(s==len)
    return 0;
    int ans=inf,i;
    if(dp[s][e]!=-1)
    return dp[s][e];
    for(i=s;i<len;i++)
    if(check[s][i]==1)
    ans = min( ans, bana(i+1,e)+1);
    return dp[s][e]=ans;
}
int main ()
{
    int t,test,i,j,k;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        ms(check,0);
        ms(dp,-1);
        cin>>a;
        len=a.size();
        for(i=0;i<len;i++)
        check[i][i]=1;
        for(i=0;i<len-1;i++)
        check[i][i+1]=(a[i]==a[i+1]);
        for(i=2;i<len;i++)
        for(j=0;j<len;j++)
        if(i+j<len)
        {
            if(check[j+1][i+j-1]==1 && a[j]==a[i+j])
            check[j][i+j]=1;
        }
        else
        break;
        printf("Case %d: %d\n",t,bana(0,len-1));
    }
    return 0;
}
