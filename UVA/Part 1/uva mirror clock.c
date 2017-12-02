#include <stdio.h>
int main ()
{
    int i,n,a,b,m,o;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d:%d",&a,&b);
        if(a==12)
        m=12;
        else
        m=12-a;
        if(b==00)
        o=00;
        else if(a!=11)
        {
            o=60-b;m-=1;
        }
        else
        {
            o=60-b;m=12;
        }
        if(o<10&&m>9)
        printf("%d:0%d\n",m,o);
        else if(m<10&&o>9)
        printf("0%d:%d\n",m,o);
        else if(o<10&&m<10)
        printf("0%d:0%d\n",m,o);
        else
        printf("%d:%d\n",m,o);
    }
    return 0;
}
