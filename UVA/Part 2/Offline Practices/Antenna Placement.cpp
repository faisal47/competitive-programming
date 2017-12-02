/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

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
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;

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
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
int X[]= {-1,0,1,0};
int Y[]= {0,1,0,-1};

/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt 45*15
#define mod

vec_<int>adj[mt];
bool col[mt];
int par[mt],n,m;
char arr[45][15];

bool check(int a,int b)
{
    if(1&a)
    {
        if(1&b)
            return 1;
        return 0;
    }
    if(1&b)
        return 0;
    return 1;
}

bool check2(int a,int b)
{
    return a>=0 && a<n && b>=0 && b<m && arr[a][b]=='*';
}

int c1,c2;

bool dfs(int u)
{
    //if(col[u]) return false;
    int i,k,v;
    k = adj[u].size();
    for(i=0; i<k; i++)
    {
        v = adj[u][i];
        if(col[v] == 0)
        {
            col[v] = 1;
            if(par[v] == -1 || dfs(par[v]))
            {
                par[v] = u;
                return true;
            }
        }
    }
    return false;
}


int bpm()
{
    int i,j,ret=0;

    for(i=0; i<c1; i++)
    {
        for(j=0; j<c2; j++) col[j] = 0;
        if(dfs(i)) ret++;
    }
    return ret;

}

int main ()
{
    //fop;
   // freopen("output.txt","w",stdout);
    int test,i,j,k,i1,j1,ans;
    map<pii,int>ma1;
    map<pii,int>ma2;
    sci1(test);
    while(test--)
    {
        c1=c2=0;
        clr(ma1);
        clr(ma2);
        sci2(n,m);
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                scch(arr[i][j]);
//                    if(arr[i][j]=='*')
//                        mot++;
            }

        for(i=0; i<mt; i++)
        {
            clr(adj[i]);
            par[i]=-1;
        }


        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                if(arr[i][j] == '*')
                {
                    if(check(i,j))
                    {
                        if(ma1.find(mp(i,j)) == ma1.end())
                            ma1[mp(i,j)]=c1++;

                        for(k=0; k<4; k++)
                        {
                            i1=i+X[k];
                            j1=j+Y[k];
                            if(check2(i1,j1))
                            {
                                if(ma2.find(mp(i1,j1)) == ma2.end())
                                    ma2[mp(i1,j1)]=c2++;

                               // deb("making graph from ",i,j,"to ",i1,j1);

                                adj[ma1[mp(i,j)]].pb(ma2[mp(i1,j1)]);
                                //adj[ma2[mp(i1,j1)]].pb(ma1[mp(i,j)]);
                            }
                        }
                    }
                    else
                    {
                        if(ma2.find(mp(i,j)) == ma2.end())
                            ma2[mp(i,j)]=c2++;
                    }
                }
            }

        ans=bpm();

        //deb("main ans == ",ans);

        printf("%d\n",ans+(c1+c2)-(ans<<1));
    }
    return 0;
}
