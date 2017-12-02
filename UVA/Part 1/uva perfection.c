#include <stdio.h>
int main ()
{
    int n,flag=1,i,m,p;
    while((scanf("%d",&n))==1)
    {
        if(flag==1)
        {
            printf("PERFECTION OUTPUT\n");
            flag=0;
        }
        if(n==0&&flag==0)
        {
            printf("END OF OUTPUT\n");
            break;
        }
        m=1;
        p=n/2;
        for(i=2; i<=p; i++)
        {
            if(n%i==0)
                m+=i;
        }
        if(n==1)
        printf("%5d  DEFICIENT\n",n);
        else if(m==n)
        printf("%5d  PERFECT\n",n);
        else if(m<n)
        printf("%5d  DEFICIENT\n",n);
        else
        printf("%5d  ABUNDANT\n",n);
    }
    return 0;
}
