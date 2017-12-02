#include <stdio.h>
int main ()
{
    int a,b,i,j,k,m,n,o,p,c;
    while((scanf("%d%d",&a,&b))==2)

    {
        if(a==0&&b==0)
        break;
    n=0;
        for(i=a;i<=b;i++)
        {o=i;
        j=i;
        m=0;
            while(j>1)
            {
                if(j==1)
                break;
                else if((j%2)==0)
                {
                 j=(j/2);
                }
                else if((j%2)==1)
                {
                    j=((3*j)+1);
                }

                m++;
            }
            if(m>n)
            {
             c=o;
             n=m;
            }
        }
       printf("Between %d and %d, %d generates the longest sequence of %d values.\n",a,b,c,n);
    }
    return 0;
}
