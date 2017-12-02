#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main ()
{
    int i,test,t,len,flag,c;
    char arr[10000],z,out[100000];
    double a,b;
    scanf("%d",&test);
    scanf("%c",&z);
    for(t=1;t<=test;t++)
    {
        gets(arr);
        len=strlen(arr);
        flag=0;
        c=0;
        for(i=0;i<len;i++)
        {
            if(((arr[i]>='1'&&arr[i]<='9')||arr[i]=='.')&&flag==0)
            out[i]=arr[i];
            else if(flag==0)
            {
                flag=1;
                out[i]='\0';
                a=atof(out);
            }
            else if((arr[i]>='1'&&arr[i]<='9')||arr[i]=='.')
            {
              out[c++]= arr[i];
            }

        }
        out[c]='\0';
        b=atof(out);
       // cout<<a<<" "<<b<<endl;
       a=(a*.5)+(b*.05);
       printf("Case %d: ",t);
       cout<<a<<endl;
    }
    return 0;
}
