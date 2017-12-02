#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#define ms(a,b) memset(a,b,sizeof(a))
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci1(a) scanf("%d",&a)
#define sz(a) a.size()
#define mt 2010
using namespace std;
vec_<int>v[mt];
int col[mt];
bool flase_flag;
void bfs(int s)
{
    queue<int>q;
    int flag1=1,i,v1;
    q.push(s);
    col[s]=flag1;
    while(!q.empty())
    {
        s=q.front();q.pop();
       flag1=col[s];
       if(flag1==1)flag1=2;
       else flag1=1;
        for(i=0;i<sz(v[s]);i++)
        {
            v1=v[s][i];
            if(!col[v1])
            {
                col[v1]=flag1;
                q.push(v1);
            }
            else if(col[v1]!=flag1 && col[v1])
            {
                flase_flag=1;
                return;
            }
        }
    }
}
int main ()
{
    int t=1,test,n,m,i,j;
    sci1(test);
    while(test--)
    {
        sci2(n,m);
        flase_flag=0;
        for(i=1;i<=n;i++)
        {
            clr(v[i]);
            col[i]=0;
        }
        while(m--)
        {
            sci2(i,j);
            v[i].pb(j);
            v[j].pb(i);
        }
        for(i=1;i<=n;i++)
        {
            if(!col[i])
            {
                bfs(i);
                if(flase_flag)break;
            }
        }
        printf("Scenario #%d:\n",t++);
        if(flase_flag)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
    }
    return 0;
}

