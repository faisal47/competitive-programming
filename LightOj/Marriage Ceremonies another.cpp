#include <stdio.h>
#include <iostream>
#define sci1(a) scanf("%d",&a)
using namespace std;
int n,arr[18][18],dp[18][(1<<16)+5];
int check(int mask,int i)
{
    return mask & (1<<i);
}
int new_mask(int mask,int i)
{
    return mask | (1<<i);
}
int recur(int a,int mask)
{
    if(a>=n)
    return 0;
    int i,&ret=dp[a][mask];
    if(ret!=-1)
    return ret;
    ret=0;
    for(i=0;i<n;i++)
    if(!check(mask,i))
        ret=max(ret, recur(a+1,new_mask(mask,i)) + arr[a][i]);
    return ret;
}
int main ()
{
    int test,t=1,k,i,j;
    sci1(test);
    while(test--)
    {
        sci1(n);
        k=(1<<n)+5;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                {
                    sci1(arr[i][j]);
                    dp[i][j]=-1;
                }
            for(j=n; j<k; j++)
                dp[i][j]=-1;
        }
        printf("Case %d: %d\n",t++,recur(0,0));
    }
    return 0;
}

