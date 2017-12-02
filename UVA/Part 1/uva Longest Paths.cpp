#include <stdio.h>
#include <iostream>
using namespace std;
#define inf 1<<28
int main ()
{
    int dist[102][102],n,i,s,k,e,ans,t=1,j;
    while(cin>>n)
    {
        if(n==0)
        break;
        cin>>s;
        for(k=1;k<=n;k++)
        for(j=1;j<=n;j++)
        dist[k][j]=inf;
        while(cin>>i>>j)
        {
            if(i==0&&j==0)
            break;
            dist[i][j]=1;
        }
        e=n;ans=0;
        for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            {
                if(dist[i][k]!=inf && dist[k][j]!=inf)
                {
                    if(dist[i][j]!=inf)
                    dist[i][j]=max(dist[i][j],dist[i][k]+dist[k][j]);
                    else
                    {
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        for(i=1;i<=n;i++)
        {
            if(ans<dist[s][i] && dist[s][i]!=inf)
            {
                ans=dist[s][i];
                e=i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",t++,s,ans,e);
    }
    return 0;
}
