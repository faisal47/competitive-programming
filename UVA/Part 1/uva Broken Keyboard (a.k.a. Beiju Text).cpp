#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char arr[3010],arr1[3010];
int main ()
{
    int len,flag1,i,c1;
    while(gets(arr))
    {
        flag1=c1=0;
        len=strlen(arr);
        for(i=0;i<len;i++)
        {
            if(arr[i]=='[')
            {
                flag1=1;
            }
            if(flag1==1)
            {
                if(arr[i]!='['&&arr[i]!=']')
                {
                    arr1[c1++]=arr[i];
                    arr[i]='[';
                }
                else if(arr[i]==']')
                {
                    flag1=0;
                }
            }
        }
        arr1[c1]='\0';
        cout<<arr1;
        for(i=0;i<len;i++)
        {
            if(arr[i]!='['&&arr[i]!=']')
            {
                cout<<arr[i];
            }
        }
        cout<<endl;
    }
    return 0;
}
