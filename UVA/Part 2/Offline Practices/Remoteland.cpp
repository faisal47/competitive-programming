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

//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}

/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt 10000010
#define mod 1000000007


const int SZ = 10000000+1;

ll bigmod(ll B,ll P)
{
    ll R=1;
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%mod;
        }
        P/=2;
        B=(B*B)%mod;
    }
    return R;
}

bool flag[mt];
//vec_<ll>primes;
bool sieve[SZ];
ll prime[664579];
int p;
void SOE()
{
	int i, j, k=0, r;
	prime[k++] = 2LL;
	for(i=3; i<=SZ-1; i+=2)
	{
		if(sieve[i]==false)
		{
			prime[k++] = (ll)(i);
			if(i<(SZ-1)/i)
			{
				r = (i<<1);
				for(j=(i*i); j<(SZ-1); j+=r)
				{
					sieve[j] = true;
				}
			}
		}
	}
	p = k;
	return ;
}
//void sieve()
//{
//    ll i,j;
//    ll sq=sqrt(mt-5);
//    primes.pb(2);
//    for(i=3; i<=sq; i+=2)
//    {
//        if(!flag[i])
//        {
//            primes.pb(i);
//            for(j=i*i; j<mt-5; j+=i)
//                flag[j]=1;
//        }
//    }
//
//    if(sq%2ll == 0ll)
//        sq++;
//
//    for(i=sq; i<mt-5; i+=2)
//        if(!flag[i])
//            primes.pb(i);
//}

int main ()
{
    ll i,j,temp,c,ans;

//    sieve();
    SOE();
    ll n;

    ll ordhek;
    while(scanf("%lld",&n)==1)
    {
        ans=1ll;

        if(n==0ll)
            break;

        ordhek=(n>>1ll);

        for(i=0; prime[i]<=ordhek; i++)
        {
            temp=n;
            c=0ll;
            while(temp>0ll)
            {
                c+=temp/prime[i];
                temp/=prime[i];
            }

            if(c & 1ll)
                c--;

            ans=(ans*bigmod(prime[i],c))%mod;

        }

        printf("%lld\n",ans);
    }

    return 0;
}

