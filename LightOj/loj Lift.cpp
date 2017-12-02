#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    int m,n,test,t,res,dif;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>m>>n;
        if(m<=n)
        {
            res=19;
            res+=(n*4);
            printf("Case %d: %d\n",t,res);
        }
        else
        {
            dif=m-n;
            res=19;
            res+=(m*4);
            res+=(dif*4);
            printf("Case %d: %d\n",t,res);
        }
    }
    return 0;
}
