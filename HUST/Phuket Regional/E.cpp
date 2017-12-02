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


#define mt 110
#define mod 1000000007

int nCr[51010][1010];

void calculate()
{
    int i, j;
    for(i=0; i<=50000; i++)
    {
        for(j=0; j<=min(i,1000); j++)
        {
            if(j == 0) nCr[i][j] = 1;
            else if(j == 1) nCr[i][j] = i;
            else nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1]) % mod;
        }
    }
}

int dp[110][1010];
int visit[110][1010],t,n,k,arr[50010],mot;
int cnt[mt],cumcnt[mt];

int solve(int ind,int morse)
{
    if(morse > k)
        return 0;
    if(morse == k)
        return 1;
    if(ind > mot)
        return 0;
    int &ret=dp[ind][morse];
    int &ret2=visit[ind][morse];
    if(ret2 == t)
        return ret;
    ret=0;
    ret2=t;
    ll temp=0;
    int x,y;
    int jento_ache=cumcnt[ind-1];
    rep(i,cnt[ind]+1)
    {
        if(i>k)
        break;
        x=max(jento_ache-1,i);
        y=min(jento_ache-1,i);
        temp+=(ll)(solve(ind+1,morse+i)*(ll)nCr[x+y][y]);
        if(temp >=mod)
            temp%=mod;
    }
    ret=temp;
    return ret;
}

int main ()
{
    calculate();
    int i,j,test;
    scanf("%d",&test);
    while(test--)
    {
        mot=0;
        t++;
        rep1(i,100)
        cnt[i]=0;

        scanf("%d %d",&n,&k);
        rep1(i,n)
        scanf("%d",&arr[i]);

        sort(arr+1,arr+1+n);
        rep1(i,n)
        {
            if(arr[i]>arr[i-1])
                mot++;
            cnt[mot]++;
        }
        rep1(i,mot)
        cumcnt[i]=(cnt[i]+cumcnt[i-1]);
        printf("Case %d: %d\n",t,solve(2,0));
    }


    return 0;
}










