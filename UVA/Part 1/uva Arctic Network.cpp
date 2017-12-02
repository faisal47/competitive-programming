#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector<double>mst;
struct d
{
    int s,e;
    double dis;
};
vector<d>dist;
double durotto(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
int par[502];
int find_par(int i)
{
    if(par[i]==i)
    return i;
    return par[i]=find_par(par[i]);
}
void make_par(int i)
{
    int u=find_par(dist[i].s);
    int v=find_par(dist[i].e);
    if(u==v)
    return;
    par[u]=v;
    mst.push_back(dist[i].dis);
}
bool sign(d a, d b)
{
    return a.dis<b.dis;
}
int main ()
{
    int t,arr[502][2],n,p,i,j;
    d d1;
    cin>>t;
    while(t--)
    {
      dist.clear();
      cin>>n>>p;
      for(i=1;i<=p;i++)
      {
          cin>>arr[i][0]>>arr[i][1];
          par[i]=i;
      }
      for(i=1;i<=p;i++)
      for(j=i+1;j<=p;j++)
      {
          d1.s=i;
          d1.e=j;
          d1.dis=durotto(arr[i][0],arr[i][1],arr[j][0],arr[j][1]);
            dist.push_back(d1);
      }
      mst.clear();
      sort(dist.begin(),dist.end(),sign);
      for(i=0;i<dist.size();i++)
      make_par(i);
      printf("%.2lf\n",mst[mst.size()-n]);
    }
    return 0;
}
