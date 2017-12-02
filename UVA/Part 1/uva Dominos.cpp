#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
#include <iostream>
using namespace std;
int flag[100010];
vector<int>v[100010];
vector<int>v1;
void bfs(int i)
{
    int it;
    int a,b;
    queue<int>q;
    q.push(i);
    flag[i]=1;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        for(it=0;it<v[a].size();it++)
        {
            b=v[a][it];
            if(flag[b]!=1)
            {
                flag[b]=1;
                q.push(b);
            }
        }
    }
    return;
}
void bfs1(int i)
{
    int it;
    queue<int>q;
    q.push(i);
    flag[i]=2;
    int a,b;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        for(it=0;it<v[a].size();it++)
        {
            b=v[a][it];
            if(flag[b]!=2)
            {
                flag[b]=2;
                q.push(b);
            }
        }
    }
    return;
}
int main ()
{
   int it;
    int test,m,n,i,a,b,count1;
    scanf("%d",&test);
    while(test--)
    {
        count1=0;
        memset(flag,0,sizeof(flag));
        scanf("%d %d",&m,&n);
        if(m==0)
        {
            cout<<0<<endl;

            continue;
        }
        else if(n==0)
        {
            cout<<m<<endl;
            continue;
        }
        for(i=1;i<=m;i++)
        {
            v[i].clear();
        }
        while(n--)
        {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
        }
        for(i=1;i<=m;i++)
        {
            if(flag[i]!=1)
            {
                v1.push_back(i);
                bfs(i);
            }
        }
        for(it=v1.size()-1;it>=0;it--)
        {
            a=v1[it];
            if(flag[a]!=2)
            {
                count1++;
                bfs1(a);
            }
        }
        printf("%d\n",count1);
        v1.clear();
    }
    return 0;
}
