#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <ctype.h>
using namespace std;
int main ()
{
    char arr[100000];
    int len,i,flag,endflag=0;
    string a,b;
    while(gets(arr))
    {
        if(endflag==1)
        break;
        flag=0;
        len=strlen(arr);
        for(i=0; i<len; i++)
        {
            if((arr[i]>='a'&&arr[i]<='z')||(arr[i]>='A'&&arr[i]<='Z')||arr[i]=='-')
                flag=1;
            else
                flag=0;
            if(flag==0)
            {
                if(a.size()>0)
                {
                    if(a=="E-N-D")
                    {
                        endflag=1;
                        break;
                    }
                    if(b.size()<a.size())
                        b=a;
                    a.clear();
                }
            }
            if(flag==1)
                a+=arr[i];
        }
        if(endflag==1)
        break;
        if(a.size()>0)
        {
            if(a=="E-N-D")
            {
                endflag=1;
                break;
            }
            if(b.size()<a.size())
                b=a;
            a.clear();
        }
        if(endflag==1)
        break;
    }
    for(i=0;i<b.size();i++)
    printf("%c",tolower(b[i]));
    cout<<endl;
    return 0;
}
