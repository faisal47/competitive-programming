#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parents[200010],main_cost;
struct rasta
{
    int start,end,cost;
};
rasta rasta_temp;
vector<rasta>rasta_main;
bool sign(rasta a,rasta b)
{
    return a.cost<b.cost;
}
int find_parent(int i)
{
    if(parents[i]==i)
    return i;
    else
    return parents[i]=find_parent(parents[i]);
}
void make_parent(int i)
{
    int u=find_parent(rasta_main[i].start);
    int v=find_parent(rasta_main[i].end);
    if(u==v)
    return;
    parents[u]=v;
    main_cost+=rasta_main[i].cost;
}
int main ()
{
    int i,m,n,pre_total;
    while(cin>>m>>n)
    {
        if(m==0&&n==0)
        break;
        rasta_main.clear();
        pre_total=main_cost=0;
        for(i=0;i<m;i++)
        parents[i]=i;
        for(i=0;i<n;i++)
        {
            cin>>rasta_temp.start>>rasta_temp.end>>rasta_temp.cost;
            pre_total+=rasta_temp.cost;
            rasta_main.push_back(rasta_temp);
        }
        sort(rasta_main.begin(),rasta_main.end(),sign);
        for(i=0;i<n;i++)
        make_parent(i);
        pre_total-=main_cost;
        cout<<pre_total<<endl;
    }
    return 0;
}
