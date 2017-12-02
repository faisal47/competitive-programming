#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
#include <string>
using namespace std;
int main ()
{
    char arr[600],*a,dis[100000];
    map<string,int>m;
    map<string,int>::iterator it;
    string b;
    b.clear();
    int i,len,flag,len1,c;
    flag=0;
    while(gets(arr))
    {
        len=strlen(arr);
        if(len==0)
            continue;
        a=strtok(arr," :';!@#$%^&*()_=+0987654321][{}|/,.></?");
        if(flag==1)
        {
            len1=strlen(a);
            for(i=0;i<len1;i++)
                a[i]=tolower(a[i]);
                b+=a;
            if(a[len1-1]=='-')
            {
                continue;
            }
            else
            {
               flag=c=0;
               for(i=0;i<b.size();i++)
               if(b[i]!='"'&&b[i]!='-')
               dis[c++]=b[i];
               dis[c]='\0';
               if(m.find(dis)==m.end())
               m[dis]=1;
               b.clear();
               a=strtok(NULL," :;'!@#$%^&*()_=+0987654321][{}|/,.></?");
            }
        }
        while(a!=NULL)
        {
            len1=strlen(a);
            if(a[len1-1]=='-')
            {
                flag=1;
                for(i=0;i<len1;i++)
                a[i]=tolower(a[i]);
                b+=a;
                break;
            }
            else
            {
                for(i=0;i<len1;i++)
                a[i]=tolower(a[i]);
                c=0;
                for(i=0;i<len1;i++)
               if(a[i]!='"')
               dis[c++]=a[i];
               dis[c]='\0';
               if(m.find(dis)==m.end())
               m[dis]=1;
            }
            a=strtok(NULL," :;'!@#$%^&*()_=+0987654321][{}|/,.></?");
        }
    }
    for(it=m.begin();it!=m.end();it++)
    cout<<it->first<<endl;
    return 0;
}
