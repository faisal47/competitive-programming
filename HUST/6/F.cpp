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


#define mt 260
#define mod

int arr[mt][mt],n,m,cum[mt][mt],temp_cum[mt];

void pre(int h)
{
    rep1(i,n)
    rep1(j,m)
    cum[i][j]=cum[i][j-1]+(arr[i][j]>=h? 1:-1);
    rep1(j,m)
    rep1(i,n)
    cum[i][j]+=cum[i-1][j];
}

int get_sum(int r1,int r2,int c1)
{
    int ret=cum[r2][c1];
    ret-=cum[r1-1][c1];
    return ret;
}

pii maxi[mt];

int solve(int h)
{
    pre(h);
    int r1,r2,c1,c2,ret=0,r;
    for(r1=1; r1<=n; r1++)
        for(r2=r1; r2<=n; r2++)
        {
            r=r2-r1+1;
            rep1(c1,m)
            temp_cum[c1]=get_sum(r1,r2,c1);
            maxi[m]= {temp_cum[m],m};
            for(c1=m-1; c1>=1; c1--)
            {
                maxi[c1]=maxi[c1+1];
                if(temp_cum[c1] > maxi[c1].fs)
                    maxi[c1]= {temp_cum[c1],c1};
            }
            c1=c2=1;
            while(c1<=m)
            {
                c2=max(c1,c2);
                while(c2<=m && maxi[c2].fs - temp_cum[c1-1] >= 0)
                {
                    c2=maxi[c2].sc;
                    ret=max(ret,r*(c2-c1+1));
                    c2++;
                }
                c1++;
            }
        }
    return ret;
}

int main ()
{
    cffi;
    int q,h,i,j,test,t=1;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        rep1(i,n)
        rep1(j,m)
        cin>>arr[i][j];
        cout<<"Case "<<t++<<":"<<endl;
        cin>>q;
        while(q--)
        {
            cin>>h;
            deb(solve(h));
        }
    }

    return 0;
}










