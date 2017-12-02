#include <stdio.h>
int main ()
{
    int t,i;
    unsigned long long n,m,p,a;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%llu",&n);
        m=n;
        while(1)
        {
            if(m==4)
            {
                printf("Case #%d: %llu is an Unhappy number.\n",i,n);
                break;
            }
            else if(m==1)
            {
                printf("Case #%d: %llu is a Happy number.\n",i,n);
                break;
            }
            p=m;m=0;
            while(1)
            {
                a=p%10;
                p/=10;
                m+=(a*a);
                if(p==0)
                break;
            }
        }
    }
    return 0;
}
