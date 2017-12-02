#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define clr(a) a.clear()
#define pb push_back
#define pob pop_back
#define vec_ vector
#define eps 1E-7
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf("%c",&a)
#define scll1(a) scanf("%lld",&a)
#define scll2(a,b) scanf("%lld %lld",&a,&b)
#define scll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scd1(a) scanf("%lf",&a)
#define scd2(a,b) scanf("%lf %lf",&a,&b)
#define scd3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define mp make_pair
#define sz(a) a.size()
#define matra
using namespace std;
int p,dp[75][75],maxi;
int maan_de(int t,int n)
{
    if(t<0)
    return 0;
    if(dp[t][n]!=-1)
    return dp[t][n];
   // cout<<t<<" "<<n<<endl;
    if(n==0 && t==0)
    {
        //cout<<"t==  "<<t<<endl;
//        return dp[t][n]=1;
return 1;
    }
    else if(n==0)
    return 0;
    int ret=0,i;
    for(i=p;i<=maxi;i++)
    ret+=maan_de(t-i,n-1);
    //cout<<t<<" "<<n<<endl;
    return dp[t][n]=ret;
}
int main ()
{
    int test,n,t;
    sci1(test);
    while(test--)
    {
        sci3(n,t,p);
        ms(dp,-1);
        maxi=p+t-n*p;
        printf("%d\n",maan_de(t,n));
    }
    return 0;
}

