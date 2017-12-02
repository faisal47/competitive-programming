#include <stdio.h>
int main ()
{
    int t,n,i,j,mile,juice,a,b,c,d;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        mile=juice=a=b=c=d=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            b=a/30;c=a/60;
            b+=1;c+=1;
            mile+=(b*10);
            juice+=(c*15);
        }
        if(mile<juice)
        printf("Case %d: Mile %d\n",j,mile);
        else if(mile>juice)
        printf("Case %d: Juice %d\n",j,juice);
        else
        printf("Case %d: Mile Juice %d\n",j,mile);
    }
    return 0;
}
