#include <stdio.h>
#include <string.h>
#include <math.h>
int main ()
{
    char arr1[110020],arr2[10020],z;
    int t,i,len,a,c,j,k;
    scanf("%d%c",&t,&z);
    for(i=0;i<t;i++)
    {
        c=0;
        gets(arr1);
        len=strlen(arr1);
        a=sqrt(len);
        if((a*a)==len)
        {
            for(j=0;j<a;j++)
            for(k=0;k<a;k++)
            {
                arr2[c++]=arr1[j+(a*k)];
            }
            arr2[len]='\0';
            printf("%s",arr2);
        }
        else
        printf("INVALID");
        printf("\n");
    }
    return 0;
}
