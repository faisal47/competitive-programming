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

#define mt 200010
#define mod

ll arr1[mt];
ll arr2[mt],n,m;

ll bs1(ll num)
{
    ll l=1;
    ll r=n;
    ll mid;
    ll ret=-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(arr1[mid]<=num)
        {
            ret=max(ret,mid);
            l=mid+1;
        }
        else
            r=mid-1;
    }
    if(ret== -1)
        ret=0;
    return ret;
}


ll bs2(ll num)
{
    ll l=1;
    ll r=m;
    ll mid;
    ll ret=-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(arr2[mid]<=num)
        {
            ret=max(ret,mid);
            l=mid+1;
        }
        else
            r=mid-1;
    }
    if(ret== -1)
        ret=0;
    return ret;
}

int main ()
{
    cffi;
    ll i,j;

    cin>>n;
    set<ll>s;
    for(i=1; i<=n; i++)
    {
        cin>>arr1[i];
        s.insert(arr1[i]);
    }

    cin>>m;
    for(i=1; i<=m; i++)
    {
        cin>>arr2[i];
        s.insert(arr2[i]);
    }

    sort(arr1+1,arr1+1+n);
    sort(arr2+1,arr2+1+m);
    set<ll>::iterator it;
    ll a,b,dm,num,ansa,ansb,dt,l,ba,da;
    dm=-inf;
    ansa=-1;
    for(it=s.begin(); it != s.end(); it++)
    {
        num=*it;
        l=bs1(num-1);
        a=2*l + (n-l)*3;

        l=bs2(num-1);
        b=2*l + (m-l)*3;
        dt=a-b;


        if(dt>dm)
        {
            dm=dt;
            ansa=a;
            ansb=b;
        }
        else if(dt==dm && ansa<a)
        {
            ansa=a;
            ansb=b;
        }


        l=bs1(num);
        a=2*l + (n-l)*3;

        l=bs2(num);
        b=2*l + (m-l)*3;
        dt=a-b;


        if(dt>dm)
        {
            dm=dt;
            ansa=a;
            ansb=b;
        }
        else if(dt==dm && ansa<a)
        {
            ansa=a;
            ansb=b;
        }


        l=bs1(num+1);
        a=2*l + (n-l)*3;

        l=bs2(num+1);
        b=2*l + (m-l)*3;
        dt=a-b;


        if(dt>dm)
        {
            dm=dt;
            ansa=a;
            ansb=b;
        }
        else if(dt==dm && ansa<a)
        {
            ansa=a;
            ansb=b;
        }

    }

    cout<<ansa<<":"<<ansb;

    return 0;
}