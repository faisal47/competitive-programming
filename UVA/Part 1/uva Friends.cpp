#include <stdio.h>
#include <iostream>
using namespace std;
int max1,par[35000],count[35000];
int parent(int a)
{
    if(par[a]==a)
    return a;
    else
    return par[a]=parent(par[a]);
}
void making_connection(int a,int b)
{
    int u=parent(a);
    int v=parent(b);
    if(u!=v)
    {
        par[u]=v;
        count[v]+=count[u];
        if(count[v]>max1)
        max1=count[v];
    }
    return;
}
int main ()
{
    int test,m,n,i,j;
    cin>>test;
    while(test--)
    {
        max1=1;
        cin>>m>>n;
        for(i=1;i<=m;i++)
        {
            par[i]=i;
            count[i]=1;
        }
        while(n--)
        {
            cin>>i>>j;
            making_connection(i,j);
        }
        cout<<max1<<endl;
    }
    return 0;
}
