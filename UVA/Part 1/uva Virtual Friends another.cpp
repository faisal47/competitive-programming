#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <string.h>
using namespace std;
int count[200020],par[200020];
int parent(int a)
{
    if(par[a]==a)
    return a;
    else
    return par[a]=parent(par[a]);
}
void making_connection(int a,int b)
{
    int u=parent(a);
    int v=parent(b);
    if(u!=v)
    {
        par[u]=v;
        count[v]+=count[u];
        cout<<count[v]<<endl;
    }
    else
    cout<<count[u]<<endl;
    return;
}
int main ()
{
    int test,f,sign,i;
    map<string,int>m;
    string s1,s2;
    cin>>test;
    while(test--)
    {
        m.clear();
        for(i=1;i<=200005;i++)
        {
            par[i]=i;
            count[i]=1;
        }
        cin>>f;sign=1;
        while(f--)
        {
            cin>>s1>>s2;
            if(m.find(s1)==m.end())
            m[s1]=sign++;
            if(m.find(s2)==m.end())
            m[s2]=sign++;
            making_connection(m[s1],m[s2]);
        }
        sign++;
    }
    return 0;
}
