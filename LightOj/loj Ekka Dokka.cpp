#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
    long long int n,i,c,limit;
    int test,t,flag;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        flag=0;
        cin>>n;
        if(n%2==1)
        {
            printf("Case %d: Impossible\n",t);
            continue;
        }
        limit++;
        for(i=2;i<n;i+=2)
        {
                c=n/i;
                if(c%2==1&&(c*i)==n)
                {
                    flag=1;
                    printf("Case %d: %lld %lld\n",t,c,i);
                    break;
                }
        }
        if(flag==0)
        printf("Case %d: Impossible\n",t);
    }
    return 0;
}
