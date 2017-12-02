#include <stdio.h>
#include <math.h>
int main ()
{
    unsigned a,j,k,l,n,i,e,flag;
    scanf("%u",&n);
    for(i=0; i<n; i++)
    {
        flag=0;
        scanf("%u",&a);
        e=sqrt(a);
        for(j=0; j<=e; j++)
        {
            for(k=j; k<=e; k++)
            {
                for(l=k; l<=e; l++)
                {
                    if(a==((j*j)+(k*k)+(l*l)))
                    {
                        flag=1;break;
                    }
                }
                if(flag==1)
                break;
            }
            if(flag==1)
                break;
        }
        if(flag==1)
        printf("%u %u %u\n",j,k,l);
        else
        printf("-1\n");
    }
    return 0;
}
