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


#define mt 55
#define mod

#define rep(i,n) for(i=0;i<n;i++)

string arr[mt];
char ans[2*mt][2*mt];
vec_<pii>os,moves;
int n;

bool okay(int x,int y)
{
    return x>=0 && x<n && y>=0 && y<n;
}
bool col[mt][mt];

int main ()
{
    cffi;
    int i,j,x,y,k;
    cin>>n;

    rep(i,n)
        cin>>arr[i];

    rep(i,n)
    rep(j,n)
    if(arr[i][j]=='o')
        os.pb(mp(i,j));

    bool hobena_flag;

    for(i=-n; i<=n; i++)
        for(j=-n; j<=n; j++)
        {
            hobena_flag=0;
            if(!i && !j)
                continue;

            rep(k,sz(os))
            {
                x=i+os[k].fs;
                y=j+os[k].sc;
                if(!okay(x,y))
                    continue;

                if(arr[x][y] == '.')
                {
                    hobena_flag=1;
                    break;
                }
            }
            if(hobena_flag)
                continue;
//            deb(i,j);
            moves.pb(mp(i,j));
            rep(k,sz(os))
            {
                x=i+os[k].fs;
                y=j+os[k].sc;
                if(!okay(x,y))
                    continue;
                col[x][y]=1;
            }
        }

    rep(i,n)
    rep(j,n)
    if(arr[i][j]=='x' && !col[i][j])
    {
        deb("NO");
        return 0;
    }
//    deb(sz(moves));
    deb("YES");
    x=n-1;
    y=n-1;
    n=(2*n)-1;

    rep(i,n)
    rep(j,n)
    ans[i][j]='.';

    int x2,y2;
    rep(i,sz(moves))
    {
        x2=moves[i].fs+x;
        y2=moves[i].sc+y;
        if(!okay(x2,y2))
            continue;
        ans[x2][y2]='x';
    }
    ans[x][y]='o';
    rep(i,n)
    {
        rep(j,n)
        cout<<ans[i][j];
        cout<<endl;
    }

    return 0;
}