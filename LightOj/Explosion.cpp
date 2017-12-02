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
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;

#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}


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
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//



#define mt 2010
#define mod

int pows[9];

void pre1()
{
    int num=1;
    rep(i,7)
    {
        pows[i]=num;
        num*=3;
    }
}
int n,k;

struct tj
{
    int tp,a,b,c;
};
vec_<tj>tjs;
vec_<int>adj[mt];
void ins(int mask)
{
    int nb,nn,nt;
    rep(i,k)
    {
        nb=(mask/pows[i])%3;
        if(nb==0)
        {
            nn=tjs[i].a;
            nt=tjs[i].tp;
            if(nt==1)
                adj[nn+1].pb(nn);
            else
                adj[nn].pb(nn+1);
        }
        else if(nb==1)
        {
            nn=tjs[i].b;
            nt=tjs[i].tp;
            if(nt==1)
                adj[nn+1].pb(nn);
            else
                adj[nn].pb(nn+1);
        }
        else
        {
            nn=tjs[i].c;
            nt=tjs[i].tp;
            if(nt==1)
                adj[nn+1].pb(nn);
            else
                adj[nn].pb(nn+1);
        }
    }
}

void outs(int mask)
{
    int nb,nn,nt;
    rep(i,k)
    {
        nb=(mask/pows[i])%3;
        if(nb==0)
        {
            nn=tjs[i].a;
            nt=tjs[i].tp;
            if(nt==1)
                adj[nn+1].pop_back();
            else
                adj[nn].pop_back();
        }
        else if(nb==1)
        {
            nn=tjs[i].b;
            nt=tjs[i].tp;
            if(nt==1)
                adj[nn+1].pop_back();
            else
                adj[nn].pop_back();
        }
        else
        {
            nn=tjs[i].c;
            nt=tjs[i].tp;
            if(nt==1)
                adj[nn+1].pop_back();
            else
                adj[nn].pop_back();
        }
    }
}

int col[mt],low[mt],tim[mt],timer;
int group_id[mt],components;
bool ans[mt]; //boolean assignment ans
stack<int>S;
void scc(int u)
{
    low[u] = tim[u] = timer++;
    col[u] = 1;
    S.push(u);
    int i, elements = adj[u].size(), v, tem;
    for(i = 0; i < elements; i++)
    {
        v = adj[u][i];
        if(col[v] == 1)
            low[u] = min(low[u], tim[v]);
        else if(col[v] == 0)
        {
            scc(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == tim[u])
    {
        do
        {
            tem = S.top();
            S.pop();
            group_id[tem]=components;
            col[tem] = 2;
        }
        while(tem != u);
        components++;
    }
}
void TarjanSCC() //n=nodes (some change may be required here)
{
    int i;
    timer=components=0;
    ms(col,0);
    while(!S.empty()) S.pop();
    rep(i,n) if(col[i]==0) scc(i);
    return;
}
//double nodes needed normally
bool TwoSAT() //n=nodes (some change may be required here)
{
    TarjanSCC();
    int i;
    for(i=0; i<n; i+=2)
    {
        if(group_id[i]==group_id[i+1]) return 0;
        if(group_id[i]<group_id[i+1])
            ans[i/2]=true;
        else ans[i/2]=false;
    }
    return 1;
}

vec_<int>mans;
void pre2()
{
    clr(tjs);
    clr(mans);
    rep(i,n)
    clr(adj[i]);
}


int main ()
{
    pre1();
    int i,j,test,t=1,tp,a,b,c,mask,m;
    bool ap;
    sci1(test);
    while(test--)
    {
        sci1(n);
        ap=0;
        n<<=1;
        pre2();
        sci2(m,k);
        while(m--)
        {
            sci3(tp,a,b);
            a--;
            b--;
            a<<=1;
            b<<=1;
            if(tp==1)
            {
                adj[a+1].pb(b);
                adj[b+1].pb(a);
            }
            else if(tp==2)
            {
                adj[a+1].pb(b+1);
                adj[b].pb(a);
            }
            else if(tp==3)
            {
                adj[a].pb(b+1);
                adj[b].pb(a+1);
            }
            else
            {
                adj[a+1].pb(b);
                adj[b+1].pb(a);
                adj[a].pb(b+1);
                adj[b].pb(a+1);
            }
        }


        rep(i,k)
        {
            sci1(tp);
            sci3(a,b,c);
            a--;
            b--;
            c--;
            a<<=1;
            b<<=1;
            c<<=1;
            tjs.pb({tp,a,b,c});
        }
        mask=pows[k];
        while(mask--)
        {
            ins(mask);
            if(TwoSAT())
            {
                ap=1;
                for(i=0;i<n;i+=2)
                    if(ans[i/2])
                    mans.pb(i/2+1);
                break;
            }
            outs(mask);
        }
        printf("Case %d: ",t++);
        if(ap)
        {
            printf("Possible");
            printf(" %d",sz(mans));
            rep(i,sz(mans))
            printf(" %d",mans[i]);
        }
        else
            printf("Impossible");
        printf(".\n");
    }
    return 0;
}










