#include <stdio.h>
int main ()
{
    int n,a,b,c=0,d,arr[1000],i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {c=0;
        scanf("%d%d",&a,&b);
        for(j=a;j<=b;j++)
        {
            if(j%2==1)
            {
                c+=j;
            }
        }
        printf("Case %d: %d\n",(i+1),c);
    }
    return 0;
}
