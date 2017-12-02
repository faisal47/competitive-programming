#include <bits/stdc++.h>

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <assert.h>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
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
#define sz(a) (int)a.size()
#define ll long long
#define LL long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
using namespace std;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//

#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define mt 205
#define mod

int dist[mt][mt][2],n,m;

string arr[mt];
vec_<pii>stars;
queue<pair<pair<int,int>,int>>q;

bool okay(int u,int v,int flag)
{
    return u>=0 && u<n && v>=0 && v<m && dist[u][v][flag]==-1 && arr[u][v]!='#';
}

int cnt;

int bfs()
{
    while(!q.empty())q.pop();
    clr(stars);
    ms(dist,-1);
    cnt=0;
    pii st,en;
    int i,j,flag;
    pii u,v;
    rep(i,n)
    rep(j,m)
    {
        if(arr[i][j] == 'P')
        st={i,j};
        if(arr[i][j] == 'D')
        en={i,j};
        if(arr[i][j] == '*')
        stars.pb({i,j});
    }
    dist[st.fs][st.sc][0]=0;
    q.push({st,0});
    while(!q.empty())
    {
        flag=q.front().sc;
        u=q.front().fs;
        if(u == en)
            return dist[u.fs][u.sc][flag];
        q.pop();
        if(flag || arr[u.fs][u.sc]!='*')
        {
            rep(i,4)
            {
                v.fs=u.fs+X[i];
                v.sc=u.sc+Y[i];
                if(okay(v.fs,v.sc,0))
                    {
                        dist[v.fs][v.sc][0]=1+dist[u.fs][u.sc][flag];
                        q.push({v,0});
                    }
            }
        }
        if(arr[u.fs][u.sc]=='*' && cnt<2)
        {
            cnt++;
            rep(i,sz(stars))
            {
                if(stars[i] == u)
                    continue;
                v=stars[i];
                if(okay(v.fs,v.sc,1))
                {
                    dist[v.fs][v.sc][1]=1+dist[u.fs][u.sc][flag];
                    q.push({v,1});
                }
            }
        }
    }
    return -1;
}

int main ()
{
    int i,j,test,t=1;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        rep(i,n)
        cin>>arr[i];
        int ans=bfs();
        if(ans == -1)
            printf("Case %d: impossible\n",t++);
        else
            printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

