#include <stdio.h>
#include <string.h>
int main ()
{
    char arr[1000],arr1[1000];
    int i,j,k,l,n,a,b;

    while(gets(arr))
    {   a=strlen(arr);
        for(i=0;i<a;i++)
        {
            if(arr[i]=='0'||arr[i]=='1'||arr[i]=='-')
            {
                arr1[i]=arr[i];
            }
            else if(arr[i]=='A'||arr[i]=='B'||arr[i]=='C')
            {
             arr1[i]='2';
            }
           else if(arr[i]=='D'||arr[i]=='E'||arr[i]=='F')
            {
             arr1[i]='3';
            }
            else if(arr[i]=='G'||arr[i]=='H'||arr[i]=='I')
            {
             arr1[i]='4';
            }
            else if(arr[i]=='J'||arr[i]=='K'||arr[i]=='L')
            {
             arr1[i]='5';
            }
            else if(arr[i]=='M'||arr[i]=='N'||arr[i]=='O')
            {
             arr1[i]='6';
            }
            else if(arr[i]=='P'||arr[i]=='Q'||arr[i]=='R'||arr[i]=='S')
            {
             arr1[i]='7';
            }
            else if(arr[i]=='T'||arr[i]=='U'||arr[i]=='V')
            {
             arr1[i]='8';
            }
            else if(arr[i]=='W'||arr[i]=='X'||arr[i]=='Y'||arr[i]=='Z')
            {
             arr1[i]='9';
            }
        }
        arr1[i]='\0';
        printf("%s\n",arr1);
    }
    return 0;
}
