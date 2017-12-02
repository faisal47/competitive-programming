#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    int ins[35],n,m,t,i,j,a,res;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(ins,0,sizeof(ins));
        res=1;
        for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            cin>>a;
            if(a==1)
            ins[j]++;
        }
        for(j=1;j<=n;j++)
        if(ins[j]>0)
        res*=ins[j];
        cout<<res<<endl;
    }
    return 0;
}
