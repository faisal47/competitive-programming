#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char arr[1000000],out[1000000];
    int i,len,a,c,d,out1[1000000];
int main ()
{
    while(gets(arr))
    {
        len=strlen(arr);d=0;
        if(arr[0]>='0'&&arr[0]<='9')
        {
            for(i=len-1;i>=0;i--)
            {
                if(arr[i]=='1')
                {
                  c=arr[i--]-'0';
                  c=(c*10)+((arr[i--]-'0'));
                  c=(c*10)+((arr[i]-'0'));
                  out[d++]=(char)c;
                }
                else
                {
                  c=arr[i--]-'0';
                  c=(c*10)+((arr[i]-'0'));
                 // cout<<"c="<<c<<endl;
                  out[d++]=(char)c;
                }
            }
            for(i=0;i<d;i++)
            cout<<out[i];
            cout<<endl;
        }
        else
        {
            for(i=len-1;i>=0;i--)
            {
                c=(int)arr[i];
                if(c>=100)
                {
                    out1[d++]=c%10;c/=10;
                    out1[d++]=c%10;c/=10;
                    out1[d++]=c%10;
                }
                else
                {
                    out1[d++]=c%10;c/=10;
                    out1[d++]=c%10;
                }
            }
            for(i=0;i<d;i++)
            cout<<out1[i];
            cout<<endl;

        }
    }
    return 0;
}
