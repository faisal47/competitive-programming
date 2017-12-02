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


#define mt 100010
#define MAX 100010
#define mod

int ans,trie[MAX][26], last,bc[mt];
bool cnt[mt];
string str;
vec_<int>adj[mt];
void add()
{
//    deb(str);
    int i, id, cur = 0;
    for(i = 0;i<sz(str) ; i++)
    {
        id = str[i] - 'a';
        if(trie[cur][id] == -1)
        {
            ans++;
            trie[cur][id] = ++last;
            adj[cur].pb(last);
            bc[cur]++;
            ms(trie[last], -1);
            cnt[last] = 0;
        }
        cur = trie[cur][id];
    }
    cnt[cur]=1;
//    deb(cur);
}
/// do clr(trie[0], -1) and last = 0 for every case

int k;
priority_queue<pii>q;
pii parm[mt];
bool col[mt];

void dfs(int node,int par,int dur)
{
    if(sz(adj[node]) > 1 || cnt[node]==1)
    {
//        deb(node,par,dur);
        parm[node]={dur,par};
        par=node;
        dur=0;
    }
    for(auto b:adj[node])
        dfs(b,par,dur+1);
    if(sz(adj[node]) == 0)
        {
            q.push({parm[node].fs,node});
//            deb(parm[node].fs,node);
        }
}

/*

1
4 3
bbc
abcde
abcdf
abcdg

8 6
fox
of
xfox
foo
foxxx
off
foff
foox

*/


void solve()
{
    pii v;
    while(!q.empty())
    {
        v=q.top();q.pop();
        if(v.sc == -1)
            continue;
        if(k==0 && cnt[v.sc])
            continue;

//        deb(v.fs,v.sc);
        if(k > 0 && cnt[v.sc])
        k--;
        ans-=v.fs;
//        deb("age ",v.sc);
        v=parm[v.sc];
        v.fs=parm[v.sc].fs;
//        deb("pore ",v.sc);
        bc[v.sc]--;
        if(!col[v.sc] && !bc[v.sc])
        {
            q.push(v);
            col[v.sc]=1;
        }
    }
}

int main ()
{
//    cffi;
    fop;
    int i,j,test,n,k1,t=1;
    cin>>test;
    while(test--)
    {
        ans=0;
        while(!q.empty())q.pop();
        ms(trie[0],-1);
        last=0;
        cin>>n>>k;
        k1=k;
        k=n-k;
        while(n--)
        {
            cin>>str;
            add();
        }
        dfs(0,-1,0);
//        deb(ans);
        solve();
//        deb(ans);
        rep(i,last+3)
        {
            col[i]=0;
            clr(adj[i]);
            cnt[i]=0;
            bc[i]=0;
        }
        ans*=2;
        ans+=k1;
        printf("Case #%d: %d\n",t++,ans);
    }
    return 0;
}










