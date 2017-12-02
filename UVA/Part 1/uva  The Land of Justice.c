#include <stdio.h>
int main ()
{
    long long int a;
    while((scanf("%lld",&a))==1)
    {
        if(a<0)
        break;
        if(a==1)
        printf("0%%\n");
        else
        printf("%lld%%\n",25*a);
    }
    return 0;
}
