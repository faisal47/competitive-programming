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


#define mt 200010
#define mod
#define MAX 200010
#define LOGMAX 20


int stable1[MAX][LOGMAX], arr1[MAX];
int stable2[MAX][LOGMAX], arr2[MAX];

void preprocess(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        stable1[i][0] = arr1[i];
        stable2[i][0] = arr2[i];
    }
    for(j = 1; (1<<j) <= n; j++)
    {
        for(i = 0; i + (1<<j) - 1 < n; i++)
            {
                stable1[i][j] = max(stable1[i][j-1], stable1[i+(1<<(j-1))][j-1]);
                stable2[i][j] = min(stable2[i][j-1], stable2[i+(1<<(j-1))][j-1]);
            }
    }
}

int query1(int a,int b)
{
        int lg = log2(b-a+1);
        return max(stable1[a][lg], stable1[b-(1<<lg)+1][lg]);
}


int query2(int a,int b)
{
        int lg = log2(b-a+1);
        return min(stable2[a][lg], stable2[b-(1<<lg)+1][lg]);
}

int bs1(int l,int r)
{
    int mid,ret=inf,ind=l;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(query1(ind,mid) < query2(ind,mid))
            l=mid+1;
        else
        {
            ret=min(ret,mid);
            r=mid-1;
        }
    }
    if(ret == inf)
        return -1;
    return ret;
}

int bs2(int l,int r)
{
    int mid,ret=-1,ind=l;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(query1(ind,mid) <= query2(ind,mid))
            {
                l=mid+1;
                ret=max(ret,mid);
            }
        else
            r=mid-1;
    }
    return ret;
}



int main ()
{
    cffi;
    int i,j,test,n,t=1,l,r;
    ll ans=0;
    cin>>n;
    rep(i,n)
    cin>>arr1[i];
    rep(i,n)
    cin>>arr2[i];

    preprocess(n);

    rep(i,n)
    {
        if(arr1[i]>arr2[i])
            continue;
        l=bs1(i,n-1);
        if(l== -1)
            continue;
        r=bs2(i,n-1);
        ans+=(ll)(r-l+1);
    }

    deb(ans);

    return 0;
}