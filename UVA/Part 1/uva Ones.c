#include <stdio.h>
int main ()
{
    unsigned long n,m,c;
    while((scanf("%lu",&n))==1)
    {
        m=1;c=1;
        if((n%2!=0)&&(n%5!=0))
        {
            while(1)
            {
                if(m>=n)
                m%=n;
                if(m==0)
                break;
                m=(m*10)+1;c++;
            }
            printf("%lu\n",c);
        }
    }
    return 0;
}
