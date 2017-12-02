#include <stdio.h>
int main ()
{
    int a,b,c,d,e1,e2;
    while((scanf("%d %d %d %d",&a,&b,&c,&d))==4)
    {
        if(a==0&&b==0&&c==0&&d==0)
        break;
        if(a==c&&b==d)
        printf("0\n");
        else if(a==c||b==d)
        printf("1\n");
        else
        {
            if(a>c)
            e1=a-c;
            else
            e1=c-a;
            if(b>d)
            e2=b-d;
            else
            e2=d-b;
            if(e1==e2)
            printf("1\n");
            else
            printf("2\n");
        }
    }
    return 0;
}
