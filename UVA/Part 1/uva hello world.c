#include <stdio.h>
int main ()
{
    long int n,i,m,a,b=1;
    while((scanf("%ld",&n))==1)
    {
        if(n<0)
        break;
        m=0;a=1;
        while(1)
        {
           if(a>=n)
            break;
            a*=2;
            m++;
        }
        printf("Case %ld: %ld\n",b,m);
        b++;
    }
    return 0;
}
