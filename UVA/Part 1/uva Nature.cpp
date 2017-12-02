#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int count[5010],parent[5010],maxi;
int find_parent(int i)
{
    if(parent[i]==i)
    return i;
    else
    return parent[i]=find_parent(parent[i]);
}
void make_parent(int a,int b)
{
    int u=find_parent(a);
    int v=find_parent(b);
    if(u==v)
    return;
    else
    {
        parent[u]=v;
        count[v]+=count[u];
        if(maxi<count[v])
        maxi=count[v];
    }
    return;
}
int main ()
{
    map<string,int>m;
    string a,b;
    int i,f,r;
    while(cin>>f>>r)
    {
        if(f==0&&r==0)
        break;
        m.clear();
        maxi=1;
        for(i=1;i<=f;i++)
        {
            cin>>a;
            m[a]=i;
            parent[i]=i;
            count[i]=1;
        }
        while(r--)
        {
            cin>>a>>b;
            make_parent(m[a],m[b]);
        }
        cout<<maxi<<endl;
    }
    return 0;
}
