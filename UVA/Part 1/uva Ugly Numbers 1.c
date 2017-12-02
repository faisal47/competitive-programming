#include <stdio.h>
int main ()
{
   unsigned long long arr[1550],i,a=2,b=3,c=5,c11=0,c22=0,c33=0,a1=2,b1=3,c1=5,flag1=0,flag2=0,flag3=0;
    for(i=2; i<2000; i++)
    {
        if((a<b&&a<c)||(a<=b&&a<c)||(a<b&&a<=c))
        {
            if(a==b)
            flag1=1;
            if(a==c)
            flag3=1;
            if(flag3==0)
                arr[i]=a;
            printf("%llu\n",a);

            ++c11;
            if(c11==1)
                a=a1*2;
            else if(c11==2)
                a=a1*3;
            else
            {
                c11=0;
                a=a1*5;
                a1*=2;
            }
        }
        else if((b<a&&b<c)||(b<a&&b<c)||(b<a&&b<=c)||flag1==1)
        {
            if(b==c)
            flag2=1;
            if(flag1==0)
            {
                printf("%llu\n",b);
            arr[i]=b;
            }
            ++c22;
            if(c22==1)
                b=b1*2;
            else if(c22==2)
                b=b1*3;
            else
            {
                c22=0;
                b=b1*5;
                b1*=3;
            }
            flag1=0;
        }
        else if(flag3==1||(c<a&&c<b)||(c<=a&&c<b)||(c<a&&c<b)||flag2==1)
        {
            if(flag2==0)
            {
                printf("%llu\n",c);
            arr[i]=c;
            }
            ++c33;
            if(c33==1)
                c=c1*2;
            else if(c33==2)
                c=c1*3;
            else
            {
                c33=0;
                c=c1*5;
                c1*=5;
            }
            flag2=0;flag3=0;
        }
    }
    printf("%llu\n",arr[1500]);
    return 0;
}
