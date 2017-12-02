#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1ll<<55
#define mp make_pair
#define pii pair<ll,ll>
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
#define CF ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//

#define mt 200010
#define mod

ll low[mt],exact[mt],t,n,col[mt],scc_count,under_scc[mt];
pii scc_info[mt];
pii info[mt];
pii dp[mt];
vec_<ll>v[mt],dag[mt];
stack<ll>s;
void initialize()
{
    ll i;
    scc_count=0;
    t=1;
    while(!s.empty())
    s.pop();
    for(i=1;i<=n;i++)
    {
        clr(v[i]);
        clr(dag[i]);
        exact[i]=low[i]=col[i]=0;
        dp[i].fs=-1ll;
    }
}

void tarjan(ll a)
{
    s.push(a);
    col[a]=1;
    low[a]=exact[a]=t++;
    ll i,j;
    for(i=0;i<v[a].size();i++)
    {
        j=v[a][i];
        if(!col[j])
        {
           tarjan(j);
           low[a]=min(low[a],low[j]);
        }
        else if(col[j]==1)
         low[a]=min(low[a],exact[j]);
    }
    if(exact[a]==low[a])
    {
        ll mini=inf,mini2=inf;

        scc_count++;
        j=-1;
        while(j!=a)
        {
            j=s.top();
            s.pop();
            col[j]=2;
            under_scc[j]=scc_count;

            if(mini > info[j].fs)
            {
                mini=info[j].fs;
                mini2=info[j].sc;
            }
            else if(mini == info[j].fs)
            {
                mini2=min(mini2,info[j].sc);
            }
        }

        scc_info[scc_count]=mp(mini,mini2);
    }
}

void create_dag()
{
    ll i,j,p,q;
    for(i=1;i<=n;i++)
    {
        p=under_scc[i];
        for(j=0;j<v[i].size();j++)
        {
            q=under_scc[v[i][j]];
            if(p!=q)
            {
                dag[p].pb(q);
            }
        }
    }
}

pii dfs(ll a)
{
    pii &ret=dp[a];

    if(ret.fs!=-1)
    return ret;

    ret.fs=scc_info[a].fs;
    ret.sc=scc_info[a].sc;
    ll i;

    for(i=0;i<dag[a].size();i++)
    {
        pii ret2=dfs(dag[a][i]);
        if(ret.fs > ret2.fs)
            ret=ret2;
        else if(ret.fs == ret2.fs)
            ret.sc=min(ret.sc,ret2.sc);
    }

    return ret;
}

int main ()
{
    CF;

    ll i,j,n1;
    string arr[mt];

    cin>>n;
    n1=n;
    for(i=1;i<=n;i++)
        {
            cin>>arr[i];
            for(j=0;j<sz(arr[i]);j++)
                arr[i][j]=tolower(arr[i][j]);
        }

    string a,b;

    cin>>n;
    ll m=1ll;
    map<string,ll>ma;
    n*=2ll;
    initialize();
    n/=2ll;
    while(n--)
    {
        cin>>a>>b;
        for(j=0;j<sz(a);j++)
            a[j]=tolower(a[j]);

        for(j=0;j<sz(b);j++)
            b[j]=tolower(b[j]);

        if(ma.find(a)==ma.end())
        {
            ma[a]=m;
            ll c1=0ll;
            ll c2=sz(a);
            for(j=0;j<sz(a);j++)
                if(a[j]=='r')
                c1++;
            info[m]=mp(c1,c2);
            m++;
        }

        if(ma.find(b)==ma.end())
        {
            ma[b]=m;
            ll c1=0ll;
            ll c2=sz(b);
            for(j=0;j<sz(b);j++)
                if(b[j]=='r')
                c1++;
            info[m]=mp(c1,c2);
            m++;
        }
        v[ma[a]].pb(ma[b]);
    }

    n=m-1;


    for(i=1;i<=n;i++)
        if(!col[i])
        tarjan(i);

    create_dag();

    ll ans1,ans2;
    ans1=0ll;
    ans2=0ll;

    for(i=1;i<=n1;i++)
    {
        a=arr[i];
        if(ma.find(a)==ma.end() || sz(v[ma[a]])==0)
        {
            ll c1=0ll;
            ll c2=sz(a);
            for(j=0;j<sz(a);j++)
                if(a[j]=='r')
                c1++;
            ans1+=c1;
            ans2+=c2;
        }
        else
        {
            ll uscc=under_scc[ma[a]];
            dfs(uscc);
            ans1+=dp[uscc].fs;
            ans2+=dp[uscc].sc;
        }
    }

    deb(ans1,ans2);

    return 0;
}

//2500000000