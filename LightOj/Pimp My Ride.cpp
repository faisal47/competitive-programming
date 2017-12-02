#include <bits/stdc++.h>
#define inf 1<<28
#define sci1(a) scanf("%d",&a)
#define mt (1<<14)+5
using namespace std;
typedef long long ll;
ll dp[mt],n,arr[16][16];
bool check(int pos,int mask)
{
    return (1<<pos)&mask;
}
int make_mask(int pos,int mask)
{
    return ~(1<<pos)&mask;
}
ll maan_de(int mask)
{
    if(!mask)return 0;
    ll &ret=dp[mask];if(ret!=-1)return ret;
    int i,j,jog,new_mask;
    ret=inf;
    for(i=0;i<n;i++)
    {
        if(check(i,mask))
        {
            jog=arr[i][i];
            new_mask=make_mask(i,mask);
            for(j=0;j<n;j++)
            {
                if(!check(j,new_mask) && i!=j)
                    jog+=arr[i][j];
            }
            ret=min(ret,jog+maan_de(new_mask));
        }
    }
    return ret;
}
int main ()
{
    int i,j,test,t=1,l;
    sci1(test);
    while(test--)
    {
        sci1(n);
        l=1<<n;
        for(i=0;i<l;i++)dp[i]=-1;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)sci1(arr[i][j]);
        printf("Case %d: %d\n",t++,maan_de((1<<n)-1));
    }
    return 0;
}

