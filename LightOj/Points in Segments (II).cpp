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


#define mt 2*50010
#define mod

map<int,int>ma;
int arr1[mt][2],arr[mt];
#define LL int
#define SZ mt
LL segtree[SZ * 4], beg, en;
LL lazy[SZ * 4];

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
    if(arr[lef] > en || arr[rig] < beg)
        return 0;
    if(arr[lef] >= beg && arr[rig] <= en)
        return segtree[cur];
    return query(lef, (lef + rig) >> 1, cur << 1) + query(((lef + rig) >> 1) + 1, rig, (cur << 1) + 1);
}


int main ()
{
    cffi;
    int i,j,test,t=1,n,q,c;

    sci1(test);
    map<int,int>::iterator it;

    while(test--)
    {
        clr(ma);
        ms(segtree,0);
        ms(lazy,0);
        sci2(n,q);
        for(i=1;i<=n;i++)
        {
            sci2(arr1[i][0],arr1[i][1]);
            ma[arr1[i][0]]=ma[arr1[i][1]]=1;
        }
        c=1;
        for(it=ma.begin();it !=ma.end();it++)
            {
                ma[it->fs]=c;
                arr[c++]=it->fs;
            }
        c--;
        for(i=1;i<=n;i++)
        {
            beg=ma[arr1[i][0]];
            en=ma[arr1[i][1]];
            lazy_update(1,c,1,1);
        }
        printf("Case %d:\n",t++);
        while(q--)
        {
            sci1(beg);
            en=beg;
            printf("%d\n",query(1,c,1));
        }
    }

    return 0;
}

