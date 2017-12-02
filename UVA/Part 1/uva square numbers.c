#include <stdio.h>
#include <stdlib.h>
int main ()
{
    long int a,b,j,i,c;
    while((scanf("%ld%ld",&a,&b))==2)
    {
        if(a==0&&b==0)
        break;
        j=0;
        for(i=a;i<=b;i++)
        {
            c=sqrt(i);
            if((c*c)==i)
            j++;
        }
        printf("%ld\n",j);
    }
    return 0;
}
