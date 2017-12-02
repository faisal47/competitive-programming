#include <stdio.h>
int main ()
{
    long long int a,i,b,c,d,e,temp,f,g;
    while((scanf("%lld%lld",&a,&e))==2)
    {d=1;
    if(a>e)
    {
        f=a;
        g=e;
        temp=a;
        a=e;
        e=temp;

    }
        for(i=a;i<=e;i++)
        {c=i;
        b=1;
            while(1)
            {
                if(c==1)
                break;
                else if((c%2)==1)
                {
                    c=((3*c)+1);
                }
                else if((c%2)==0)
                {
                    c=(c/2);
                }
                b++;
            }
            if(b>d)
            {
                d=b;
            }
        }

        if(f>g)
        {
            printf("%lld %lld %lld\n",f,g,d);
        }
        else
        {
             printf("%lld %lld %lld\n",a,e,d);
        }
        f=0;g=0;
    }

    return 0;
}
