#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
vector<int>v[1000];
map<string,int>m1;
map<int,string>m2;
int parents[700];
bool color[700];
void bfs(int start)
{
    queue<int>q;
    q.push(start);
    int i;
    color[start]=1;
    while(!q.empty())
    {
        start=q.front();
        q.pop();
        for(i=0; i<v[start].size(); i++)
        {
            if(color[v[start][i]]==0)
            {
                color[v[start][i]]=1;
                q.push(v[start][i]);
                parents[v[start][i]]=start;
            }
        }
    }
    return;
}
int main ()
{
    string s1,s2;
    int test,c,a,b,i,flag=0;
    while(cin>>test)
    {
        if(flag)
            cout<<endl;
        flag=1;
        m1.clear();
        m2.clear();
        c=1;
        for(i=1; i<700; i++)
        {
            v[i].clear();
            parents[i]=i;
            color[i]=0;
        }
        while(test--)
        {
            cin>>s1>>s2;
            if(m1.find(s1)==m1.end())
            {
                m1[s1]=c++;
                m2[m1[s1]]=s1;
            }
            if(m1.find(s2)==m1.end())
            {
                m1[s2]=c++;
                m2[m1[s2]]=s2;
            }
            a=m1[s1];
            b=m1[s2];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        cin>>s1>>s2;
        if(m1.find(s1)==m1.end())
        {
            m1[s1]=c++;
            m2[m1[s1]]=s1;
        }
        if(m1.find(s2)==m1.end())
        {
            m1[s2]=c++;
            m2[m1[s2]]=s2;
        }
        bfs(m1[s2]);
        if(color[m1[s1]]==0||s1==s2)
            cout<<"No route"<<endl;
        else
        {
            a=m1[s1];
            b=parents[a];
            while(1)
            {
                if(a==b)
                    break;
                cout<<m2[a]<<" "<<m2[b]<<endl;
                a=b;
                b=parents[a];
            }
        }
    }
    return 0;
}
