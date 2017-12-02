#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool flag[110],flag1[110];
map<string,int>m;
map<int,string>m1;
vector<int>v[110];
int current_time;
struct res
{
    string a;
    int time;
};
res res1;
vector<res>out;
void dfs(int start)
{
    int i;
    if(flag[start]==0)
    {
       // cout<<"ghelo"<<endl;
        flag[start]=1;
        current_time++;
        for(i=0;i<v[start].size();i++)
        dfs(v[start][i]);
        res1.a=m1[start];
        res1.time=current_time;
        out.push_back(res1);
        current_time++;
    }
    return;
}
bool comp(res a,res b)
{
    return a.time>b.time;
}
int main ()
{
    string a,b;
    int n,i,z,test=1;
    while(cin>>n)
    {
        m.clear();
        m1.clear();
        out.clear();
        for(i=1;i<=n;i++)
        {
            flag[i]=0;
            flag1[i]=0;
            v[i].clear();
            cin>>a;
            m[a]=i;
            m1[i]=a;
        }
//        for(i=1;i<=n;i++)
//        cout<<m1[i]<<endl;
        cin>>z;
        while(z--)
        {
            cin>>a>>b;
            //cout<<m[a]<<" "<<m[b]<<endl;
            v[m[a]].push_back(m[b]);
            flag1[m[a]]=1;
            flag1[m[b]]=1;
        }
        printf("Case #%d: Dilbert should drink beverages in this order:",test++);
        for(i=1;i<=n;i++)
        if(flag1[i]==0)
        cout<<" "<<m1[i];
        current_time=1;
        for(i=1;i<=n;i++)
        if(flag[i]==0&&flag1[i]==1)
        {
            dfs(i);
            current_time--;
        }
        sort(out.begin(),out.end(),comp);
        for(i=0;i<out.size();i++)
        cout<<" "<<out[i].a;
        cout<<'.'<<endl<<endl;
    }
    return 0;
}
