#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
vector<char>v;
map<string,int>m;
string a,b;
int n,taken[40]={0},sign;
void bt()
{
    if(v.size()==n)
    {
        b.clear();
        for(int i=0;i<n;i++)
        b+=v[i];
        if(m.find(b)==m.end())
        {
            m[b]=sign++;
            cout<<b<<endl;
        }
        return;
    }
    for(int i=0;i<a.size();i++)
    {
        if(taken[i]==0)
        {
            if(v.size()>0)
            {
                if(v[v.size()-1]>a[i])
                continue;
            }
            taken[i]=1;
            v.push_back(a[i]);
             bt();
             taken[i]=0;v.pop_back();
        }
    }
    return;
}
int main ()
{
    while(cin>>a>>n)
    {
        sort(a.begin(),a.end());
        sign=0;
        m.clear();
        bt();
    }
    return 0;
}
