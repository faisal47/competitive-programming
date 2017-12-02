#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define scll2(a,b) scanf("%lld %lld",&a,&b)
using namespace std;
typedef long long ll;
ll L,S,dp[30][30][360];
ll maan_de(ll ase,ll bortoman,ll mot)
{
    if(ase>L)return 0;
    if(ase==L && mot==S)return 1;
    ll i,&ret=dp[ase][bortoman][mot];
    if(ret!=-1)return ret;
    ret=0;
    for(i=bortoman+1;i<=26;i++)
    ret+=maan_de(ase+1,i,mot+i);
    return ret;
}
int main ()
{
    ll t=1;
    while(scll2(L,S)==2)
    {
        if(L==0 && S==0)break;
        ms(dp,-1);
        printf("Case %lld: %lld\n",t++,maan_de(0,0,0));
    }
    return 0;
}

