#include <stdio.h>
#include <string.h>
#include <math.h>
int main ()
{
    int t,i,a,j,l,k;
    char arr[10005],z;
    double b;
    scanf("%d%c",&t,&z);
    for(i=0; i<t; i++)
    {
        gets(arr);
        a=strlen(arr);
        b=sqrt(a);
        if(a==0)
        ;
        else if((double)a/b!=b)
            printf("INVALID\n");
        else
        {
            l=(int)b;
            for(j=0; j<l; j++)
                for(k=0; k<l; k++)
                    printf("%c",arr[(l*k)+j]);
            printf("\n");
        }
    }
    return 0;
}
