#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <stack>
#include <utility>
#include <queue>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define eps 1E-7
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf("%c",&a)
#define scll1(a) scanf("%lld",&a)
#define scll2(a,b) scanf("%lld %lld",&a,&b)
#define scll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scd1(a) scanf("%lf",&a)
#define scd2(a,b) scanf("%lf %lf",&a,&b)
#define scd3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define sz 510
using namespace std;
struct ans1
{
    int x,y;
};
vec_<ans1>ans;
int X[]={-1,0,1,0};
int Y[]={0,1,0,-1},m,n,c,flag[sz][sz];
char arr[sz][sz];
void bfs2(int s,int e)
{
    clr(ans);
    flag[s][e]=2;
    ans.pb({s,e});
    queue<int>q;
    q.push(s);
    q.push(e);
    int s1,e1,i;
    while(!q.empty())
    {
        s=q.front();q.pop();
        e=q.front();q.pop();
        for(i=0;i<4;i++)
        {
            s1=X[i]+s;
            e1=Y[i]+e;
            if(flag[s1][e1]==1  && s1>=0 && e1>=0 && s1<m && e1<n)
            {
                flag[s1][e1]=2;
                q.push(s1);
                q.push(e1);
                ans.pb({s1,e1});
            }
        }
    }
   // cout<<ans.size()<<endl;
    if(ans.size()<3)
    {
        for(i=0;i<ans.size();i++)
        if(i>0)
        printf("R %d %d\n",ans[i].x+1,ans[i].y+1);
        else
        printf("B %d %d\n",ans[i].x+1,ans[i].y+1);
    }
    else
    {
        for(i=0;i<ans.size()-1;i++)
        {
            printf("B %d %d\n",ans[i].x+1,ans[i].y+1);
        }
        printf("R %d %d\n",ans[ans.size()-1].x+1,ans[ans.size()-1].y+1);
        for(i=ans.size()-2;i>0;i--)
        {
            printf("D %d %d\n",ans[i].x+1,ans[i].y+1);
            printf("R %d %d\n",ans[i].x+1,ans[i].y+1);
        }
    }
}
void bfs1(int s,int e)
{
    int i,s1,e1;
    queue<int>q;
    q.push(s);
    q.push(e);
    c++;
    flag[s][e]=1;
    while(!q.empty())
    {
        s=q.front();q.pop();
        e=q.front();q.pop();
        for(i=0;i<4;i++)
        {
            s1=s+X[i];
            e1=e+Y[i];
            if(!flag[s1][e1] && arr[s1][e1]=='.' && s1>=0 && e1>=0 && s1<m && e1<n)
            {
                //cout<<s1<<" "<<e1<<endl;
                flag[s1][e1]=1;
                c++;
                q.push(s1);
                q.push(e1);
            }
        }
    }
}
int main ()
{
    int i,j,mot=0;
    char z;
    sci2(m,n);
    scch(z);
    for(i=0;i<m;i++)
    gets(arr[i]);
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    if(!flag[i][j] && arr[i][j]=='.')
    {
        c=0;
        bfs1(i,j);
        if(c>2)
        {
            mot+=(c-2) * 2;
        }
        mot+=c;
    }
    cout<<mot<<endl;
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    if(flag[i][j]==1 && arr[i][j]=='.')
    {
        bfs2(i,j);
    }
    return 0;
}