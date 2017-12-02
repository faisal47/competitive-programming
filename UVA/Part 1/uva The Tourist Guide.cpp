#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
#define inf 1<<28
int main ()
{
    int n,dist[102][102],i,j,k,s,e,m,p,test=1;
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
        break;
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(i==j)
        dist[i][j]=0;
        else
        dist[i][j]=-inf;
        while(m--)
        {
            cin>>s>>e>>p;
            dist[s][e]=p;
            dist[e][s]=p;
        }
        cin>>s>>e>>p;
        for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        dist[i][j]=max(dist[i][j],min(dist[i][k],dist[k][j]));
        printf("Scenario #%d\n",test++);
        printf("Minimum Number of Trips = ");
        cout<<ceil((p*1.0)/(dist[s][e]-1))<<endl<<endl;
    }
    return 0;
}
