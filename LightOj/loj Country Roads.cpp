#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    unsigned long arr[520][520],n,m,i,j,inf=123456789,w,k,max1;
    int test,t;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(i==j)
            arr[i][j]=0;
            else
            arr[i][j]=inf;
        }
        while(m--)
        {
            cin>>i>>j>>w;
            arr[i][j]=arr[j][i]=w;
        }
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        for(k=0;k<n;k++)
        {
            max1=max(arr[i][k],arr[k][j]);
            arr[i][j]=min(arr[i][j],max1);
        }
        cin>>k;
        printf("Case %d:\n",t);
        for(i=0;i<n;i++)
        {
            if(arr[k][i]>=inf)
            cout<<"Impossible"<<endl;
            else
            cout<<arr[k][i]<<endl;
        }
    }
    return 0;
}
