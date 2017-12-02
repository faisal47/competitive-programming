#include <stdio.h>
int main ()
{
    long long int a,b,c;
    int n,i;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        if(((a+b)<=c)||((a+c)<=b)||((c+b)<=a)||a<1||b<1||c<1)
            printf("Case %d: Invalid\n",i);
        else if((a==b)&&(b==c)&&(c==a))
            printf("Case %d: Equilateral\n",i);
        else if((a==b)||(b==c)||(c==a))
            printf("Case %d: Isosceles\n",i);
        else if((a!=b)&&(b!=c)&&(c!=a))
            printf("Case %d: Scalene\n",i);
    }
    return 0;
}
