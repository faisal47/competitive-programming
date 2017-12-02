#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    int test,t,len,c,flag,i;
    char arr[100],z;
    scanf("%d",&test);
    scanf("%c",&z);
    for(t=1;t<=test;t++)
    {
        gets(arr);
        flag=0;
        len=strlen(arr);
        c=len-1;
        for(i=0;i<len/2;i++)
        {
            if(arr[i]!=arr[c--])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        printf("Case %d: No\n",t);
        else
        printf("Case %d: Yes\n",t);
    }
    return 0;
}
