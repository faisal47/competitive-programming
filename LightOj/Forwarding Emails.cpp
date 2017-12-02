#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stack>
#define ms(a,b) memset(a,b,sizeof(a))
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sz 50010
using namespace std;
int indx[sz],scc_mot,n,low[sz],cnt,ans,ans_mot;
vec_<int>v[sz];
bool col[sz];
stack<int>s;
struct components1
{
    int a,b;
};
components1 components[sz];
void find_scc(int a)
{
    s.push(a);
    col[a]=low[a]=indx[a]=++cnt;
    int i,j;
    for(i=0;i<v[a].size();i++)
    {
        j=v[a][i];
        if(!indx[j])
        {
            find_scc(j);
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
        scc_mot++;
        components[scc_mot].b=a;
        while(j!=a)
        {
            j=s.top();
            s.pop();
            components[scc_mot].b=min(components[scc_mot].b,j);
            components[scc_mot].a++;
            col[j]=0;
        }
    }
}
int main ()
{
    int i,j,t=1,test,k;
    sci1(test);
    while(test--)
    {
        sci1(n);
        scc_mot=cnt=ans_mot=0;
        for(i=1;i<=n;i++)
        {
            components[i].a=components[i].b=low[i]=indx[i]=col[i]=0;
            clr(v[i]);
        }
        for(i=1;i<=n;i++)
        {
            sci2(j,k);
            v[j].pb(k);
        }
        for(i=1;i<=n;i++)
        if(!indx[i])
        find_scc(i);
        for(i=1;i<=scc_mot;i++)
        if(components[i].a>ans_mot)
        {
            ans_mot=components[i].a;
            ans=components[i].b;
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

