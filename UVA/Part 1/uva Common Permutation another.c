#include <stdio.h>
#include <string.h>
int main ()
{
    char arr1[1005],arr2[1005];
    int arr3[130],arr4[130],i,a,len1,len2,j;
    while(gets(arr1))
    {
        gets(arr2);
        len1=strlen(arr1);len2=strlen(arr2);
        for(i=97;i<130;i++)
        {
            arr3[i]=0;arr4[i]=0;
        }
        for(i=0;i<len1;i++)
        {
            a=arr1[i];arr3[a]++;
        }
        for(i=0;i<len2;i++)
        {
            a=arr2[i];arr4[a]++;
        }
        for(i=97;i<130;i++)
        {
            if(arr3[i]<=arr4[i])
            {
                for(j=0;j<arr3[i];j++)
                printf("%c",i);
            }
            else
            {
                for(j=0;j<arr4[i];j++)
                printf("%c",i);
            }
        }
        printf("\n");
    }
    return 0;
}
