#include <stdio.h>
int main ()
{
    unsigned long long n;
    int i,arr1[35],a,b,m,count;
    while((scanf("%llu",&n))==1)
    {
        count=0;
        if(n==0)
        break;
         m=0;
        while(1)
        {
            a=n/2;
            b=n%2;
            arr1[m]=b;
            n=a;
            if(b==1)
            count++;
            if(a==0)
                break;
            m++;
        }
        printf("The parity of ");
        for(i=m; i>=0; i--)
            printf("%d",arr1[i]);
            printf(" is %d (mod 2).\n",count);
    }
    return 0;
}

