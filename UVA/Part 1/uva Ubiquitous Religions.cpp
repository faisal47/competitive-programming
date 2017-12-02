#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
vector<int>v[50010];
bool color[50010];
void bfs(int a)
{
    int i;
    queue<int>q;
    q.push(a);
    color[a]=1;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        for(i=0;i<v[a].size();i++)
        {
            if(color[v[a][i]]==0)
            {
                color[v[a][i]]=1;
                q.push(v[a][i]);
            }
        }
    }
    return;
}
int main ()
{
    int i,test=1,m,n,j,count;
    while(cin>>m>>n)
    {
        if(m==0&&n==0)
        break;
        memset(color,0,sizeof(color));
        count=0;
        for(i=1;i<=m;i++)
        v[i].clear();
        while(n--)
        {
            cin>>i>>j;
            v[i].push_back(j);
            v[j].push_back(i);
        }
        for(i=1;i<=m;i++)
        {
            if(color[i]==0)
            {
                bfs(i);
                count++;
            }
        }
        printf("Case %d: %d\n",test++,count);
    }
    return 0;
}
