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
#define SZ(a) (int)a.size()
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


#define mt 5000010
#define mod

#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

string arr;

string s, t;
void prepare_string()
{
    int i;
    t = "^#";
    for(i = 0; i < SZ(s); i++)
        t += s[i], t += "#";
    t += "$";
}
int P[2*mt+20];
int manacher()
{
    prepare_string();
    int c = 0, r = 0, i, i_mirror, n = SZ(t) - 1;
    for(i = 1; i < n; i++)
    {
        i_mirror = (2 * c) - i;
        P[i] = r > i? min(r - i, P[i_mirror]) : 0;
        while(t[i + 1 + P[i]] == t[i - 1 - P[i]])
            P[i]++;
        if(i + P[i] > r)
        {
            c = i;
            r = i + P[i];
        }
    }
    return *max_element(P + 1, P + n);
}

ll go(int pos)
{
    ll ret=0,lagbe;
    int asi=pos;
    while(pos >1)
    {
        lagbe=pos/2;
        if(pos%2==0)
            lagbe--;
        lagbe*=2;
        if(pos%2==0)
            lagbe++;
        if(lagbe != P[pos])
            break;
        ret++;
        pos=pos/2+(pos%2);
    }
//    deb(asi,ret);
    return ret;
}

bool okay(int pos)
{
    int lagbe=pos/2;
    if(pos%2==0)
        lagbe--;
    lagbe*=2;
    if(pos%2==0)
        lagbe++;
    return lagbe == P[pos];
}

int pre_pos(int pos)
{
   return pos/2+(pos%2);
}

ll dp[mt*2+20];

int main ()
{
    cffi;
    int i,j,test,n;
    cin>>arr;
    s=arr;
    manacher();
    ll ans=0;
    for(i=2; i<=sz(arr)*2; i++)
    {
        if(okay(i))
            dp[i]++;
        if(dp[i])
        dp[i]+=dp[pre_pos(i)];
        ans+=dp[i];
    }
    deb(ans);
//    deb(arr);
//    rep(i,sz(t))
//    cout<<i<<" ";
//    cout<<endl;
//    rep(i,sz(t))
//    cout<<t[i]<<" ";
//    cout<<endl;
//    rep(i,sz(t))
//    cout<<P[i]<<" ";
    return 0;
}