#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
struct d
{
    int s,e;
    double d;
};
vector<d>dist;
int par[800];
double ans;
double durotto(int x1,int x2,int y1,int y2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
int find_par(int i)
{
    if(par[i]==i)
    return i;
    else
    return par[i]=find_par(par[i]);
}
void make_par1(int a,int b)
{
    int u=find_par(a);
    int v=find_par(b);
    if(u==v)
    return;
    else
    par[u]=v;
}
void make_par2(int i)
{
    int u=find_par(dist[i].s);
    int v=find_par(dist[i].e);
    if(u==v)
    return;
    else
    par[u]=v;
    ans+=dist[i].d;
}
bool sign(d a,d b)
{
    return a.d<b.d;
}
int main ()
{
    d d1;
    int i,j,n,dis[800][2],m;
    while(cin>>n)
    {
        ans=0;
        dist.clear();
        for(i=1;i<=n;i++)
        {
            par[i]=i;
            cin>>dis[i][0]>>dis[i][1];
        }
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
               d1.s=i;d1.e=j;d1.d=durotto(dis[i][0],dis[j][0],dis[i][1],dis[j][1]);
               dist.push_back(d1);
            }
        }
        cin>>m;
        while(m--)
        {
            cin>>i>>j;
            make_par1(i,j);
        }
        sort(dist.begin(),dist.end(),sign);
        for(i=0;i<dist.size();i++)
        make_par2(i);
        printf("%.2lf\n",ans);
    }
    return 0;
}
