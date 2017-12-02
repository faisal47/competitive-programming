#include <stdio.h>
int main ()
{
    int n,a,b,c,m,o;
    while((scanf("%d",&n))==1)
    {a=0;
        if(n==0)
        break;
    while(n>=3)
    {
        m=n/3;
        o=n%3;
        n=(m+o);
        a+=m;
    }
    if(o!=0)
    {
        a+=1;
    }
    printf("%d\n",a);
    }
    return 0;
}
