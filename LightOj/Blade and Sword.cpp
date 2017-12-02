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

#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)

#define pri1(a) printf("%d ",a)
#define pri2(a,b) printf("%d %d ",a,b)
#define prll1(a) printf("%I64d ",a)
#define prll2(a,b) printf("%I64d %I64d ",a,b)
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define mt 210
using namespace std;
char arr[mt][mt];
int X[]= {-1,0,1,0};
int Y[]= {0,1,0,-1};
int n,m,dist[mt][mt],col[mt][mt];
vec_<int>stars;

bool check(int s1,int s2)
{
    return s1>=1 && s1<=n && s2>=1 && s2<=m && arr[s1][s2]!='#';
}

int d;

void bfs(int s1,int s2)
{
    queue<int>q;
    q.push(s1);
    q.push(s2);
    dist[s1][s2]=0;
    int i,e1,e2,j;
    while(!q.empty())
    {
        s1=q.front();
        q.pop();
        s2=q.front();
        q.pop();

        if(arr[s1][s2]=='*' && col[s1][s2]==2)
        {
            for(j=0; j<sz(stars); j+=2)
            {
                e1=stars[j];
                e2=stars[j+1];
                d=dist[s1][s2]+1;
                if(d<dist[e1][e2])
                {
                    dist[e1][e2]=d;
                    col[e1][e2]=1;
                    q.push(e1);
                    q.push(e2);
                }
            }
            for(i=0; i<4; i++)
            {
                e1=s1+X[i];
                e2=s2+Y[i];
                if(check(e1,e2) && arr[e1][e2]!='*')
                {
                    d=dist[s1][s2]+1;
                    if(d<dist[e1][e2])
                    {
                        dist[e1][e2]=d;
                        q.push(e1);
                        q.push(e2);
                    }
                }
            }
        }
        else if(arr[s1][s2]=='*' && col[s1][s2]==1)
        {
            for(j=0; j<sz(stars); j+=2)
            {
                e1=stars[j];
                e2=stars[j+1];
                d=dist[s1][s2]+1;
                if(d<dist[e1][e2])
                {
                    dist[e1][e2]=d;
                    col[e1][e2]=2;
                    q.push(e1);
                    q.push(e2);
                }
            }
        }
        else
        {
            for(i=0; i<4; i++)
            {
                e1=s1+X[i];
                e2=s2+Y[i];
                if(check(e1,e2))
                {
                    e1=s1+X[i];
                    e2=s2+Y[i];
                    if(check(e1,e2))
                    {
                        if(arr[e1][e2]=='*')
                            col[e1][e2]=1;
                        d=dist[s1][s2]+1;
                        if(d<dist[e1][e2])
                        {
                            dist[e1][e2]=d;
                            q.push(e1);
                            q.push(e2);
                        }
                    }
                }
            }
        }
    }
}

int main ()
{
    int i,j,test,t=1,s1,s2,e1,e2;
    sci1(test);
    while(test--)
    {
        sci2(n,m);
        clr(stars);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                dist[i][j]=inf;
                scch(arr[i][j]);
              //  cout<<arr[i][j];
                if(arr[i][j]=='*')
                {
                    col[i][j]=2;
                    stars.pb(i);
                    stars.pb(j);
                }
                else if(arr[i][j]=='P')
                {
                    s1=i;
                    s2=j;
                }
                else if(arr[i][j]=='D')
                {
                    e1=i;
                    e2=j;
                }
            }
          //  cout<<endl;
        }
        bfs(s1,s2);
        printf("Case %d: ",t++);
        if(dist[e1][e2]==inf)
            cout<<"impossible\n";
        else
            printf("%d\n",dist[e1][e2]);
    }
    return 0;
}

