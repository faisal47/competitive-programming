#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    long long n,b,h,w,res,i,p,a,flag1,inf=123456789;
    while(cin>>n>>b>>h>>w)
    {
        res=inf;
        while(h--)
        {
            flag1=0;
            cin>>p;
            for(i=0; i<w; i++)
            {
                cin>>a;
                if(a<n)
                    ;
                else
                {
                    a=p*n;
                    if(a<=b)
                        res=min(a,res);
                }
            }
        }
        if(res==inf)
            cout<<"stay home"<<endl;
        else
            cout<<res<<endl;
    }
    return 0;
}
