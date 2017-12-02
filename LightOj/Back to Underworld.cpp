#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sz 20010
using namespace std;
int flag[sz],i,j,s;
vec_<int>v[sz];
int bfs(int s)
{
    queue<int>q;
    q.push(s);
  int c1=0,c2=0;
        flag[s]=1;
        c1++;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(i=0; i<v[s].size(); i++)
        {
            j=v[s][i];
            if(!flag[j])
            {
                if(flag[s]==1)
                {
                    flag[j]=2;
                    c2++;
                }
                else
                {
                    flag[j]=1;
                    c1++;
                }
                q.push(j);
            }
        }
    }
    return max(c1,c2);
}
int main ()
{
    int i,test,t=1,a,b,n,max_n,ans;
    sci1(test);
    while(test--)
    {
        max_n=0;
        ans=0;
        sci1(n);
        for(i=1; i<=n; i++)
        {
            sci2(a,b);
            max_n=max(a,max_n);
            max_n=max(b,max_n);
            v[a].pb(b);
            v[b].pb(a);
        }
        for(i=1; i<=max_n; i++)
            if(!flag[i] && v[i].size())
                ans+=bfs(i);
        printf("Case %d: %d\n",t++,ans);
        for(i=1; i<=max_n; i++)
        {
            flag[i]=0;
            clr(v[i]);
        }
    }
    return 0;
}

