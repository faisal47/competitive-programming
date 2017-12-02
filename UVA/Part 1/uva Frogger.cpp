#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
double arr[205][3];
int test=1,i,j,k,n;
double dis[205][205],mini;
void init()
{
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if(i==j)
    dis[i][j]=0;
    else
    dis[i][j]=100000.;
    return;
}
void fw()
{
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
        dis[j][k]=min(dis[j][k],max(dis[j][i],dis[i][k]));
    }
    return;
}
int main ()
{
    while(cin>>n)
    {
        if(n==0)
        break;
        mini=100000.;
        for(i=0;i<n;i++)
        cin>>arr[i][0]>>arr[i][1];
        init();
        for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        dis[i][j]=dis[j][i]=sqrt(pow(arr[i][0]-arr[j][0],2.)+pow(arr[i][1]-arr[j][1],2.));
        fw();
//        for(i=0;i<n-1;i++)
//        for(j=i+1;j<n;j++)
//        mini=min(mini,dis[i][j]);
        printf("Scenario #%d\nFrog Distance = %.3lf\n",test++,(dis[0][1]));
        cout<<endl;
    }
    return 0;
}
