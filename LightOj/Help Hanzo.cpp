#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<30
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
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define repa(i,n) for(auto i: n)
#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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


#define SET(x, n) (x[n>>6]|=(1<<((n>>1)&31)))
#define CHK(x, n) (x[n>>6]&(1<<((n>>1)&31)))
#define sqr(x) ((x)*(x))
#define MAX 46656
#define RAN 100032
#define LMT 216
#define LEN 4830


unsigned base[MAX/64], seg[RAN/64], primes[LEN];

void sieve()
{
	unsigned i, j, k;
	for(i=3;i<LMT;i+=2)
		if(!CHK(base, i))
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				SET(base, j);
	for(i=3,j=0;i<MAX;i+=2)
		if(!CHK(base, i))
			primes[j++]=i;
	return;
}

int seg_sieve(int a, int b)
{
	unsigned i, j, k, cnt=0;
	if(a<=2 && b>=2) cnt++;
	if(b<2) return 0;
	if(b<=2) return 1;
	if(a<3) a=3;
	if(!(a&1)) a++;
	memset(seg, 0, sizeof seg);
	for(i=0;sqr(primes[i])<=b;i++)
	{
//	    deb("hola");
		j = primes[i] * ((a+primes[i]-1)/primes[i]);
		if(!(j&1)) j+=primes[i];
		for(k=(primes[i]<<1);j<=b;j+=k)
			if(j!=primes[i])
				SET(seg, (j-a));
	}
	for(i=0;i<=(b-a);i+=2)
	{
		if(!(CHK(seg, i)))
			cnt++;
	}
	return cnt;
}

int main ()
{
    cffi;
    int test,n,t=1;
    unsigned i,j;
    sieve();
    cin>>test;
    while(test--)
    {
        cin>>i>>j;
        cout<<"Case "<<t++<<": "<<seg_sieve(i,j)<<endl;
    }
    return 0;
}










