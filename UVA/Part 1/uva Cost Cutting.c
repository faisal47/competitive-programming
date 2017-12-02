#include <stdio.h>
int main ()
{
    long int n,a,b,c,i;
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%ld%ld%ld",&a,&b,&c);
        if(a<b&&b<c)
        {
            printf("Case %ld: %ld\n",i,b);
        }
        else if(b<a&&a<c)
        {
            printf("Case %ld: %ld\n",i,a);
        }
        else if(a<c&&c<b)
        {
            printf("Case %ld: %ld\n",i,c);
        }
        else if(c<a&&a<b)
        {
            printf("Case %ld: %ld\n",i,a);
        }
        else if(b<c&&c<a)
        {
            printf("Case %ld: %ld\n",i,c);
        }
        else if(c<b&&b<a)
        {
            printf("Case %ld: %ld\n",i,b);
        }
    }
    return 0;
}
