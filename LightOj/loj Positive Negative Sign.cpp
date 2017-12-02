#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    long long int res,n,a,b,m;
    bool flag;
    int test,t;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>n>>m;
        a=b=1;
        flag=res=0;
        while(1)
        {
            if(flag==0)
            res-=a;
            else
            res+=a;
            a++;
            b++;
           // cout<<res<<endl;
            if(b>m&&flag==0)
            {
                b=1;flag=1;
            }
            else if(b>m&&flag==1)
            {
                b=1;flag=0;
            }
            if(a>n)
            break;
        }
        printf("Case %d: %lld\n",t,res);
    }
    return 0;
}
