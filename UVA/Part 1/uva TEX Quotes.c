#include <stdio.h>
#include <string.h>
int main ()
{
    unsigned len,i,flag=0;
    char arr[10000];
    while(gets(arr))
    {
        len=strlen(arr);
        for(i=0;i<len;i++)
        {
            if(flag==0&&arr[i]=='"')
            {printf("``");flag=1;}
            else if(flag==1&&arr[i]=='"')
            {
                printf("''");flag=0;
            }
            else
            printf("%c",arr[i]);
        }
        printf("\n");
    }
    return 0;
}
