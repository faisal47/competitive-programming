#include <iostream>
#include <stdio.h>
#include <math.h>
#define inf 123456789
using namespace std;
double dist[105][105];
int n;
struct graph
{
    double x,y;
};
graph g[105];
void fw()
{
    int i,j,k;
    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    return;
}
void make_dist()
{
    int i,j;
    double result;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(i!=j)
            {
                result=sqrt(pow((g[i].x-g[j].x),2.)+pow((g[i].y-g[j].y),2.));
                if(result<=10.)
                    dist[i][j]=result;
            }
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
    int test,t,i,j,flag;
    double maximum;
    cin>>test;
    for(t=1; t<=test; t++)
    {
        cin>>n;
        init();
        flag=0;
        for(i=0; i<n; i++)
            cin>>g[i].x>>g[i].y;
        make_dist();
        fw();
        maximum=0;
        for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                if(dist[i][j]<inf)
                    maximum=max(maximum,dist[i][j]);
                else
                {
                    flag=1;
                    break;
                }
                if(flag==1)
                break;
            }

        if(flag==1)
        printf("Case #%d:\nSend Kurdy\n\n",t);
        else
            printf("Case #%d:\n%.4lf\n\n",t,maximum);

    }
    return 0;
}
