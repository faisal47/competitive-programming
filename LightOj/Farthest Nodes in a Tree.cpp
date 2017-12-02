#include <stdio.h>
#include <iostream>
#include <vector>
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sci1(a) scanf("%d",&a)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sz 30010
using namespace std;
int n,ans;
struct n_d1
{
    int node,cost;
};
bool col[sz];
vec_<n_d1>n_d[sz];
int dfs(int node)
{
    col[node]=1;
    int a=0,b=0,b1=0,i,j,j_cost;
    for(i=0;i<n_d[node].size();i++)
    {
        j=n_d[node][i].node;
        j_cost=n_d[node][i].cost;
        if(!col[j])
        {
            b1=j_cost+dfs(j);
            if(b1>a)
            {
                b=a;
                a=b1;
            }
            else if(b1>b)
            {
                b=b1;
            }
        }
    }
    ans=max(ans,a+b);
    return a;
}
int main ()
{
    int i,test,t=1,a,b,c;
    sci1(test);
    while(test--)
    {
        ans=0;
        sci1(n);
        for(i=0;i<n;i++)
        {
            clr(n_d[i]);
            col[i]=0;
        }
        for(i=0;i<n-1;i++)
        {
            sci3(a,b,c);
            n_d[a].pb({b,c});
            n_d[b].pb({a,c});
        }
        dfs(0);
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

