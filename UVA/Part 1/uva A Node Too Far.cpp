#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int c1,node[100],m,dist[100];
bool color[100],arr[100][100];
void bfs(int a,int ttl)
{
    int c2=0,i,b;
    b=a;
    queue<int>q;
    q.push(a);
    color[a]=1;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        for(i=1;i<m;i++)
        {
            if(color[i]==0&&arr[a][i]==1&&arr[i][a]==1)
            {
                color[i]=1;
                q.push(i);
                dist[i]=dist[a]+1;
            }
        }
    }
    for(i=1;i<m;i++)
    {
        if(dist[i]<=ttl&&dist[i]!=0)
        c2++;
    }
    c2++;
    printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",c1++,m-1-c2,node[b],ttl);
    return;
}
int main ()
{
    c1=1;
   int n,a,i,b,flag1,flag2,c,d,j;
    while(cin>>n)
    {
        if(n==0)
        break;
        m=1;
        memset(node,0,sizeof(node));
        memset(arr,0,sizeof(arr));
        while(n--)
        {
            cin>>a>>b;
            flag1=flag2=0;
            for(i=1;i<m;i++)
            {
                if(a==node[i])
                flag1=1;
                if(b==node[i])
                flag2=1;
            }
            if(a==b&&flag1==0)
            flag2=1;
            if(flag1==0)
            node[m++]=a;
            if(flag2==0)
            node[m++]=b;
            for(i=1;i<m;i++)
            {
                if(a==node[i])
                c=i;
                if(b==node[i])
                d=i;
            }
            if(c==d)
            arr[c][d]=arr[d][c]=0;
            else
            arr[c][d]=arr[d][c]=1;
        }
        while(cin>>a>>b)
        {
            if(a==0&&b==0)
            break;
            for(i=1;i<m;i++)
            {
                if(a==node[i])
                {
                    memset(color,0,sizeof(color));
                    memset(dist,0,sizeof(dist));
                    if(b==0)
                    printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",c1++,m-2,a,b);
                    else
                    bfs(i,b);
                    break;
                }
            }
        }
    }
    return 0;
}
