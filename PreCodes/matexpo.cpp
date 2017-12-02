#include <bits/stdc++.h>
using namespace std;
#define mod         1000000007
#define ll long long

struct matrix{
     ll x[6][6];
};
matrix base,zero,ans;

matrix matmult(matrix &a,matrix &b,int n)//m*n and n*r matrix  //1 based
{
    matrix ret;
    int i,j,k;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        ret.x[i][j]=0;
        for(k=1;k<=n;k++)
            ret.x[i][j]=ret.x[i][j]+(a.x[i][k]*b.x[k][j])%mod; //we can reduce complexity here
        ret.x[i][j]%=mod;
    }
    return ret;
}

matrix bigmod(matrix b,long long p,int n) //have to pass n
{
    matrix xx=zero;
    int i;
    for(i=1;i<=n;i++) xx.x[i][i]=1;
    matrix power=b;
    while(p)
    {
        if((p&1)==1) xx=matmult(xx,power,n);
        power=matmult(power,power,n);
        p/=2;
    }
    return xx;
}


int main()
{
    int t,cas=0,p;
    cin>>t;
    int k;
    long long n;
    while(t--)
    {
        cin>>n>>k;
        printf("Case %d: ",++cas);
        base.x[1][1]=1;
        base.x[1][4]=2;
        base.x[4][1]=3;
        if(n<=1)
        {
            cout<<n;
            continue;
        }
        matrix ans=bigmod(base,p,n); //n-number of baseconditions+1
        cout<<ans.x[1][1];
    }
    return 0;
}
