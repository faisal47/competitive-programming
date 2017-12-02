#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    unsigned long long a,b,c,d,test,t,n;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>n;
        for(a=2;a<=n/2;a++)
        {
            if((n%a)==0)
            {
                b=n/a;
                break;
            }
        }
        for(c=a+1;c<=n/2;c++)
        {
            if((n%c)==0)
            {
                d=n/c;
                break;
            }
        }
        printf("Case #%llu: %llu = %llu * %llu = %llu * %llu\n",t,n,a,b,c,d);
    }
    return 0;
}
