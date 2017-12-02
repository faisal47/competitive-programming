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
#define make_flush  cout << flush; //    fflush(stdout);
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
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
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

#define mt 100010
#define mod

int arr1[mt],arr2[mt];
string a,b;

void pre()
{
    ms(arr1,-1);
    ms(arr2,-1);
}

void go1()
{
    int i=0,j=0;
    while(i<sz(a) && j<sz(b))
    {
        if(a[i]==b[j])
            arr1[j++]=i;
        i++;
    }
}

void go2()
{
    int i=sz(a)-1,j=sz(b)-1;
    while(i>=0 && j>=0)
    {
        if(a[i]==b[j])
            arr2[j--]=i;
        i--;
    }
}

int ansl,ansr;
vec_<int>v1,v2;

int go(int llim)
{
    int ret=inf;
    int l=0,r=sz(v2)-1;
    while(l <= r)
    {
        int mid= l+r >> 1;
        if(v2[mid] < llim)
            l=mid+1;
        else
        {
            ret=min(ret,mid);
            r=mid-1;
        }
    }

    if(ret >= inf)
        return 0;

    return sz(v2)-ret;
}

void bs()
{
    int ret=0,rl,rr;
    rep(i,sz(b))
    {
        if(arr1[i] != -1)
            v1.pb(arr1[i]);
        if(arr2[i] != -1)
            v2.pb(arr2[i]);
    }
    ansl=0;
    ansr=0;

    rl=0;
    rr=go(0);
    if(rl + rr > ansl+ansr)
    {
        ansl=rl;
        ansr=rr;
    }
    rep(i,sz(v1))
    {
        rl=i+1;
        rr=go(v1[i]+1);
        if(rl+rr > ansl+ansr)
        {
            ansl=rl;
            ansr=rr;
        }
    }
}

int main ()
{
    cffi;
    pre();
    int i,j,test,n,t=1;
    cin>>a>>b;
    go1();
    go2();
    bs();
    if(ansl ==0 && ansr==0)
    {
        deb("-");
        return 0;
    }

    rep(i,ansl)
    cout<<b[i];

    rep(i,sz(b))
    if(sz(b)-i <= ansr && i>=ansl)
        cout<<b[i];

    return 0;
}