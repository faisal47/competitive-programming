#include <stdio.h>
int main ()
{
    unsigned long m,n,a,b,t,i;
    scanf("%lu",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lu %lu",&m,&n);
        m-=2;n-=2;
        a=m/3;
        if((m%3)!=0)
        a+=1;
        b=n/3;
        if((n%3)!=0)
        b+=1;
        printf("%lu\n",(a*b));
    }
    return 0;
}
