#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int>v[200020];
int count;
bool flag[200020];
void bfs(int start)
{
    int i;
    flag[start]=1;
    count++;
    queue<int>q;
    q.push(start);
    while(!q.empty())
    {
        start=q.front();
        q.pop();
        for(i=0;i<v[start].size();i++)
        {
            if(flag[v[start][i]]==0)
            {
               flag[v[start][i]]=1;
               q.push(v[start][i]);
               count++;
            }
        }
    }
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
        cin>>f;sign=1;
        while(f--)
        {
            count=0;
            cin>>s1>>s2;
            if(m.find(s1)==m.end())
            m[s1]=sign++;
            if(m.find(s2)==m.end())
            m[s2]=sign++;
            for(i=1;i<=sign;i++)
            flag[i]=0;
            v[m[s1]].push_back(m[s2]);
            v[m[s2]].push_back(m[s1]);
            bfs(m[s1]);
            cout<<count<<endl;
        }
        sign++;
        for(i=1;i<=sign;i++)
        v[i].clear();
    }
    return 0;
}
