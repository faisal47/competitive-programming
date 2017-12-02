#include <stdio.h>
int main ()
{
    int i,t,c,d;
    double e;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&c,&d);
        e=(((double)d*5)/(double)9);
        e+=(double)c;
        printf("Case %d: %.2lf\n",i,e);
    }
    return 0;
}
