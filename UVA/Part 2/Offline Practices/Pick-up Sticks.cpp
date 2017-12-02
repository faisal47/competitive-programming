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
#include <stdlib.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define pb push_back
#define vec_ vector
#define clr(a) a.clear()
#define eps 1e-7
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()

#define scch(a) scanf(" %c",&a)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scll1(a) scanf(" %lld",&a)
#define scll2(a,b) scanf(" %lld %lld",&a,&b)
#define scll3(a,b,c) scanf(" %lld %lld %lld",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define ll long long
#define sz(a) (int)a.size()
#define dd double

using namespace std;

#define mt 100010

struct PT
{
    dd x,y;
    PT() {}
    PT(dd x,dd y):x(x),y(y) {}
    PT operator - (const PT &p)const
    {
        return PT(x-p.x,y-p.y);
    }
};

dd EPS=1e-12;
dd dot(PT p,PT q)
{
    return p.x*q.x+p.y*q.y;
}

dd dist2(PT p,PT q)
{
    return dot(p-q,p-q);
}
dd cross(PT p,PT q)
{
    return p.x*q.y - p.y*q.x;
}
bool LinPal(PT a,PT b,PT c,PT d)
{
    return fabs(cross(b-a,c-d))<EPS;
}

bool LinCol(PT a,PT b,PT c,PT d)
{
    return LinPal(a,b,c,d) && fabs(cross(a-b,a-c))<EPS && fabs(cross(c-d,c-a))<EPS;
}

bool SegInt(PT a,PT b,PT c,PT d)
{
    if(LinCol(a,b,c,d))
    {
        if(dist2(a,c) < EPS || dist2(a,d)<EPS || dist2(b,c)<EPS || dist2(b,d)<EPS)
            return true;
        if(dot(c-a,c-b)>0 && dot(d-a,d-b)>0 && dot(c-b,d-b)>0)
            return 0;
        return 1;
    }
    if(cross(d-a,b-a)*cross(c-a,b-a)>0)return 0;
    if(cross(a-c,d-c)*cross(b-c,d-c)>0)return 0;
    return 1;
}

struct maan
{
    dd a,b,c,d;
};

vec_<maan>v;
set<int>ss,td;
int main()
{
    int i,j,n,k=0;
    int ans[1010];

    while(sci1(n) == 1)
    {
        if(n==0)
            break;
        clr(ss);
        clr(v);
        k=0;
        maan temp;
        for(i=0; i<n; i++)
        {
            clr(td);
            scanf(" %lf %lf %lf %lf",&temp.a,&temp.b,&temp.c,&temp.d);
            for(auto val : ss)
            {
                if(SegInt(PT(v[val].a,v[val].b),PT(v[val].c,v[val].d),PT(temp.a,temp.b),PT(temp.c,temp.d)))
                    td.insert(val);
            }
            for(auto val:td)
                ss.erase(val);

            ss.insert(i);
            v.pb(temp);
        }
        for(auto val:ss)
            ans[k++]=val;

        printf("Top sticks:");
        for(i=0; i<k; i++)
        {
            printf(" %d",ans[i]+1);
            if(i!=k-1)
                printf(",");
        }
        puts(".");
    }

    return 0;
}


