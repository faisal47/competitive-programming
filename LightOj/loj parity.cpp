#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    unsigned long long n;
    int i,arr1[35],a,b,m,count,test,t;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        count=0;
         m=0;
         cin>>n;
        while(1)
        {
            a=n/2;
            b=n%2;
            arr1[m]=b;
            n=a;
            if(b==1)
            count++;
            if(a==0)
                break;
            m++;
        }
        if(count%2==0)
        printf("Case %d: even\n",t);
        else
        printf("Case %d: odd\n",t);
    }
    return 0;
}

