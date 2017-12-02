#include <stdio.h>
int main ()
{
    unsigned long long m=2,n,count=1;
    int flag1,flag2,flag3,flag4;
    while(1)
    {
        flag1=flag2=flag3=flag4=0;
        n=m;
        if(flag4==0)
        {
            while(1)
            {
                if(n%2==0&&flag1==0)
                {
                    while(1)
                    {
                        n/=2;
                        if((n%2)!=0)
                        break;
                    }
                }
                else if(n%3==0&&flag2==0)
                {
                     while(1)
                    {
                        n/=3;
                        if((n%3)!=0)
                        break;
                    }
                }
                else if(n%5==0)
                {

                     while(1)
                    {
                        n/=5;
                        if((n%5)!=0)
                        break;
                    }
                }
                else if(n==1)
                {
                    flag3=1;
                    break;
                }
                else
                {
                    flag3=2;
                    break;
                }
            }
        }
        if(flag3==1)
        {
            printf("%llu\n",m);
            count++;
        }
        if(count==1500)
        {
            printf("The 1500'th ugly number is %llu.",m);
            break;
        }
        m++;
    }
    return 0;
}
