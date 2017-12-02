#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m,k,ase[2010],cou[2010],flag[2010],jabe[2010];
vector<int>v[2010];
void bfs(int start)
{
    int i;
    queue<int>q;
    q.push(start);
    flag[start]=1;
    if(ase[start]==0)
    cou[start]=1;
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
               if(ase[v[start][i]]==0)
               cou[v[start][i]]=cou[start]+1;
               else
               cou[v[start][i]]=cou[start];
            }
        }
    }
}
int main ()
{
    int t,test,a,b,i;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>n>>m>>k;
        for(i=1;i<=n;i++)
        {
            ase[i]=0;
            jabe[i]=0;
            v[i].clear();
        }
        while(k--)
        {
            cin>>a;
            ase[a]=1;
        }
        while(m--)
        {
            cin>>a>>b;
            jabe[a]=jabe[b]=1;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        cin>>k;
        printf("Case %d:\n",t);
        while(k--)
        {
            cin>>a>>b;
            for(i=1;i<=n;i++)
            {
                cou[i]=0;
                flag[i]=0;
            }
            if(jabe[a]==0||jabe[b]==0)
            {
                cout<<"-1"<<endl;
            }
            else
            {
                bfs(a);
                if(flag[b]==1)
                cout<<cou[b]<<endl;
                else
                cout<<"-1\n";
            }
        }
        cout<<endl;
    }
    return 0;
}
