#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int parents[10000000],maxi;
struct ras
{
    int start,end,weight;
};
vector<ras>rasta;
bool flag[10000000];
bool sign (ras a,ras b)
{
    return a.weight<b.weight;
}
int find_parents(int i)
{
    if(parents[i]==i)
    return i;
    else
    return parents[i]=find_parents(parents[i]);
}
void make_parents(int i)
{
    int u=find_parents(rasta[i].start);
    int v=find_parents(rasta[i].end);
    if(u==v)
    return;
    parents[u]=v;
    flag[rasta[i].start]=1;
    flag[rasta[i].end]=1;
    if(maxi<rasta[i].weight)
    maxi=rasta[i].weight;
}
int main ()
{
    int n,m,i,flag2;
    ras rast;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
        break;
        maxi=flag2=0;
        rasta.clear();
        for(i=0;i<m;i++)
        {
            cin>>rast.start>>rast.end>>rast.weight;
            rasta.push_back(rast);
        }
        for(i=0;i<n;i++)
        {
            parents[i]=i;
            flag[i]=0;
        }
        sort(rasta.begin(),rasta.end(),sign);
        for(i=0;i<m;i++)
        make_parents(i);
        for(i=0;i<n;i++)
        if(flag[i]==0)
        {
            flag2=1;
            break;
        }
        if(flag2==1)
        cout<<"IMPOSSIBLE"<<endl;
        else
        cout<<maxi<<endl;
    }
    return 0;
}
