#include <stdio.h>
int main ()
{
    int a,b,n,i,c,d;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d%d",&a,&b);
        if((a%2==1)&&(b%2==0))
        {
            printf("impossible\n");
        }
        else if((a%2==0)&&(b%2==1))
        {
            printf("impossible\n");
        }
        else
        {
            c=((a+b)/2);
            d=((a-b)/2);
            if(c>=0&&d>=0)
            {

                if(c>d)
                {
                    printf("%d %d\n",c,d);
                }
                else
                {
                    printf("%d %d\n",d,c);
                }
            }
            else
            {
                printf("impossible\n");
            }

        }
    }
    return 0;
}
