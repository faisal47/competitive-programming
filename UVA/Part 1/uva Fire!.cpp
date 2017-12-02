#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int m,n,dist[1050][1050];
char arr[1050][1050];
bool color[1050][1050];
void bfs()
{
    memset(color,0,sizeof(color));
    memset(dist,0,sizeof(dist));
    int i,j,a,b,a1,b1;
    queue<int>q;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(arr[i][j]=='F')
            {
                q.push(i);
                q.push(j);
                color[i][j]=1;
            }
            else if(arr[i][j]=='J')
            {
                a=i;
                b=j;
            }
        }
    }
    q.push(a);
    q.push(b);
     if(a==(m-1)||b==(n-1)||a==0||b==0)
     {
         cout<<"1"<<endl;
         return;
     }
    int x[]= {0,-1,0,1},y[]= {-1,0,1,0},u,v,endflag=0;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        v=q.front();
        q.pop();
        if(arr[u][v]=='J')
        {
            for(i=0; i<4; i++)
            {
                a1=(u+x[i]);
                b1=(v+y[i]);
                if(a1>=0&&b1>=0&&a1<m&&b1<n)
                {
                    if(arr[a1][b1]=='.'&&color[a1][b1]==0)
                    {
                        if(a1==(m-1)||b1==(n-1)||a1==0||b1==0)
                        {
                            endflag=1;
                            a=a1;
                            b=b1;
                            dist[a1][b1]=dist[u][v]+1;
                            break;
                        }
                        else
                        {
                            dist[a1][b1]=dist[u][v]+1;
                            arr[a1][b1]='J';
                            q.push(a1);
                            q.push(b1);
                        }
                    }
                }
            }
        }
        else
        {
            for(i=0; i<4; i++)
            {
                a1=(u+x[i]);
                b1=(v+y[i]);
                if(a1>=0&&b1>=0&&a1<m&&b1<n)
                {
                    if(arr[a1][b1]!='#'&&color[a1][b1]==0)
                    {
                        color[a1][b1]=1;
                        q.push(a1);
                        q.push(b1);
                    }
                }
            }
        }
        if(endflag==1)
            break;
    }
    if(endflag==1)
        cout<<dist[a][b]+1<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
    return;
}
int main ()
{
    int i,test,j;
    char z;
    cin>>test;
    while(test--)
    {
        scanf("%d %d",&m,&n);
        scanf("%c",&z);
        for(i=0; i<m; i++)
            gets(arr[i]);
        bfs();
    }
    return 0;
}
