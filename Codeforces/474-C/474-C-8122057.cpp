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
//#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define fop   freopen("output.txt","w",stdout);
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
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


ll dur(ll x1,ll y1,ll x2,ll y2)
{
    return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
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

#define mt
#define mod

int ase[5][2],orig[5][2];
int ans;

void make_rotate(int i)
{
    int x,y;
    x=ase[i][0]-orig[i][0];
    y=ase[i][1]-orig[i][1];
    swap(x,y);
    x=-x;
    x+=orig[i][0];
    y+=orig[i][1];
    ase[i][0]=x;
    ase[i][1]=y;
}
vec_<int>v;

map<pii,int>ma;

bool solve2()
{
    clr(ma);
    int i,j,k,l;
    ll d1,d2,d3,d4,d5,d6;
    pii a,b,c,d;
    a=mp(ase[1][0],ase[1][1]);
    b=mp(ase[2][0],ase[2][1]);
    c=mp(ase[3][0],ase[3][1]);
    d=mp(ase[4][0],ase[4][1]);
    ma[a]=0;
    ma[b]=0;
    ma[c]=0;
    ma[d]=0;
    ma[a]++;
    ma[b]++;
    ma[c]++;
    ma[d]++;
    if(ma[a]>1 || ma[b]>1 || ma[c]>1 || ma[d]>1)
        return 0;

    sort(all(v));
    do
    {
        i=v[0];
        j=v[1];
        k=v[2];
        l=v[3];
        d1=dur(ase[i][0],ase[i][1],ase[j][0],ase[j][1]);
        d2=dur(ase[j][0],ase[j][1],ase[k][0],ase[k][1]);
        d3=dur(ase[k][0],ase[k][1],ase[l][0],ase[l][1]);
        d4=dur(ase[l][0],ase[l][1],ase[i][0],ase[i][1]);
        d5=dur(ase[i][0],ase[i][1],ase[k][0],ase[k][1]);
        d6=dur(ase[j][0],ase[j][1],ase[l][0],ase[l][1]);
        if(d1==d2 && d2== d3 && d3==d4 && d4==d1 && d5==d6)
        {
            return 1;
        }

    }
    while(next_permutation(all(v)));

    return 0;
}

void solve1()
{
    int i,j,k,l,c=0;
    int c1=0,c2=0,c3=0,c4=0;

    for(i=0; i<4; i++)
    {
        if(i)
        {
            make_rotate(1);
            c1++;
            if(c1==4)
                c2=0;
        }
        for(j=0; j<4; j++)
        {
            if(j)
            {
                make_rotate(2);
                c2++;
                if(c2==4)
                    c2=0;
            }

            for(k=0; k<4; k++)
            {
                if(k)
                {
                    make_rotate(3);
                    c3++;
                    if(c3==4)
                        c3=0;
                }
                for(l=0; l<4; l++)
                {
                    if(l)
                    {
                        make_rotate(4);
                        c4++;
                        if(c4==4)
                            c4=0;
                    }
                    if(solve2())
                    {
                        ans=min(ans,c1+c2+c3+c4);
                        return;
                    }
                }
            }
        }
    }

}

int main ()
{
    v.pb(1);
    v.pb(2);
    v.pb(3);
    v.pb(4);
    cffi;
    int i,j,n;
    cin>>n;

    while(n--)
    {
        for(i=1; i<=4; i++)
        {
            cin>>ase[i][0]>>ase[i][1]>>orig[i][0]>>orig[i][1];
        }
        ans=inf;
        solve1();
        if(ans>=inf)
            deb("-1");
        else
            deb(ans);
    }

    return 0;
}