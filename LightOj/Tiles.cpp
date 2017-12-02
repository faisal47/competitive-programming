#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <utility>
#define scll1(a) scanf(" %lld",&a)
#define sz(a) a.size()
#define ll long long
using namespace std;

const ll mod=10007;

struct matrix{
     ll x[5][5];
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

int main ()
{
    ll i,j,test,t=1,ans1,n;
    scll1(test);
    for(i=1;i<=4;i++)
    base.x[1][i]=1;
    for(i=1;i<=4;i++)
    if(i==1)
    base.x[2][i]=1;
    else
    base.x[2][i]=0;
    base.x[3][1]=0;
    base.x[3][2]=1;
    base.x[3][3]=0;
    base.x[3][4]=1;

    base.x[4][1]=0;
    base.x[4][2]=1;
    base.x[4][3]=1;
    base.x[4][4]=0;

    while(test--)
    {
        scll1(n);
        printf("Case %d: ",t++);
        if(n==1)
        cout<<1;
        else if(n==2)
        cout<<2;
        else
        {
            ans1=0;
            ans=bigmod(base,n-2,4);
            ans1=(2*ans.x[1][1])%mod;
            ans1=(ans1+ans.x[1][2])%mod;
            ans1=(ans1+ans.x[1][3])%mod;
            ans1=(ans1+ans.x[1][4])%mod;
            cout<<ans1;
        }
        cout<<endl;
    }
    return 0;
}


