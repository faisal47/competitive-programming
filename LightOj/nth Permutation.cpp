/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
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

#define mt 22
#define mod

string st;

ll fact[mt];

void fact_gen()
{
    ll i;
    fact[0]=1ll;
    for(i=1ll; i<=20; i++)
        fact[i]=fact[i-1]*i;

}

ll ekhon_mot(int mask)
{
    ll ret=fact[sz(st)-__builtin_popcount(mask)];

    int i,c=1;
    char pre='0';

    for(i=0; i<sz(st); i++)
    {
        if(!(mask & (1<<i)))
        {
            if(st[i]!=pre)
            {
                pre=st[i];
                ret/=fact[c];
                c=1;
            }
            else
                c++;
        }
    }

    ret/=fact[c];

    return ret;
}

string solve(ll n)
{
    string ret="";
    ll n_mot;

    int mask=0,i;

    while(n > 0ll)
    {
        for(i=0; i<sz(st); i++)
        {
            if(!(mask & (1<<i)))
            {
                if(i>0 && (!(mask & (1<<(i-1)))) && st[i]==st[i-1])
                    continue;

                n_mot=ekhon_mot(mask | (1<<i));
                if(n-n_mot>0)
                {
                    n-=n_mot;
                }
                else
                {
                    ret+=st[i];
                    mask|=(1<<i);
                    break;
                }
            }
        }

        if(__builtin_popcount(mask) == sz(st)-1)
        {
            for(i=0; i<sz(st); i++)
            {
                if(!(mask & (1<<i)))
                {
                    ret+=st[i];
                    break;
                }
            }
            break;
        }
    }
    return ret;
}

int main ()
{
    fact_gen();
    char arr[mt];
    int test,t=1;
    ll n;

    sci1(test);

    while(test--)
    {
        scanf(" %s %lld",arr,&n);
        st=arr;
        sort(all(st));

        if(ekhon_mot(0) < n)
        {
            printf("Case %d: Impossible\n",t++);
            continue;
        }

        printf("Case %d: %s\n",t++,solve(n).c_str());
    }

    return 0;
}


