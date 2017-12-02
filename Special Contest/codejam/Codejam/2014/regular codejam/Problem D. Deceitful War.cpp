/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

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
#define deb1(a) cout<<a<<endl;
#define deb2(a,b) cout<<a<<" "<<b<<endl
#define deb3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt
#define mod

vec_<dd>v1,v2;
int n;

bool ok(int s,int e)
{
    int i,j;
    int c1=s;
    int c2=0;
    while(c1<n && c2<e)
    {
        if(v1[c1]<v2[c2])
            return 0;
        c1++;
        c2++;
    }
    return 1;
}

int main ()
{
    fop;
    int test,t=1,i,ans1,ans2,j;
    dd a;
    map<int,bool>m;
    sci1(test);
     bool flag;

    while(test--)
    {
        clr(m);
        ans1=ans2=0;

        clr(v1);
        clr(v2);

        sci1(n);

        for(i=0; i<n; i++)
        {
            scd1(a);
            v1.pb(a);
        }

        for(i=0; i<n; i++)
        {
            scd1(a);
            v2.pb(a);
        }

        sort(all(v1));
        sort(all(v2));

        flag=false;

        int s,e;
        s=0;
        e=n;

        while(1)
        {
            flag=ok(s,e);
            if(flag)
            {
                ans1=e;
                break;
            }
            s++;
            e--;

        }

        for(i=0; i<n; i++)
        {
            flag=0;
            for(j=0; j<n; j++)
            {
                if(v2[j]>v1[i] && m.find(j)==m.end())
                {
                    m[j]=1;
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                ans2++;
                for(j=0; j<n; j++)
                {
                    if(m.find(j)==m.end())
                    {
                        m[j]=1;
                        break;
                    }
                }
            }
        }
        printf("Case #%d: %d %d\n",t++,ans1,ans2);
    }
    return 0;
}
