#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
vector<int>v[105];
bool flag[105];
void bfs(int start)
{
    queue<int>q;
    int i;
    q.push(start);
    while(!q.empty())
    {
        start=q.front();
        q.pop();
        for(i=0;i<v[start].size();i++)
        {
            if(flag[v[start][i]]==0)
            {
                flag[v[start][i]]=1;
                q.push(v[start][i]);
            }
        }
    }
    return;
}
int main ()
{
    vector<int>out;
    int nodes,test,start,end,i,c;
    while(cin>>nodes)
    {
        if(nodes==0)
        break;
        for(i=1;i<=nodes;i++)
        v[i].clear();
        while(cin>>start)
        {
            if(start==0)
            break;
            while(cin>>end)
            {
                if(end==0)
                break;
                v[start].push_back(end);
            }
        }
        cin>>test;
        while(test--)
        {
            c=0;
            out.clear();
            memset(flag,0,sizeof(flag));
            cin>>start;
            bfs(start);
            for(i=1;i<=nodes;i++)
            if(flag[i]==0)
            {
                out.push_back(i);
            }
            cout<<out.size();
            for(i=0;i<out.size();i++)
            cout<<" "<<out[i];
            cout<<endl;
        }
    }
    return 0;
}
