#include <stdio.h>
int main ()
{
    int a,b,c,d,m,n;
    while((scanf("%d %d %d %d",&a,&b,&c,&d))==4)
    {
        if(a==0&&b==0&&c==0&&d==0)
            break;
        m=0;
        n=0;
        if(a==c&&b<=d)
        m=(d-b);
        else
        {
            m=(60-b)+d;
            a+=1;
            while(1)
            {
                if(a==24)
                a=0;
                if(a==c)
                    break;
                a++;
                n++;
            }
            m+=(n*60);
        }
        printf("%d\n",m);
    }
    return 0;
}
