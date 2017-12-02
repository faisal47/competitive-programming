#include <bits/stdc++.h>
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define scch(a) scanf(" %c",&a)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
using namespace std;
int dp[16][1<<16],dist[16][16],ase;
int make_mask(int pos,int number)
{
    return ~(1<<pos)&number;
}
bool check(int pos,int number)
{
    return (1<<pos)&number;
}
int maan_de(int pre,int mask)
{
    if(!mask)return dist[pre][0];
    int &ret=dp[pre][mask];
    if(ret!=-1)return ret;
    ret=inf;
    int i;
    for(i=1;i<ase;i++)
    if(check(i-1,mask))
    ret=min(ret,dist[pre][i]+maan_de(i,make_mask(i-1,mask)));
    return ret;
}
int main ()
{
    pii a[16];
    char arr[21][21];
    int t=1,test,n,m,i,j,res,mask;
    sci1(test);
    while(test--)
    {
        ase=1;
        res=inf;
        sci2(n,m);
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                scch(arr[i][j]);
                if(arr[i][j]=='x')
                    a[0]=mp(i,j);
                else if(arr[i][j]=='g')
                    a[ase++]=mp(i,j);
            }
        mask=(1<<(ase-1))-1;
        for(i=1;i<ase;i++)
        for(j=1;j<=mask;j++)
        dp[i][j]=-1;
        for(i=0;i<ase-1;i++)
        for(j=i+1;j<ase;j++)
            dist[i][j]=dist[j][i]=max(abs(a[i].fs-a[j].fs),abs(a[i].sc-a[j].sc));
        for(i=1;i<ase;i++)
        res=min(res,dist[0][i]+maan_de(i,make_mask(i-1,mask)));
        if(res==inf)res=0;
        printf("Case %d: %d\n",t++,res);
    }
    return 0;
}

