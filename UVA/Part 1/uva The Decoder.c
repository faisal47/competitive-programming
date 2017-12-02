#include <stdio.h>
#include <string.h>
int main ()
{
    char arr[2000];
    int n,i;
    while(gets(arr))
    {
        n=strlen(arr);
        for(i=0;i<n;i++)
        {
            printf("%c",arr[i]-7);
        }
        printf("\n");
    }
    return 0;
}
