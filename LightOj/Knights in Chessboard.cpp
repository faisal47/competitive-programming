#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define pri1(a) printf("%d ",a)
#define pri2(a,b) printf("%d %d ",a,b)
#define prll1(a) printf("%I64d ",a)
#define prll2(a,b) printf("%I64d %I64d ",a,b)
#define sz(a) a.size()
#define ll long long
#define mt 205
using namespace std;
int col[mt][mt];
int X[]={1,-1,1,-1,2,2,-2,-2}; //for knight move
int Y[]={2,2,-2,-2,1,-1,1,-1};
int m,n,mot1,mot2;

void bfs(int x,int y)
{
    int s1,e1;
    queue<int>q;
    q.push(x);
    q.push(y);
    col[x][y]=1;
    mot1=0;
    mot2=1;
    while(!q.empty())
    {
        x=q.front();q.pop();
        y=q.front();q.pop();
        for(int i=0;i<8;i++)
        {
            s1=x+X[i];
            e1=y+Y[i];
            if(!col[s1][e1] && s1<n && e1<m && s1>-1 && e1>-1)
            {
                if(col[x][y]==1)
                {
                    col[s1][e1]=2;
                    mot1++;
                }
                else
                {
                    col[s1][e1]=1;
                    mot2++;
                }
                q.push(s1);
                q.push(e1);
            }
        }
    }
}

int main ()
{
    int test,t=1,i,j,ans;
    sci1(test);
    while(test--)
    {
        ans=0;
        sci2(n,m);
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        col[i][j]=0;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        if(!col[i][j])
        {
            bfs(i,j);
            ans+=max(mot1,mot2);
        }
        printf("Case %d: %d\n",t++,ans);
//        cout<<ans<<endl;
    }
    return 0;
}

