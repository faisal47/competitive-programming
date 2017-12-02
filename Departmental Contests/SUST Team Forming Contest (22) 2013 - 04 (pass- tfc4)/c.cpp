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
#define ull unsigned long long
#define mt 200
using namespace std;

char arr[mt][mt];
int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};
int dist[mt][mt];
queue<int>q;
int n,m;
bool check(int s,int e)
{
    return s>=0 && s<n && e>=0 && e<m;
}

void bfs()
{
    int s,e,s1,e1;
    while(!q.empty())
    {
        s=q.front();q.pop();
        e=q.front();q.pop();
        for(int i=0;i<4;i++)
        {
            s1=s+X[i];
            e1=e+Y[i];
            if(check(s1,e1) && dist[s1][e1]>dist[s][e]+1)
            {
                dist[s1][e1]=dist[s][e]+1;
                q.push(s1);
                q.push(e1);
            }
        }
    }
}

int main ()
{
    int i,j;
    int test;
    sci1(test);
    while(test--)
    {
        while(!q.empty())q.pop();
        sci2(n,m);
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            scch(arr[i][j]);
            if(arr[i][j]=='1')
            {
                dist[i][j]=0;
                q.push(i);
                q.push(j);
            }
            else dist[i][j]=inf;
        }
        bfs();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(j)cout<<" ";
                cout<<dist[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}

