#include <stdio.h>
int main ()
{
    int a,b,c;
    while((scanf("%d%d",&a,&b))==2)
    {c=0;
        c=((a*b)-1);
        printf("%d\n",c);
    }
    return 0;
}
