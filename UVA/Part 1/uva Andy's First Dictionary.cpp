#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <ctype.h>
using namespace std;
int main ()
{
    int i,len;
    map<string,int>m;
    map<string,int>::iterator it;
    char arr[302],*ptr;
    while(gets(arr))
    {
        len=strlen(arr);
        for(i=0;i<len;i++)
        {
            if((arr[i]>='a'&&arr[i]<='z')||(arr[i]>='A'&&arr[i]<='Z'))
                arr[i]=tolower(arr[i]);
                else
            arr[i]=' ';
        }
        ptr=strtok(arr," !@#$%^&*()_+=-':;/.,<>?][{}1234567890");
        while(ptr!=NULL)
        {
            if(m.find(ptr)==m.end())
            m[ptr]=1;
            ptr=strtok(NULL," !@#$%^&*()_+=-':;/.,<>?][{}1234567890");
        }
    }
    for(it=m.begin();it!=m.end();it++)
    cout<<it->first<<endl;
    return 0;
}
