#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
struct towns
{
  int start,end;
  double cost;
};
vector<towns>town;
int parents[800],flag1;
bool sign(towns a,towns b)
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
void make_parents(int i,int j)
{
    int u=find_parent(i);
    int v=find_parent(j);
    if(u==v)
    return;
    else
    parents[u]=v;
}
void make_parents1(int i)
{
    int u=find_parent(town[i].start);
    int v=find_parent(town[i].end);
    if(u==v)
    return;
    else
    parents[u]=v;
    cout<<town[i].start<<" "<<town[i].end<<endl;
    flag1=1;
}
int main ()
{
    towns t1;
    int test,m,n,i,j,flag=0,arr[800][3];
    cin>>test;
    while(test--)
    {
        flag1=0;
        town.clear();
        if(flag)
        cout<<endl;
        flag=1;
        cin>>m;
        for(i=1;i<=m;i++)
        {
            cin>>arr[i][0]>>arr[i][1];
            parents[i]=i;
        }
        for(i=1;i<=m;i++)
        for(j=i+1;j<=m;j++)
        {
            t1.start=i;
            t1.end=j;
            t1.cost=sqrt(pow((arr[i][0]-arr[j][0]),2.)+pow((arr[i][1]-arr[j][1]),2.));
            town.push_back(t1);
        }
        sort(town.begin(),town.end(),sign);
        cin>>n;
        while(n--)
        {
            cin>>i>>j;
            make_parents(i,j);
        }
        for(i=0;i<town.size();i++)
        make_parents1(i);
        if(flag1==0)
        cout<<"No new highways need"<<endl;
    }
    return 0;
}
