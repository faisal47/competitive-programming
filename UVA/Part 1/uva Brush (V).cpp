#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
struct ras
{
    int a,b,w;
};
vector<ras>rasta;
bool flag[110],flag1;
int parent[110];
long long int jog;
bool comp(ras a,ras b)
{
    return a.w<b.w;
}
int find_parent(int i)
{
    if(parent[i]==i)
    return i;
    else
    return parent[i]=find_parent(parent[i]);
}
void make_parent(int i)
{
    int u=find_parent(rasta[i].a);
    int v=find_parent(rasta[i].b);
    if(u!=v)
    {
        parent[u]=v;
        flag[rasta[i].a]=flag[rasta[i].b]=1;
        jog+=rasta[i].w;
    }

    return;
}
int main ()
{
    int test,t,m,n,i;
    ras ras1;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        flag1=jog=0;
        rasta.clear();
        cin>>n>>m;
        while(m--)
        {
            cin>>ras1.a>>ras1.b>>ras1.w;
            rasta.push_back(ras1);
        }
        for(i=1;i<=n;i++)
        {
            flag[i]=0;
            parent[i]=i;
        }
        sort(rasta.begin(),rasta.end(),comp);
        for(i=0;i<rasta.size();i++)
        {
            make_parent(i);
        }
        for(i=1;i<=n;i++)
        {
            if(flag[i]==0)
            {
                flag1=1;
                break;
            }
        }
        printf("Case %d: ",t);
        if(flag1==1)
        cout<<"Impossible"<<endl;
        else
        cout<<jog<<endl;
    }
    return 0;
}
