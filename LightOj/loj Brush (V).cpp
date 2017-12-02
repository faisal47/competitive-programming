#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    int test,t,i,m,n,arr[105][105],inf=123456789,a,b,c,k,j;
    cin>>test;
    for(t=1; t<=test; t++)
    {
        cin>>m>>n;
        for(i=1; i<=m; i++)
            for(j=1; j<=m; j++)
            {
                if(i==j)
                    arr[i][j]=0;
                else
                    arr[i][j]=inf;
            }
        while(n--)
        {
            cin>>a>>b>>c;
            if(arr[a][b]>c)
                arr[a][b]=arr[b][a]=c;
        }
        for(k=1; k<=m; k++)
            for(i=1; i<=m; i++)
                for(j=1; j<=m; j++)
                    arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
        if(arr[1][m]>=inf)
        printf("Case %d: Impossible\n",t);
        else
        printf("Case %d: %d\n",t,arr[1][m]);
    }
    return 0;
}
