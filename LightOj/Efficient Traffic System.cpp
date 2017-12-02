#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sz 20010
using namespace std;
int n,low[sz],indx[sz],scc_count,under[sz],cnt;
vec_<int>v[sz];
stack<int>s;
bool col[sz],in[sz],out[sz];
void scc(int a)
{
    s.push(a);
    col[a]=1;
    indx[a]=low[a]=++cnt;
    int i,j;
    for(i=0; i<v[a].size(); i++)
    {
        j=v[a][i];
        if(!indx[j])
        {
            scc(j);
            low[a]=min(low[a],low[j]);
        }
        else if(col[j])
        {
            low[a]=min(low[a],low[j]);
        }
    }
    if(indx[a]==low[a])
    {
        j=-1;
        scc_count++;
        while(j!=a)
        {
            j=s.top();
            s.pop();
            under[j]=scc_count;
            col[j]=0;
        }
    }
}
void dfs(int a)
{
    col[a]=1;
    int i,j;
    for(i=0; i<v[a].size(); i++)
    {
        j=v[a][i];
        if(under[a]!=under[j])
        {
            out[under[a]]++;
            in[under[j]]++;
        }
        if(!col[j])
            dfs(j);
    }
}
int main ()
{
    int i,j,test,t=1,m,ans,in_mot,out_mot;
    sci1(test);
    while(test--)
    {
        in_mot=out_mot=scc_count=cnt=0;
        sci2(n,m);
        for(i=1; i<=n; i++)
        {
            clr(v[i]);
            in[i]=out[i]=col[i]=low[i]=0;
            indx[i]=0;
        }
        while(m--)
        {
            sci2(i,j);
            v[i].pb(j);
        }
        for(i=1; i<=n; i++)
            if(!indx[i])
                scc(i);
        for(i=1; i<=n; i++)
            col[i]=0;
        for(i=1; i<=n; i++)
            if(!col[i])
                dfs(i);
        if(scc_count==1)
            ans=0;
        else
        {
            for(i=1; i<=scc_count; i++)
            {
                if(!in[i])
                    in_mot++;
                if(!out[i])
                    out_mot++;
            }
            ans=max(in_mot,out_mot);
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

