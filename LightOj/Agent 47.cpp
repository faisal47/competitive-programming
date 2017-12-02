#include <bits/stdc++.h>
#define inf 1<<28
#define scch(a) scanf(" %c",&a)
#define sci1(a) scanf(" %d",&a)
#define mt (1<<15)+3
using namespace std;
int dp[mt],n,health[20];
char arr[20][20];
bool check(int pos,int number)
{
    return (1<<pos)&number;
}
int make_mask(int pos,int number)
{
    return ~(1<<pos)&number;
}
int maan_de(int mask)
{
    if(!mask)return 0;
    int &ret=dp[mask];
    if(ret!=-1)return ret;
    ret=inf;
    int i,j,ansp,ans;
    for(i=0;i<n;i++)
    if(check(i,mask))
    {
        ansp=1;
        for(j=0;j<n;j++)
            if(!check(j,mask))ansp=max(ansp,arr[j][i]-'0');
        ans=health[i]/ansp;
        if(health[i]%ansp)ans++;
        ret=min(ret,ans+maan_de(make_mask(i,mask)));
    }
    return ret;
}
int main ()
{
    int test,t=1,i,j,l;
    sci1(test);
    while(test--)
    {
        sci1(n);
        l=1<<n;
        for(i=0;i<l;i++)dp[i]=-1;
        for(i=0;i<n;i++)sci1(health[i]);
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scch(arr[i][j]);
        printf("Case %d: %d\n",t++,maan_de((1<<n)-1));
    }
    return 0;
}

