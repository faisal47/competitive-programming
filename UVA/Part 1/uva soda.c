
#include <stdio.h>
int main ()
{
    int i,n,m,a,b,c,d,e,z;
    scanf("%d",&z);
    for(i=0; i<z; i++)
    {scanf("%d %d %d",&n,&e,&m);
        n=n+e;
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
        printf("%d\n",b);
    }

    return 0;
}
