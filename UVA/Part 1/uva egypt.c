#include <stdio.h>
int main ()
{
    long int a,b,c;
    while((scanf("%ld%ld%ld",&a,&b,&c))==3)
    {
        if(a==0&&b==0&&c==0)
        break;
        if(((a*a)+(b*b)==(c*c))||((c*c)+(b*b)==(a*a))||((a*a)+(c*c)==(b*b)))
        printf("right\n");
        else
        printf("wrong\n");
    }
    return 0;
}
