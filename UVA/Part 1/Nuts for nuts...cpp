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
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define scch(a) scanf(" %c",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sz(a) a.size()
#define mt 1<<16
using namespace std;
int ase,dist[25][25],dp[20][mt];
bool check(int mask,int pos)
{
    return (1<<pos)&mask;
}
int make_mask(int mask,int pos)
{
    return ~(1<<pos)&mask;
}
int maan_de(int asi,int mask)
{
    if(!mask)return dist[asi][0];
    int &ret=dp[asi][mask];
    if(ret!=-1)return ret;
    int i;
    ret=inf;
    for(i=1;i<ase;i++)
    if(check(mask,i))
    ret=min(ret,dist[asi][i]+maan_de(i,make_mask(mask,i)));
    return ret;
}
int main ()
{
    int i,j,arr[23][2],mask,n,m;
    char c;
    while(sci2(n,m)==2)
    {
        ase=1;
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
            {
                scch(c);
                if(c=='L')
                    arr[0][0]=i,arr[0][1]=j;
                else if(c=='#')
                    arr[ase][0]=i,arr[ase++][1]=j;
            }
        for(i=0;i<ase;i++)
        for(j=0;j<ase;j++)
        dist[i][j]=max(abs(arr[i][0]-arr[j][0]),abs(arr[i][1]-arr[j][1]));
        mask=(1<<ase)-1;
        for(j=0;j<ase;j++)
        for(i=0;i<=mask;i++)
        dp[j][i]=-1;
        printf("%d\n",maan_de(0,make_mask(mask,0)));
    }
    return 0;
}

