#include <iostream>
#include <stdio.h>
#include <string.h>
using  namespace std;
int main ()
{
    int c1,c2,c3,flag3,flag4,flag1,flag2,n,j,len,i,k,l;
    char arr[150],z;
    scanf("%d%c",&n,&z);
    for(j=0; j<n; j++)
    {
        flag1=flag2=c1=c2=c3=flag3=flag4=0;
        gets(arr);
        len=strlen(arr);
        while(1)
        {
            for(i=0; i<len; i++)
            {
                if((arr[i]=='('&&arr[i+1]==')')||(arr[i]=='['&&arr[i+1]==']'))
                {
                    arr[i]=arr[i+1]='0';flag1=1;
                i+=1;
                }
            }
            if(flag1==0&&flag2==1)
            {
                flag3=1;
                break;
            }
            flag1=flag2=c1=0;
            for(i=0;i<len;i++)
            {
                if(arr[i]!='0')
                {
                    arr[c1++]=arr[i];
                    flag2=1;
                }
            }
            if(c1==0)
            {
                flag4=1;
                break;
            }
            len=c1;
        }
        if(flag3==1)
        cout<<"No"<<endl;
        else
        cout<<"Yes"<<endl;
    }
    return 0;
}
