#include <stdio.h>
#include <string.h>
int main ()
{
    char arr[1000];
    int m,n,a,i;
    while(gets(arr))
    {m=0;
    n=0;
        a=strlen(arr);
        for(i=0;i<a;i++)
        {
            if((m==0)&&((arr[i]>='a'&&arr[i]<='z')||(arr[i]>='A'&&arr[i]<='Z')))
            {
                m=1;
                n++;
            }
            else if ((arr[i]>='a'&&arr[i]<='z')||(arr[i]>='A'&&arr[i]<='Z'))
            ;
            else
            {
                m=0;
            }
        }
        printf("%d\n",n);
    }
    return 0;
}
