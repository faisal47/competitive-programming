#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct res
{
    int node,time;
};
res res1;
vector<res>result;
vector<int>v[150];
bool flag[150];
int current_time;
void dfs(int start)
{
    int i;
    if(flag[start]==0)
    {
        current_time++;
        flag[start]=1;
        for(i=0;i<v[start].size();i++)
        {
            dfs(v[start][i]);
        }
        res1.time=current_time;
        res1.node=start;
        result.push_back(res1);
         current_time++;
    }
    return;
}
bool comp(res a,res b)
{
    return a.time>b.time;
}
int main ()
{
    int m,n,i,a,b;
    while(cin>>m>>n)
    {
        if(m==0&&n==0)
        break;
        current_time=0;
        result.clear();
        for(i=1;i<=m;i++)
        {
            flag[i]=0;
            v[i].clear();
        }
        result.clear();
        while(n--)
        {
            cin>>a>>b;
            v[a].push_back(b);
        }
        for(i=1;i<=m;i++)
        if(flag[i]==0)
        {
            dfs(i);
            current_time--;
        }
        sort(result.begin(),result.end(),comp);
        for(i=0;i<m;i++)
        cout<<result[i].node<<endl;
    }
    return 0;
}
