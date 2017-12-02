#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    char arr[10000];
    int len,i,max,out[400];
    while(gets(arr))
    {
        max=0;
        memset(out,0,sizeof(out));
        len=strlen(arr);
        for(i=0;i<len;i++)
        {
            if((arr[i]>='a'&&arr[i]<='z')||(arr[i]>='A'&&arr[i]<='Z'))
            ++out[arr[i]];
            if(out[arr[i]]>max)
            max=out[arr[i]];
        }
        for(i=0;i<400;i++)
        if(out[i]==max)
        printf("%c",i);
        cout<<" ";
        cout<<max<<endl;
    }
    return 0;
}
