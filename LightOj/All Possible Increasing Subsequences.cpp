#include <bits/stdc++.h>

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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
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
#define LL long long
#define mt 100010
#define SZ 100010
#define mod 1000000007

int segtree[SZ * 4], beg, en, sum;
int lazy[SZ * 4];

void lazy_update(int lef, int rig, int cur, int val)
{
    if(lazy[cur])
    {
        segtree[cur] = (segtree[cur]+((rig - lef + 1) * lazy[cur])%mod)%mod;
        if(lef != rig)
        {
            lazy[cur << 1] =(lazy[cur << 1] + lazy[cur])%mod;
            lazy[(cur << 1) + 1] =(lazy[(cur << 1) + 1] + lazy[cur])%mod;
        }
        lazy[cur] = 0;
    }
    if(lef > en || rig < beg)
        return;
    if(lef >= beg && rig <= en)
    {
        segtree[cur] = (segtree[cur]+((rig - lef + 1) * val)%mod)%mod;
        if(rig != lef)
        {
            lazy[cur << 1] =(lazy[cur << 1] + val)%mod;
            lazy[(cur << 1) + 1] =(lazy[(cur << 1) + 1] + val)%mod;
        }
        return;
    }
    lazy_update(lef, (lef + rig) >> 1, cur << 1, val);
    lazy_update(((lef + rig) >> 1) + 1, rig, (cur << 1) + 1, val);
    segtree[cur] = (segtree[cur << 1] + segtree[(cur << 1) + 1])%mod;
}

int query(int lef, int rig, int cur)
{
    if(lazy[cur])
    {
        segtree[cur] = (segtree[cur]+((rig - lef + 1) * lazy[cur])%mod)%mod;
        if(lef != rig)
        {
            lazy[cur << 1] =(lazy[cur << 1] + lazy[cur])%mod;
            lazy[(cur << 1) + 1] =(lazy[(cur << 1) + 1] + lazy[cur])%mod;
        }
        lazy[cur] = 0;
    }
    if(lef > en || rig < beg)
        return 0;
    if(lef >= beg && rig <= en)
        return segtree[cur];
    return (query(lef, (lef + rig) >> 1, cur << 1) + query(((lef + rig) >> 1) + 1, rig, (cur << 1) + 1))%mod;
}

int arr[mt];

void build(int node,int l,int r)
{
    lazy[node]=0;
    segtree[node]=0;
    if(l==r)
        return;
    int mid=(l+r)>>1;
    build(node<<1,l,mid);
    build((node<<1)|1,mid+1,r);
}

int main ()
{
    cffi;
    int i,j,test,t=1,n,c,ans,temp,num;
    map<int,int>ma;
    map<int,int>:: iterator it;
    cin>>test;
    while(test--)
    {
        clr(ma);
        ans=0;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
            ma[arr[i]]=1;
        }
        c=1;
        for(it=ma.begin();it!=ma.end();it++)
            ma[it->fs]=c++;
        for(i=1;i<=n;i++)
            arr[i]=ma[arr[i]];
        c--;
        build(1,1,c);
        for(i=1;i<=n;i++)
        {
            beg=1;
            temp=0;
            num=arr[i];
            en=num-1;
            if(beg <= en)
                temp=query(1,c,1);
//            ans=(ans + temp + 1)%mod;
            beg=num;
            en=num;
            lazy_update(1,c,1,temp+1);
        }
        cout<<"Case "<<t++<<": ";
        beg=1;en=c;
        deb(query(1,c,1));
    }
    return 0;
}


