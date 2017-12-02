#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <ctype.h>
using namespace std;
int main ()
{
    char arr[10000];
    int len,i,flag,j;
    string a;
    while(gets(arr))
    {
        if(strcmp(arr,"DONE")==0)
        break;
        a.clear();
        flag=0;
        len=strlen(arr);
        for(i=0;i<len;i++)
        if((arr[i]>='a'&&arr[i]<='z')||(arr[i]>='A'&&arr[i]<='Z'))
        a+=tolower(arr[i]);
        i=0;j=a.size()-1;
        while(1)
        {
            if(i==j||i>j)
            break;
            if(a[i]!=a[j])
            {
                flag=1;
                break;
            }
            i++;j--;
        }
        if(flag==1)
        cout<<"Uh oh.."<<endl;
        else
        cout<<"You won't be eaten!"<<endl;
    }
    return 0;
}
