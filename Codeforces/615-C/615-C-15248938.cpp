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
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
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


#define mt 3010
#define mod

string text,pattern;
int f[2*mt];
string pat,arr;

vec_<pii>v[2][mt];

void kmp(int ind,int kind)
{
    text=pat;
    pattern=arr.substr(ind);
    int len2=pattern.size();
    pattern.push_back('#');
    pattern+=text;
    int k;
    f[0]=k=0;
    int i;
    for(i=1; i<pattern.size(); i++)
    {
        while(k>0 && pattern[i]!=pattern[k])
            k=f[k-1];
        if(pattern[i]==pattern[k])
            k++;
        f[i]=k;
    }
//    deb("yo");
    for(i=len2+1; i<pattern.size(); i++)
        if(f[i] > 0)
            {
//                deb(kind,ind,i-len2,f[i]);
                v[kind][ind].pb({i-len2-f[i]+1,f[i]});
            }
}

int dp[mt];

int solve(int ind)
{
    if(ind >= sz(arr))
        return 0;
    int &ret=dp[ind],baki,i;
    if(ret != -1)
        return ret;
    ret=inf;
    baki=sz(arr)-ind;
    rep(i,sz(v[0][ind]))
    {
        if(baki >= v[0][ind][i].sc)
        ret=min(ret,1+solve(ind+v[0][ind][i].sc));
    }
    rep(i,sz(v[1][ind]))
    {
        if(baki >= v[1][ind][i].sc)
        ret=min(ret,1+solve(ind+v[1][ind][i].sc));
    }
    return ret;
}

void solve2(int ind)
{
    if(ind >= sz(arr))
        return;
    int ret=dp[ind],baki,i;
    baki=sz(arr)-ind;
    rep(i,sz(v[0][ind]))
    {
        if(baki >= v[0][ind][i].sc && ret==1+solve(ind+v[0][ind][i].sc))
        {
            deb(v[0][ind][i].fs,v[0][ind][i].sc+v[0][ind][i].fs-1);
            solve2(ind+v[0][ind][i].sc);
            return;
        }
    }
   rep(i,sz(v[1][ind]))
    {
        if(baki >= v[1][ind][i].sc && ret==1+solve(ind+v[1][ind][i].sc))
        {
            int a=v[1][ind][i].fs;
            int b=v[1][ind][i].sc+v[1][ind][i].fs-1;
            a=sz(pat)-a+1;
            b=sz(pat)-b+1;
            deb(a,b);
            solve2(ind+v[1][ind][i].sc);
            return;
        }
    }
    return;
}


int main ()
{
    cffi;
    int i,j,test,n;
    cin>>pat>>arr;
    rep(i,sz(arr))
        kmp(i,0);
    reverse(all(pat));

    rep(i,sz(arr))
        kmp(i,1);

    ms(dp,-1);

    int ans=solve(0);
    if(ans >= inf)
    {
        deb(-1);
        exit(0);
    }

    deb(ans);
    solve2(0);
    return 0;
}