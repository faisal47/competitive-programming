#include <stdio.h>
#include <string.h>
int main ()
{
    char arr[30],arr1[30],arr2[30];
    int len,i,j,k,l,m,flag,flag2,flag3;
    while(scanf("%s",arr)==1)
    {
        flag=flag2=flag3=0;
        len=strlen(arr);
        m=len-1;
        for(i=0; i<len; i++)
        {
            arr1[i]=arr[m];
            m--;
        }
        arr1[i]='\0';
        if(strcmp(arr,arr1)==0)
            flag=1;
        for(i=0; i<len; i++)
        {
            if(arr[i]=='E')
                arr2[i]='3';
            else if(arr[i]=='J')
                arr2[i]='L';
            else if(arr[i]=='L')
                arr2[i]='J';
            else if(arr[i]=='S')
                arr2[i]='2';
            else if(arr[i]=='Z')
                arr2[i]='5';
            else if(arr[i]=='2')
                arr2[i]='S';
            else if(arr[i]=='3')
                arr2[i]='E';
            else if(arr[i]=='5')
                arr2[i]='Z';
            else if(arr[i]=='A'||arr[i]=='H'||arr[i]=='I'||arr[i]=='M'||arr[i]=='O'||arr[i]=='T'||arr[i]=='U'||arr[i]=='V'||arr[i]=='W'||arr[i]=='X'||arr[i]=='Y'||arr[i]=='1'||arr[i]=='8')
                arr2[i]=arr[i];
            else
            {
                flag2=1;
                break;
            }
        }
        arr2[i]='\0';
        if(flag2==0)
            if(strcmp(arr1,arr2)==0)
                flag3=1;
        if(flag3==0&&flag==0)
            printf("%s -- is not a palindrome.\n\n",arr);
        else if(flag==1&&flag3==0)
            printf("%s -- is a regular palindrome.\n\n",arr);
        else if(flag==0&&flag3==1)
            printf("%s -- is a mirrored string.\n\n",arr);
        else if(flag==1&&flag3==1)
            printf("%s -- is a mirrored palindrome.\n\n",arr);
    }
    return 0;
}
