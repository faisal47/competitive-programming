#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define inf 1<<28
int dist[105][105];
int n,ans;
int main ()
{
    int i,j,k;
    char arr[1000],*ptr,z;
    while(scanf("%d",&n)==1)
    {
        scanf("%c",&z);
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(i==j)
        dist[i][j]=0;
        else
        dist[i][j]=inf;
        for(i=2;i<=n;i++)
        {
            gets(arr);
            j=1;
            ptr=strtok(arr," ");
            while(ptr!=NULL)
            {
                if(strcmp(ptr,"x")==0)
                dist[i][j]=dist[j][i]=inf;
                else
                dist[i][j]=dist[j][i]=atoi(ptr);
                j++;
                ptr=strtok(NULL," ");
            }
        }
        ans=-inf;
        for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        for(i=1;i<=n;i++)
        ans=max(ans,dist[1][i]);
        cout<<ans<<endl;
    }
    return 0;
}
