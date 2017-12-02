#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#define inf 1<<28
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sz 1010
using namespace std;
stack<int>s;
map<int,int>m;
int low[sz],exact[sz],scc_count,t,under_scc[sz],in_d[sz],out_d[sz],col[sz];
vec_<int>v[sz],v_main;
void init()
{
    int i;
    clr(m);
    clr(v_main);
    t=1;
    for(i=0; i<1005; i++)
    {
        col[i]=in_d[i]=out_d[i]=0;
        clr(v[i]);
    }
    scc_count=0;
    while(!s.empty())
    s.pop();
}
void make_scc(int a)
{
    s.push(a);
    col[a]=1;
    low[a]=exact[a]=t++;
    int i,j;
    for(i=0;i<v[a].size();i++)
    {
        j=v[a][i];
        if(!col[j])
        {
            make_scc(j);
            low[a]=min(low[a],low[j]);
        }
        else if(col[j]==1)
        {
            low[a]=min(low[a],low[j]);
        }
    }
    if(exact[a]==low[a])
    {
        j=-1;
        scc_count++;
        while(j!=a)
        {
            j=s.top();s.pop();
            col[j]=2;
            under_scc[j]=scc_count;
        }
    }
}
void make_dag()
{
    int i,j,k,l;
    for(i=0;i<v_main.size();i++)
    {
        j=under_scc[v_main[i]];
        for(k=0;k<v[v_main[i]].size();k++)
        {
            l=under_scc[v[v_main[i]][k]];
            if(j!=l)
            {
                in_d[l]++;
                out_d[j]++;
            }
        }
    }
}
int main ()
{
    int i,test,te=1,n,a,b,k,c1,c2,c3;
    sci1(test);
    while(test--)
    {
        c1=c2=c3=0;
        sci1(n);
        init();
        while(n--)
        {
            sci1(k);
            while(k--)
            {
                sci2(a,b);
                v[a].pb(b);
                if(m.find(a)==m.end())
                {
                    m[a]=1;
                    v_main.pb(a);
                }
                if(m.find(b)==m.end())
                {
                    m[b]=1;
                    v_main.pb(b);
                }
            }
        }
        for(i=0;i<v_main.size();i++)
        if(!col[v_main[i]])
        make_scc(v_main[i]);
        make_dag();
        for(i=1;i<=scc_count;i++)
        {
            if(in_d[i]==1 && out_d[i]==1)
            c2++;
            else if(in_d[i]==1 && out_d[i]==0)
            c1++;
            else if(in_d[i]==0 && out_d[i]==1)
            c3++;
        }
  if((m[0]==1 && c2==scc_count-2 && c1==1 && c3==1 && out_d[under_scc[0]]==1 && !in_d[under_scc[0]])|| (scc_count==1 && m[0]==1))
        printf("Case %d: YES\n",te++);
        else
        printf("Case %d: NO\n",te++);
    }
    return 0;
}

