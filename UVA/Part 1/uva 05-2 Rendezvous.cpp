#include <stdio.h>
#include <iostream>
#include <map>
#define inf 1<<28
using namespace std;
int main ()
{
    long long dist[25][25],n,a,b,m,i,j,k,t=1;
    map<string,int>m1;
    map<int,string>m2;
    char arr[15],z;
    while(scanf("%lld %lld",&n,&m)==2)
    {
        if(n==0)
        break;
        scanf("%c",&z);
        for(i=1;i<=n;i++)
        {
            gets(arr);
            m1[arr]=i;
            m2[i]=arr;
//            scanf("%c",&z);
        }
//        for(i=1;i<=n;i++)
//        printf("%s\n",m2[i]);
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(i==j)
        dist[i][j]=0;
        else
        dist[i][j]=inf;
        while(m--)
        {
            cin>>a>>b>>i;
            dist[a][b]=i;
            dist[b][a]=i;
        }
        for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        a=inf;
        for(i=1;i<=n;i++)
        {
            b=0;
//            cout<<"hello"<<endl;
            for(j=1;j<=n;j++)
            b+=dist[i][j];
//            cout<<b<<endl;
            if(a>b)
            {
                a=b;
                k=i;
            }
        }
//        printf("Case #%lld : %s\n",t++,m2[k]);
        cout<<"Case #"<<t++<<" : "<<m2[k]<<endl;
        m1.clear();
        m2.clear();
    }
    return 0;
}
