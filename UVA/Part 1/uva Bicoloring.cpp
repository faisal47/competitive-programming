#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
vector<int>v[250];
int flag,color[250];
bool path[250][250];
void bfs()
{
    int a,i,j;
    queue<int>q;
    q.push(0);
    color[0]=1;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        if(color[a]==1)
            j=2;
        else
            j=1;
        for(i=0; i<v[a].size(); i++)
        {
            if(color[v[a][i]]==0)
            {
                path[a][v[a][i]]=path[v[a][i]][a]=1;
                color[v[a][i]]=j;
                q.push(v[a][i]);
            }
            else if(color[a]==color[v[a][i]]&&path[a][v[a][i]]==0)
                flag=1;
        }
        if(flag==1)
            break;
    }
    return;
}
int main ()
{
    int n,m,i,j;
    while(cin>>n)
    {
        if(n==0)
            break;
        for(i=0; i<n; i++)
            v[i].clear();
        cin>>m;
        flag=0;
        memset(color,0,sizeof(color));
        memset(path,0,sizeof(path));
        while(m--)
        {
            cin>>i>>j;
            v[i].push_back(j);
            v[j].push_back(i);
        }
        bfs();
        if(flag==1)
            printf("NOT BICOLORABLE.\n");
        else
            printf("BICOLORABLE.\n");
    }
}
