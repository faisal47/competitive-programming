
#include <stdio.h>
#include <iostream>
#define inf 123456789
using namespace std;
int n,dist[105][105];
void fw()
{
    int i,j,k;
    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    return;
}
void init()
{
    int i,j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=inf;
    return;
}
int main ()
{
    int t,test,i,a,b,r,maximum;
    cin>>test;
    for(t=1; t<=test; t++)
    {
        cin>>n>>r;
        init();
        maximum=0;
        for(i=0; i<r; i++)
        {
            cin>>a>>b;
            dist[a][b]=1;
            dist[b][a]=1;
        }
        cin>>a>>b;
        fw();
        for(i=0;i<n;i++)
        maximum=max(maximum,dist[a][i]+dist[i][b]);
        printf("Case %d: %d\n",t,maximum);
    }
    return 0;
}
