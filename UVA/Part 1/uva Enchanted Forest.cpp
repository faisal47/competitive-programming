#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <queue>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define ll long long
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define pu push
#define pob pop_back()
#define vec_ vector
#define eps 1E-7
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz
using namespace std;
//struct data //for dj()
//{
//   int node,cost;
//   bool operator < (const data& p) const
//   {
//       return cost > p.cost;
//   }
//};
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
//ll gcd(ll a,ll b)
//{
//   if(b==0)
//   return a;
//   return gcd(b,a%b);
//}
int X[]={0,-1,-1,-1,0,1,1,1};
int Y[]={-1,-1,0,1,1,1,0,-1};
int arr[210][210];
int i,j,r,c,m,n,i1,j1,a,x1,x2;
bool check()
{
    if(x1>=0 && x2>=0 && x1<r && x2<c)
    return 1;
    else
    return 0;
}
void make_block()
{
    x1=i;
    x2=j;
    a=n;
    while(a--)
    {
        x2--;
        if(!check())
        break;
        arr[x1][x2]=-1;
    }
    x1=i;
    x2=j;
    a=n;
    while(a--)
    {
        x2--,x1--;
        if(!check())
        break;
        arr[x1][x2]=-1;
    }
    x1=i;
    x2=j;
    a=n;
    while(a--)
    {
        x1--;
        if(!check())
        break;
        arr[x1][x2]=-1;
    }
    x1=i;
    x2=j;
    a=n;
    while(a--)
    {
        x1--,x2++;
        if(!check())
        break;
        arr[x1][x2]=-1;
    }
    x1=i;
    x2=j;
    a=n;
    while(a--)
    {
        x2++;
        if(!check())
        break;
        arr[x1][x2]=-1;
    }
    x1=i;
    x2=j;
    a=n;
    while(a--)
    {
        x1++,x2++;
        if(!check())
        break;
        arr[x1][x2]=-1;
    }
    x1=i;
    x2=j;
    a=n;
    while(a--)
    {
        x1++;
        if(!check())
        break;
        arr[x1][x2]=-1;
    }
    x1=i;
    x2=j;
    a=n;
    while(a--)
    {
        x1++,x2--;
        if(!check())
        break;
        arr[x1][x2]=-1;
    }
}
int bfs()
{
    queue<int>q;
    q.pu(0);
    q.pu(0);
    int s,e;
    arr[s][e]=1;
    while(!q.empty())
    {
        s=q.front();
        q.pob;
        e=q.front();
        q.pob;
        for(i=0;i<8;i++)
        {
            x1=s+X[i];
            x2=e+Y[i];
            if(arr[x1][x2]==0 && check())
            {
                q.pu(x1);
                q.pu(x2);
                arr[x1][x2]=arr[s][e]+1;
            }
        }
    }
}
int main ()
{
    while(cin>>r>>c)
    {
        if(r==0 && c==0)
        break;
        for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        arr[i][j]=0;
        cin>>m;
        while(m--)
        {
            cin>>i>>j;
            i--,j--;
            arr[i][j]=-1;
        }
        cin>>m;
        while(m--)
        {
            cin>>i>>j>>n;
            i--,j--;
            arr[i][j]=-1;
            make_block();
        }
        bfs();
    }
    return 0;
}

