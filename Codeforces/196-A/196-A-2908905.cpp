#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <ctype.h>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#define inf 123456789
using namespace std;
int main ()
{
    map<char,int>m;
    vector<char>v;
    char arr[100030];
    int len,i,pos,j,npos;
    while(gets(arr))
    {
        m.clear();
        v.clear();
        pos=npos=0;
        len=strlen(arr);
        for(i=0;i<len;i++)
        {
            if(m.find(arr[i])==m.end())
             {
                 m[arr[i]]=1;
                 v.push_back(arr[i]);
             }
        }
        sort(v.rbegin(),v.rend());
        for(i=0;i<v.size();i++)
        {
                pos=npos;
            for(j=pos;j<len;j++)
            {
                if(arr[j]==v[i])
                {
                  npos=j+1;
                  cout<<arr[j];
                }
            }
            if(npos>len)
            break;
        }
        cout<<endl;
    }
    return 0;
}