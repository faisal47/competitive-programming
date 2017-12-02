#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct pat
{
  int start,end,cost;
};
vector<pat>path;
vector<int>result;
int parent[1010];
bool sign (pat a,pat b)
{
    return a.cost<b.cost;
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
    int u=find_parent(path[i].start);
    int v=find_parent(path[i].end);
    if(u==v)
    {
        result.push_back(path[i].cost);
        return;
    }
    parent[u]=v;
}
int main ()
{
    pat path1;
    int m,n,i;
    while(cin>>m>>n)
    {
        if(n==0&&m==0)
        break;
        for(i=0;i<m;i++)
        parent[i]=i;
        path.clear();
        result.clear();
        while(n--)
        {
            cin>>path1.start>>path1.end>>path1.cost;
            path.push_back(path1);
        }
        sort(path.begin(),path.end(),sign);
        for(i=0;i<path.size();i++)
        make_parent(i);
        if(result.size()==0)
        cout<<"forest"<<endl;
        else
        {
            cout<<result[0];
            for(i=1;i<result.size();i++)
            cout<<" "<<result[i];
            cout<<endl;
        }
    }
    return 0;
}
