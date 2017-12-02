#include <stdio.h>
int main ()
{
    int i,n,a,b,c;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a<=0||b<=0||c<=0||(a+b)<=c||(b+c)<=a||(c+a)<=b)
        printf("Wrong!!\n");
        else
        printf("OK\n");
    }
    return 0;
}
