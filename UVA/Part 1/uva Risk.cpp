#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
bool arr[25][25],color[25];
int dist[25],c;
void bfs(int i,int j)
{
    int temp,u,v,a=i,b=j,flag=0;
    queue<int>q;
    q.push(i);
    color[i]=1;
    while(!q.empty())
    {
        i=q.front();
        q.pop();
        for(j=1;j<=20;j++)
        {
            if(color[j]==0&&arr[i][j]==1&&arr[j][i]==1)
            {
                color[j]=1;
                q.push(j);
                dist[j]=dist[i]+1;
                if(j==b)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
        break;
    }
    printf("%2d to %2d: %d\n",a,b,dist[b]);
    return;
}
int main ()
{
    c=1;
    memset(arr,0,sizeof(arr));
    int a,n,m=1,i,j,flag=0;
    while(cin>>a)
    {
        m=1;flag=0;
        while(a--)
        {
            cin>>n;
            arr[m][n]=arr[n][m]=1;
        }
        for(m=2; m<20; m++)
        {
            cin>>a;
            while(a--)
            {
                cin>>n;
                arr[m][n]=arr[n][m]=1;
            }
        }
        cin>>a;
        for(m=1;m<=a;m++)
        {
            cin>>i>>j;
            memset(color,0,sizeof(color));
            memset(dist,0,sizeof(dist));
            if(flag==0)
            {
                printf("Test Set #%d\n",c++);
                flag=1;
            }
            bfs(i,j);
        }
        cout<<endl;
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
