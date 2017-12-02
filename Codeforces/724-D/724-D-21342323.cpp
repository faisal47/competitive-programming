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

pii seg[4*mt];
string st;

void build(int node,int l,int r)
{
    if(l==r)
    {
        seg[node]= {st[l-1],l};
        return;
    }

    int mid=l+r >> 1;
    int b=node <<1;
    build(b,l,mid);
    build(b|1,mid+1,r);
    seg[node]=min(seg[b],seg[b|1]);
    if(seg[b].fs == seg[b|1].fs)
        seg[node].sc=seg[b|1].sc;
}

int ml,mr;

pii solve(int node,int l,int r)
{
    if(r<ml || l>mr)
        return {inf,inf};

    if(l>=ml && r<=mr)
        return seg[node];

    int mid=l+r >> 1;
    int b=node <<1;
    pii temp1=solve(b,l,mid);
    pii temp2=solve(b|1,mid+1,r);
    pii temp=min(temp1,temp2);
    if(temp1.fs == temp2.fs)
        temp.sc=temp2.sc;
    return temp;
}

string ans;

int mtcc[30];

int main ()
{
    cffi;
    int i,j,test,n,t=1,m;
    pii mini= {-inf,-inf};
    cin>>m>>st;
    repa(b,st)
    mtcc[b-'a']++;
    pii ret;
    build(1,1,sz(st));

    set<char>ss;

    rep1(i,sz(st)-m+1)
    {
        ml=i;
        mr=i+m-1;
        mini=max(mini,solve(1,1,sz(st)));
    }

    repa(b,st)
    if(b<mini.fs)
        ss.insert(b);

    ans=char(mini.fs);

    if(sz(ss)==0)
    {
        ans="";
        i=1;
        while(i<=sz(st)-m+1)
        {
            ml=i;
            mr=i+m-1;
            ret=solve(1,1,sz(st));
            if(ret.fs == mini.fs)
                ans+=char(mini.fs);
            i=ret.sc+1;
//            deb(i);
        }
    }
    else
    {
        char lc=char(mini.fs);
        ans="";
        repa(b,ss)
        rep(i,mtcc[b-'a'])
        ans+=b;

//        deb(ans);

        i=1;
        while(i<=sz(st)-m+1)
        {
            ml=i;
            mr=i+m-1;
            ret=solve(1,1,sz(st));
            if(ret.fs == mini.fs)
                ans+=char(mini.fs);
            i=ret.sc+1;
//            deb(i);
        }

    }

    deb(ans);

    return 0;
}