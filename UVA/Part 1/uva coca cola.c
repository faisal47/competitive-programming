#include <stdio.h>
int main ()
{
    int a,n,b;
    while((scanf("%d",&n))==1)
    {a=0;
        if(n==0)
        break;
        a=n/2;
        printf("%d\n",a);
    }
    return 0;
}
