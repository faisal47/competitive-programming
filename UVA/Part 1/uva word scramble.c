#include <stdio.h>
#include <string.h>
int main ()
{
    char arr[1000],arr1[1000];
    int a,i,m,j,n,flag;
    while(gets(arr))
    {
        a=strlen(arr);
        m=0;
        n=0;
        flag=0;
        for(i=0; i<a; i++)
        {
            if(arr[i]==' ')
            {
                flag=1;
                for(i=0; i<a; i++)
                {
                    if(arr[i]==' ')
                    {
                        arr1[i]=arr[i];
                        for(j=i-1; j>=(i-m); j--)
                        {
                            arr1[n]=arr[j];
                            n++;
                        }
                        n+=1;
                        m=0;
                    }
                    else
                        m++;
                }
                for(i=(a-1); i>=0; i--)
                {
                    if(arr[i]==' ')
                    {
                        for(j=(a-1); j>i; j--)
                        {
                            arr1[n]=arr[j];
                            n++;
                        }
                        break;
                    }
                }
                for(i=0;i<a;i++)
                {
                    printf("%c",arr1[i]);
                }
                printf("\n");

                break;
            }
        }
        if(flag==1)
        ;
        else
        {
            {
                for(i=(a-1);i>-1;i--)
                printf("%c",arr[i]);
                }
                printf("\n");
                }

    }
    return 0;
}
