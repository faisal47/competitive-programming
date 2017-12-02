#include <stdio.h>
int main ()
{//“Multiply n by 567, then divide the result by 9, then add 7492, then multiply by 235, then divide by 47, then subtract 498. What is the digit in the tens column?”
    long int m,n,i,j,a,b;
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {scanf("%d",&n);
       n=(n*567);
       n=n/9;
       n=n+7492;
       n=n*235;
       n=n/47;
       n=n-498;
       printf("%d\n",n);
    }
    return 0;
}
