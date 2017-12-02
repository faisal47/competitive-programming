#include <stdio.h>
#include <iostream>
using namespace std;
#define inf 1<<28
int main ()
{
    int dist[105][105],i,j,k,n,m,p,test=0;
    while(cin>>n>>m>>p)
    {
        if(n==0 && m==0 && p==0)
        break;
        if(test++)
        cout<<endl;
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(i==j)
        dist[i][j]=0;
        else
        dist[i][j]=inf;
        while(m--)
            {
                cin>>i>>j>>k;
                dist[j][i]=dist[i][j]=k;
            }
        for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        dist[i][j]=min(dist[i][j],max(dist[i][k],dist[k][j]));
        printf("Case #%d\n",test);
        while(p--)
        {
            cin>>i>>j;
            if(dist[i][j]!=inf)
            cout<<dist[i][j]<<endl;
            else
            cout<<"no path\n";
        }
    }
    return 0;
}
