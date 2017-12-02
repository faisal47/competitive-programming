#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define sci1(a) scanf("%d",&a)
#define mt 10010
#define inf 1<<28
using namespace std;
int dp[mt];
int maan_de(int n)
{
    int a=sqrt(n);
    if(a*a==n)return 1;
    int &ret=dp[n];
    if(ret!=-1)
    return ret;
    ret=inf;
    for(int i=1;i<=a;i++)
    ret=min(ret,1+maan_de(n-i*i));
    return ret;
}
int main ()
{
    int n,t;
    ms(dp,-1);
    sci1(t);
    while(t--)
    {
        sci1(n);
        cout<<maan_de(n)<<endl;
    }
    return 0;
}

