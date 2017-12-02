#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    int test,t,len,count,flag,flag2,i,c;
    char z,arr[30],word1[30],word2[30];
    scanf("%d%c",&test,&z);
    gets(arr);
    for(t=0;t<test-1;t++)
    {
        flag=0;
        while(gets(arr))
        {
            len=strlen(arr);
            if(len==0)
            break;
            if(arr[0]=='*'&&len==1)
            {
                flag=1;
                continue;
            }
            if(flag==1)
            {
                flag2=c=count=0;
                for(i=0;i<len;i++)
                {
                    if(arr[i]==' ')
                    {
                        c=0;flag2=1;
                    }
                    else if(flag2==0)
                    word1[c++]=arr[i];
                    else if(flag2==1)
                    word2[c++]=arr[i];
                }
                for(i=0;i<c;i++)
                {
                    if(word1[i]==word2[i])
                    count++;
                }
                cout<<arr<<" "<<count<<endl;
            }
        }
        cout<<endl;
    }
    flag=0;
    while(gets(arr))
        {
            len=strlen(arr);
            if(len==0)
            break;
            if(arr[0]=='*'&&len==1)
            {
                flag=1;
                continue;
            }
            if(flag==1)
            {
                flag2=c=count=0;
                for(i=0;i<len;i++)
                {
                    if(arr[i]==' ')
                    {
                        c=0;flag2=1;
                    }
                    else if(flag2==0)
                    word1[c++]=arr[i];
                    else if(flag2==1)
                    word2[c++]=arr[i];
                }
                for(i=0;i<c;i++)
                {
                    if(word1[i]!=word2[i])
                    count++;
                }
                cout<<arr<<" "<<count<<endl;
            }
        }
    return 0;
}
