#include <stdio.h>
int main ()
{
    int n,i,j,a,b,c,d;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    scanf("%d%d%d",&a,&b,&c);
    {d=b;
     for(j=0;j<c;j++)
     {if(d==a)
         d=0;
         d+=1;}
    }
    printf("Case %d: %d\n",i,d);

    }
    return 0;
}
