#include <stdio.h>
#include <string.h>
int main ()
{
    char arr1[1005],arr2[1005];
    int i,a,len1,len2,arr[130],arr3[130];
    while(gets(arr1))
    {
        gets(arr2);
        len1=strlen(arr1);
        len2=strlen(arr2);
        for(i=97;i<130;i++)
            {
                 arr[i]=0;
                 arr3[i]=0;
            }
        if(len1<=len2)
        {
            for(i=0;i<len2;i++)
            {
                a=arr2[i];
                ++arr3[a];
            }
            for(i=0;i<len1;i++)
            {
                a=arr1[i];
                if(arr3[a]>0)
                ++arr[a];
            }
        }
        else if(len1>len2)
        {
            for(i=0;i<len1;i++)
            {
                a=arr1[i];
                ++arr3[a];
            }
            for(i=0;i<len2;i++)
            {
                a=arr2[i];
                if(arr3[a]>0)
                ++arr[a];
            }
        }
        for(i=97;i<130;i++)
        {
            if(arr[i]>0)
            printf("%c",i);
        }
        printf("\n");
    }
    return 0;
}
