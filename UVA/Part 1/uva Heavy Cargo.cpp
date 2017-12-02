#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
vector<int>v[200];
bool color[205];
int w[205][205],uniparent[200],parent[205];
struct nod
{
    int start,end,weight;
};
nod node[19920];
void bfs(int a,int b)
{
    queue<int>q;
    parent[a]=a;
    color[a]=1;
    int i,c,flag=0;
    q.push(a);
    while(!q.empty())
    {
        c=q.front();
        q.pop();
        for(i=0;i<v[c].size();i++)
        {
            if(color[v[c][i]]==0)
            {
                color[v[c][i]]=1;
                q.push(v[c][i]);
            parent[v[c][i]]=c;
            if(v[c][i]==b)
            {
                flag=1;
                break;
            }
            }
        }
        if(flag==1)
        break;
    }
    return;
}
int findparent(int r)
{
    if(uniparent[r]==r)
        return r;
    else
        uniparent[r]=findparent(uniparent[r]);
}
void makeset(int a,int b,int i)
{
    int u1=findparent(a);
    int v1=findparent(b);
    if(u1==v1)
        return;
        v[a].push_back(b);
        v[b].push_back(a);
    w[a][b]=w[b][a]=node[i].weight;
    uniparent[u1]=v1;
    return;
}
int main ()
{
    int i,a,b,weight,c,start,end,j,test=1,min;
    bool flag,flag1;
    map<string,int>m;
    string rasta1,rasta2;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)
            break;
        m.clear();
        c=1;
        memset(color,0,sizeof(color));
        flag=flag1=0;
        min=10050;
        for(i=1; i<=a; i++)
            {
                uniparent[i]=i;
                v[i].clear();
            }
        for(i=0; i<b; i++)
        {
            cin>>rasta1>>rasta2>>weight;
            if(m.find(rasta1)==m.end())
            {
                m[rasta1]=c++;
            }
            if(m.find(rasta2)==m.end())
            {
                m[rasta2]=c++;
            }
            node[i].weight=weight;
            node[i].start=m.find(rasta1)->second;
            node[i].end=m.find(rasta2)->second;
        }
        for(i=0; i<b-1; i++)
            for(j=i+1; j<b; j++)
                if(node[i].weight<node[j].weight)
                {
                    swap(node[i].weight,node[j].weight);
                    swap(node[i].start,node[j].start);
                    swap(node[i].end,node[j].end);
                }
        for(i=0; i<b; i++)
        {
            start=node[i].start;
            end=node[i].end;
                makeset(start,end,i);
        }
        cin>>rasta1>>rasta2;
        start=m.find(rasta1)->second;
        end=m.find(rasta2)->second;
        bfs(start,end);
        b=end;
        while(1)
        {
            a=parent[b];
            if(a==b)
            break;
            if(min>w[a][b])
            min=w[a][b];
            b=a;
        }
        printf("Scenario #%d\n%d tons\n\n",test++,min);
    }
    return 0;
}
