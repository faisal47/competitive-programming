#include <stdio.h>
int main ()
{
    int n,m,a,b,c,d;
    while((scanf("%d %d",&n,&m))==2)
    {
        a=n;
        b=0;
        while(1)
        {
            if(a<m)
                break;
            d=(a/m);
            c=(a%m);
            a=(d+c);
            b+=d;
        }
        printf("%d\n",(n+b));
    }
    return 0;
}
