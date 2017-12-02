#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
#include <string>
using namespace std;
int main ()
{
    map<string,string>m;
    char arr[100],*pt;
    int len;
    string a,b;
    while(gets(arr))
    {
        if(strlen(arr)==0)
        break;
       pt=strtok(arr," ");
       a=pt;
       pt=strtok(NULL," ");
       b=pt;
       m[b]=a;
    }
    while(cin>>a)
    {
        if(m.find(a)==m.end())
        cout<<"eh"<<endl;
        else
        cout<<m[a]<<endl;
    }
    return 0;
}
