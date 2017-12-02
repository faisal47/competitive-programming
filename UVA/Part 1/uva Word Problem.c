#include <stdio.h>
#include <string.h>
int arr1[1050][200],arr2[200],flag;
int main ()
{
    char arr[20];
    int c=0,len,i,j,z,d;
    while(1)
    {
        gets(arr);
        len=strlen(arr);
        if(len==1&&arr[0]=='#')
        break;
        for(i=0;i<len;i++)
        {
            z=arr[i];
            ++arr1[c][z];
        }
        ++c;
    }
    d=c;
    while(1)
    {
        gets(arr);
        len=strlen(arr);
        if(len==1&&arr[0]=='#')
        break;
        flag=0;c=0;
        for(i=0;i<len;i++)
        {
            if(arr[i]!=' ')
            {
                z=arr[i];
                ++arr2[z];
            }
        }
        for(i=0;i<d;i++)
        {
            for(j=97;j<=122;j++)
            {
                if(arr2[j]<arr1[i][j])
                flag=1;
            }
            if(flag==0)
            ++c;
            flag=0;
        }
        for(i=97;i<=122;i++)
        arr2[i]=0;
        printf("%d\n",c);
    }
    return 0;
}
