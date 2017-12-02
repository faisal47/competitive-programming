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


#define mt
#define SZ 200010
#define mod
#define LL long long

#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

LL segtree[SZ * 4], beg, en;
LL lazy[SZ * 4];
LL segtree2[SZ * 4];
LL lazy2[SZ * 4];


void lazy_update2(int lef, int rig, int cur, int val)
{
    if(lazy2[cur])
    {
        segtree2[cur] += (rig - lef + 1) * lazy2[cur];
        if(lef != rig)
        {
            lazy2[cur << 1] += lazy2[cur];
            lazy2[(cur << 1) + 1] += lazy2[cur];
        }
        lazy2[cur] = 0;
    }
    if(lef > en || rig < beg)
        return;
    if(lef >= beg && rig <= en)
    {
        segtree2[cur] += (rig - lef + 1) * val;
        if(rig != lef)
        {
            lazy2[cur << 1] += val;
            lazy2[(cur << 1) + 1] += val;
        }
        return;
    }
    lazy_update2(lef, (lef + rig) >> 1, cur << 1, val);
    lazy_update2(((lef + rig) >> 1) + 1, rig, (cur << 1) + 1, val);
    segtree2[cur] = segtree2[cur << 1] + segtree2[(cur << 1) + 1];
}
LL query2(int lef, int rig, int cur)
{
    if(lazy2[cur])
    {
        segtree2[cur] += (rig - lef + 1) * lazy2[cur];
        if(lef != rig)
        {
            lazy2[cur << 1] += lazy2[cur];
            lazy2[(cur << 1) + 1] += lazy2[cur];
        }
        lazy2[cur] = 0;
    }
    if(lef > en || rig < beg)
        return 0;
    if(lef >= beg && rig <= en)
        return segtree2[cur];
    return query2(lef, (lef + rig) >> 1, cur << 1) + query2(((lef + rig) >> 1) + 1,
            rig, (cur << 1) + 1);
}

void lazy_update(int lef, int rig, int cur, int val)
{
    if(lazy[cur])
    {
        segtree[cur] += (rig - lef + 1) * lazy[cur];
        if(lef != rig)
        {
            lazy[cur << 1] += lazy[cur];
            lazy[(cur << 1) + 1] += lazy[cur];
        }
        lazy[cur] = 0;
    }
    if(lef > en || rig < beg)
        return;
    if(lef >= beg && rig <= en)
    {
        segtree[cur] += (rig - lef + 1) * val;
        if(rig != lef)
        {
            lazy[cur << 1] += val;
            lazy[(cur << 1) + 1] += val;
        }
        return;
    }
    lazy_update(lef, (lef + rig) >> 1, cur << 1, val);
    lazy_update(((lef + rig) >> 1) + 1, rig, (cur << 1) + 1, val);
    segtree[cur] = segtree[cur << 1] + segtree[(cur << 1) + 1];
}
LL query(int lef, int rig, int cur)
{
    if(lazy[cur])
    {
        segtree[cur] += (rig - lef + 1) * lazy[cur];
        if(lef != rig)
        {
            lazy[cur << 1] += lazy[cur];
            lazy[(cur << 1) + 1] += lazy[cur];
        }
        lazy[cur] = 0;
    }
    if(lef > en || rig < beg)
        return 0;
    if(lef >= beg && rig <= en)
        return segtree[cur];
    return query(lef, (lef + rig) >> 1, cur << 1) + query(((lef + rig) >> 1) + 1,
            rig, (cur << 1) + 1);
}
ll arr1[SZ],arr2[SZ];

ll go1(ll a,ll ind,ll val)
{
    ll ret=0;
    ll nval=min(a,arr1[ind]+val);
    ret=nval-arr1[ind];
    arr1[ind]=nval;
    return ret;
}

ll go2(ll a,ll ind,ll val)
{
    ll ret=0;
    ll nval=min(a,arr2[ind]+val);
    ret=nval-arr2[ind];
    arr2[ind]=nval;
    return ret;
}



int main ()
{
    cffi;
    ll i,j,test,n,t=1,a,b,k,q,ord,d,maan,sum;
    cin>>n>>k>>b>>a>>q;
//    scanf("%I64d %I64d %I64d %I64d %I64d",&n,&k,&b,&a,&q);
    while(q--)
    {
//        scanf("%I64d",&t);
        cin>>t;
        if(t==1)
        {
//            scanf("%I64d %I64d ",&d,&ord);
            cin>>d>>ord;
            maan=go1(a,d,ord);
            beg=d;
            en=d;
            if(maan > 0)
            lazy_update(1,n,1,maan);
            maan=go2(b,d,ord);
            beg=d;
            en=d;
            if(maan > 0)
            lazy_update2(1,n,1,maan);

        }
        else
        {
            cin>>d;
//            scanf("%I64d",&d);
            sum=0;
            beg=1,en=d-1;
            if(beg<=en)
                sum=query(1,n,1);
            beg=d+k;
            en=n;
            if(beg <= en)
            sum+=query2(1,n,1);
            deb(sum);
//            printf("%I64d\n",sum);
        }
    }
    return 0;
}