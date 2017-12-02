#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int taka[10010],amount;
bool flag[10010];
vector<int>v[10010];
void bfs(int start)
{
    queue<int>q;
    q.push(start);
    amount=taka[start];
    flag[start]=1;
    //cout<<"start "<<start<<endl;
    int i;
    //cout<<"output "<<amount<<endl;
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
               amount+=taka[v[start][i]];
              // cout<<"output "<<amount<<endl;
            }
        }
    }
    return;
}
int main ()
{
    int test,m,n,i,j,flag1;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        flag1=0;
        for(i=0;i<n;i++)
        {
            cin>>j;
            flag[i]=0;
            taka[i]=j;
            v[i].clear();
           // cout<<"output "<<taka[i]<<endl;
        }
        while(m--)
        {
            cin>>i>>j;
            v[i].push_back(j);
            v[j].push_back(i);
        }
        for(i=0;i<n;i++)
        {
            if(flag[i]==0)
            bfs(i);
            if(amount!=0)
            {
                flag1=1;
                break;
            }
        }
        if(flag1==0)
        cout<<"POSSIBLE"<<endl;
        else
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
