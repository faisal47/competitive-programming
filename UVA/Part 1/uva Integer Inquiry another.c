#include <stdio.h>
#include <string.h>
int arr2[105][105],arr3[105];
int main ()
{
    char arr1[105][105];
    int len,m=0,max=0,c;
    while(1)
    {
        gets(arr1[m]);
        if(strlen(arr1[m])==1&&arr1[m][0]=='0')
            break;
        m++;
    }
    int i,j,k,temp;
    for(i=0; i<m; i++)
    {
        len=strlen(arr1[i]);
        if(max<len)
            max=len;
        c=0;
        for(j=len-1; j>=0; j--)
            arr2[i][c++]=arr1[i][j]-'0';
    }
    c=0;
    len=0;
    for(i=0; i<max; i++)
    {
        for(j=0; j<m; j++)
        arr3[i]+=arr2[j][i];
        if(i!=(max-1))
        {
            if(arr3[i]>9)
            {
                temp=arr3[i];
                arr3[i]%=10;
                arr3[i+1]=temp/10;
            }
        }
    }
    for(i=max-1; i>=0; i--)
        printf("%d",arr3[i]);
        printf("\n");
    return 0;
}
