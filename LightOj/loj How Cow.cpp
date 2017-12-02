#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    int x1,x2,y1,y2,test,t,n,a,b,flag;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        printf("Case %d:\n",t);
        cin>>x1>>y1>>x2>>y2;
        cin>>n;
        while(n--)
        {
            flag=0;
            cin>>a>>b;
            if(a<x1||a>x2||b<y1||b>y2)
            flag=1;
            if(flag==1)
            cout<<"No\n";
            else
            cout<<"Yes\n";
        }
    }
    return 0;
}
