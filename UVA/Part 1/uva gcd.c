#include <stdio.h>
int main ()
{
    int gcd,b,i,j,k;
    while((scanf("%d",&b))==1)
    {
        if(b==0)
        break;
        gcd=0;
        for(i=1;i<b;i++)
        {for (j=i+1;j<=b;j++)
            {
                for(k=i; i<j; k--)
                {if(((i%k)==0)&&((j%k)==0))
                    {gcd+=k;break;}}}}printf("%d\n",gcd);}return 0;}
