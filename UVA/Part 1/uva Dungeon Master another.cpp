#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int a,b,c,dist[35][35][35];
bool color[35][35][35];
char arr[35][35][35],z;
void bfs(int i,int j,int k)
{
    int flag=0,l,u,v,w,mjayga1[10]={0,0,0,0,-1,1},mjayga2[10]={-1,0,1,0,0,0},mjayga3[10]={0,1,0,-1,0,0};
    queue<int>q;
    q.push(i);
    q.push(j);
    q.push(k);
    color[i][j][k]=1;
    while(!q.empty())
    {
       i=q.front();
       q.pop();
       j=q.front();
       q.pop();
       k=q.front();
       q.pop();
       for(l=0;l<6;l++)
       {
           u=i+mjayga1[l];
           v=j+mjayga2[l];
           w=k+mjayga3[l];
           if(u>=0&&v>=0&&w>=0&&u<a&&v<b&&w<c)
           {
               if(color[u][v][w]==0&&arr[u][v][w]!='#')
               {
                   color[u][v][w]=1;
                   dist[u][v][w]=dist[i][j][k]+1;
                   if(arr[u][v][w]=='E')
                   {
                       flag=1;
                       break;
                   }
                   q.push(u);
                   q.push(v);
                   q.push(w);
               }
           }
       }
       if(flag==1)
       break;
    }
    if(flag==1)
    printf("Escaped in %d minute(s).\n",dist[u][v][w]);
    else
    printf("Trapped!\n");
    return;
}
int main ()
{
    int i,j,k,flag;
    while(cin>>a>>b>>c)
    {
        scanf("%c",&z);
        if(a==0&&b==0&&c==0)
        break;
        flag=0;
        memset(color,0,sizeof(color));
        memset(dist,0,sizeof(dist));
        for(i=0;i<a;i++)
        for(j=0;j<b+1;j++)
        gets(arr[i][j]);
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                for(k=0;k<c;k++)
                {
                    if(arr[i][j][k]=='S')
                    {
                        bfs(i,j,k);
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                break;
            }
            if(flag==1)
                break;
        }
    }
    return 0;
}
