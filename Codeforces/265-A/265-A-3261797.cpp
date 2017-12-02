#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    int len1,len2,i,now;
    char arr1[100],arr2[100];
    while(gets(arr1))
    {
        now=0;
        gets(arr2);
        len1=strlen(arr1);
        len2=strlen(arr2);
        for(i=0;i<len2;i++)
        if(arr2[i]==arr1[now])
        now++;
        cout<<now+1<<endl;
    }
    return 0;
}