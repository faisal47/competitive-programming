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
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define repa(i,n) for(auto i: n)
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

#define fop freopen("inputCL.txt","r",stdin);freopen("outputCL.txt","w",stdout);

#define mt 105
#define mod

string arr[mt];

int n,m,k;
int cum[mt][mt],maxD[mt][mt];

bool ok1(int c,int cnt)
{
    return c+cnt<=m && c-cnt-1>=0;
}

int find_max_depth(int r,int c)
{
    if(arr[r][c] != '#')
        return 0;
    int ret=1,cnt=1;
    r++;
    int lagbe=3;
    while(r <= n)
    {
        if(!ok1(c,cnt) || cum[r][c+cnt]-cum[r][c-cnt-1]!=lagbe)
            break;
        ret++;
        cnt++;
        lagbe+=2;
        r++;
    }
    return ret;
}

int dp[mt][mt][mt];

int calc(int mot)
{
    int ret=2+(mot-1)*2;
    ret*=mot;
//    deb(mot,ret/2);
    return ret/2;
}

int solve(int r,int nisi,int pre)
{
//    deb("hula");
    if(nisi ==k)
        return 0;
    if(r>n)
        return -inf;
    int &ret=dp[r][nisi][pre];
    if(ret != -1)
        return ret;
    ret=-inf;
    int j,l;
    if(pre==0)
    {
        rep1(j,m)
        rep1(l,maxD[r][j])
        ret=max(ret,solve(r+l,1,r)+calc(l));

    }
    else
    {
        int d=r-pre;
        int lf=max(r-d+1,1);
        int rg=min(r+d-1,m);
        for(j=lf; j<=rg; j++)
            rep1(l,maxD[r][j])
            ret=max(ret,solve(r+l,nisi+1,r)+calc(l));
    }
    return ret;
}

int main ()
{
    fop;
//    cffi;
    int i,j,test,t=1,ans,l;
    cin>>test;
    while(test--)
    {
        cin>>n>>m>>k;
        rep1(i,n)
        {
            cin>>arr[i];
            arr[i]=" "+arr[i];
        }
//        rep1(i,n)
//        deb(arr[i]);
        ms(cum,0);
        rep1(i,n)
        rep1(j,m)
        {
            if(arr[i][j]=='#')
                cum[i][j]++;
            cum[i][j]+=cum[i][j-1];
        }
        rep1(i,n)
        rep1(j,m)
        {
            maxD[i][j]=find_max_depth(i,j);
//            deb(i,j,maxD[i][j]);
        }
        ms(dp,-1);
        ans=0;
        rep1(i,n)
        rep1(j,m)
        if(arr[i][j]=='#')
        {
            ans=max(ans,solve(i,0,0));
            break;
        }
        printf("Case #%d: %d\n",t++,ans);
    }
    return 0;
}









