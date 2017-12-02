#include <stdio.h>

typedef long long ll;
using namespace std;

const ll mod=1LL<<32;

struct matrix
{
    ll x[53][53];
};

matrix base,zero,ans;

matrix matmult(matrix &a,matrix &b,ll n)//m*n and n*r matrix  //1 based
{
    matrix ret;
    int i,j,k;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            ret.x[i][j]=0;
            for(k=1; k<=n; k++)
                ret.x[i][j]=ret.x[i][j]+(a.x[i][k]*b.x[k][j])%mod; //we can reduce complexity here
            ret.x[i][j]%=mod;
        }
    return ret;
}

matrix bigmod(matrix b,long long p,ll n) //have to pass n
{
    matrix xx=zero;
    int i;
    for(i=1; i<=n; i++) xx.x[i][i]=1;
    matrix power=b;
    while(p)
    {
        if((p&1)==1) xx=matmult(xx,power,n);
        power=matmult(power,power,n);
        p/=2;
    }
    return xx;
}

ll dp[51][51];

int main ()
{
    ll n;

    ll test,t=1,i,j,k1,k,l;
    ll ans1;
    k1=51;
    for(i=0; i<k1; i++)
    {
        for(j=0; j<=i; j++)
        {
            if(j == 0) dp[i][j] = 1;
            else if(j == 1) dp[i][j] = i;
            else dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }

    scanf("%lld",&test);

    while(test--)
    {
       scanf("%lld %lld",&n,&k);

        k1=k+2;
        base = zero;
        base.x[1][1] = 1;

        j = 0;
        for(i=2; i<=k1; i++) base.x[1][i] = dp[k][j++];
        for(i=2; i<=k1; i++)
        {
            l = 0;
            for(j=i; j<=k1; j++) base.x[i][j] = dp[k-i+2][l++];
        }

        ans=bigmod(base,n-1,k1);

        ans1=0;
        for(i=1; i<=k1; i++)
            ans1=(ans1+ans.x[1][i])%mod;

        printf("Case %lld: %lld\n",t++,ans1);
    }

    return 0;
}

