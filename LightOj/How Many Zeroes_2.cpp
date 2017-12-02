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

#define mt
#define mod

int arr[15];
ll dp[15][10][2][2];

void pre(ll num)
{
    int c=0;
    ms(arr,0);
    ms(dp,-1ll);
    while(num > 0)
    {
        arr[c]=num%10;
        num/=10;
        c++;
    }
}

ll solve(int ind,int num,bool flag1,bool flag2)
{
    if(ind < 0)
        return 0ll;
    ll &ret=dp[ind][num][flag1][flag2];
    if(ret != -1ll)
        return ret;
    ret=0ll;
    int i;
    bool nf;
    if(flag1)
    {
        for(i=0;i<=9;i++)
        {
            if(i==0 && flag2)
            ret+=(1+solve(ind-1,i,flag1,flag2));
            else if(i==0)
            ret+=solve(ind-1,i,flag1,flag2);
            else
            ret+=solve(ind-1,i,flag1,1);
        }
    }
    else
    {
        for(i=0;i<=arr[ind];i++)
        {
            if(i==arr[ind])
                nf=0;
            else
                nf=1;

            if(i==0 && flag2)
            ret+=(1+solve(ind-1,i,nf,flag2));
            else if(i==0)
            ret+=solve(ind-1,i,nf,flag2);
            else
            ret+=solve(ind-1,i,nf,1);
        }
    }

    return ret;
}

int main ()
{
    cffi;
    int i,j,test,t=1;
    ll a,b,ans;

    cin>>test;
    while(test--)
    {
        cin>>a>>b;
        pre(b);
        ans=solve(14,0,0,0)+1ll;
        a--;
        if(a>=0)
            {
                pre(a);
                ans-=(1ll+solve(14,0,0,0));
            }
        cout<<"Case "<<t++<<": ";
        deb(ans);
    }

    return 0;
}


