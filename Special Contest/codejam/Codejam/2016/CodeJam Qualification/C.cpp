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
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};


#define mt 231072000
#define mod

#define fop freopen("cin.txt","r",stdin);freopen("coutput2.txt","w",stdout);

vec_<int>primes;
bool col[mt];
bool yprime[mt];

void pre()
{
    primes.pb(2);
    int i,j;
    yprime[2]=1;
    for(i=3;i<=mt-5;i+=2)
        if(!col[i])
    {
        primes.pb(i);
        yprime[i]=1;
        for(j=i;j<=mt-5;j+=i)
            col[j]=1;
    }
}

int cnt;
vec_<int>ans;
string tob(int num)
{
    string ret="";
    while(num>0)
    {
        if(num%2)
            ret+='1';
        else
            ret+='0';
        num/=2;
    }
    reverse(all(ret));
    return ret;
}

bool okay(ll num,ll base)
{
    ll nnum=0,pp=1;
    while(num>0)
    {
        nnum+=((num%2)*pp);
        pp*=base;
        num/=2;
    }
    if(nnum<=1)
        return 0;
    int i;
    rep(i,sz(primes))
    if(nnum%primes[i] == 0 && primes[i]<nnum)
    {
        ans.pb(primes[i]);
        return 1;
    }
    else if(nnum < primes[i])
        break;
    return 0;
}

void go(int num)
{
    clr(ans);
    int base,i;
    for(base=2;base<=10;base++)
    {
        if(!okay(num,base))
            return;
    }
//    exit(0);
    cout<<tob(num)<<" ";
    rep(i,sz(ans))
    cout<<" "<<ans[i];
    cout<<endl;
    cnt++;
}

int main ()
{
    fop;
    pre();
    int i,j,test,n,t=1,a,b;
    cin>>t>>a>>b;
    deb("Case #1:");
    int mask=1<<15;
    int pre=1<<15;
    while(mask--)
    {
        int nm=pre+mask;
        if(mask %2 ==0)
            continue;
        go(nm);
        if(cnt == 50)
            break;
    }
    return 0;
}










