#include <stdio.h>
int main ()
{
    long long int a,b,i,n,m,o,p,q,d,arr[1000],arr1[1000];
    while((scanf("%lld%lld",&a,&b))==2)
    {if(a==0&&b==0)
        break;
        m=a;
        o=0;
        n=b;
        while(1)
        {
            if(m==0)
                break;
            p=m/10;
            arr[o]=m%10;
            m=p;
            o++;
        }
        q=0;
        while(1)
        {
            if(n==0)
                break;
            p=n/10;
            arr1[q]=n%10;
            n=p;
            q++;
        }
        if(o>q)
        {
            for(i=q;i<o;i++)
            {
                arr1[i]=0;
            }
            d=o;
        }
        else if(o<q)
        {
            for(i=o;i<q;i++)
            {
                arr[i]=0;
            }
            d=q;
        }
        else
        {
            d=o;
        }
         int e,f=0,g=0;
        for(i=0;i<d;i++)
        {
            e=arr[i]+arr1[i]+f;
            f=e/10;
            if(f==1)
            {
                g++;
            }
        }
        if(g==0)
        {
            printf("No carry operation.\n");
        }
        else if(g==1)
        {
            printf("1 carry operation.\n");
        }
        else
        {
            printf("%d carry operations.\n",g);
        }

    }
    return 0;
}
