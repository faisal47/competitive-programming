#include <stdio.h>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
bool color[10010];
int count;
vector<int>v[10010];
void bfs(int start)
{
    queue<int>q;
    q.push(start);
    int i;
    color[start]=1;
    ++count;
    while(!q.empty())
    {
        start=q.front();q.pop();
        for(i=0;i<v[start].size();i++)
        {
            if(color[v[start][i]]==0)
            {
               color[v[start][i]]=1;
               ++count;
                q.push(v[start][i]);
            }
        }
    }
    return;
}
int main ()
{
    int test,i,m,n,z,j;
    cin>>test;
    while(test--)
    {
        count=0;
        cin>>m>>n>>z;
        for(i=1;i<=m;i++)
        {
            color[i]=0;
            v[i].clear();
        }
        while(n--)
        {
            cin>>i>>j;
            v[i].push_back(j);
        }
        while(z--)
        {
            cin>>i;
            if(color[i]==0)
            bfs(i);
        }
        cout<<count<<endl;
    }
    return 0;
}
