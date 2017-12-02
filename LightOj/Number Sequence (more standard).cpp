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
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define sci1(a) scanf(" %d",&a)
#define ll long long
using namespace std;

int mod;

struct matrix
{
    ll x[3][3];
};
matrix base,zero,ans;

matrix matmult(matrix &a,matrix &b,int n)//m*n and n*r matrix  //1 based
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

matrix bigmod(matrix b,long long p,int n) //have to pass n
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

int main ()
{
    int test,t=1,a,b,n,m,yes;
    sci1(test);
    while(test--)
    {
        sci1(a);
        sci1(b);
        sci1(n);
        sci1(m);
        if(m==1)mod=10;
        else if(m==2)mod=100;
        else if(m==3)mod=1000;
        else mod=10000;

        base.x[1][1]=1;
        base.x[1][2]=1;
        base.x[2][1]=1;
        base.x[2][2]=0;

        printf("Case %d: ",t++);

        if(!n)
            {
                printf("%d\n",a%mod);
                continue;
            }
        else if(n==1)
            {
                printf("%d\n",b%mod);
                continue;
            }

        ans=bigmod(base,n-1,2);
        yes=(ans.x[1][1]*b)%mod;
        yes=(yes+((ans.x[1][2]*a)%mod))%mod;
        printf("%d\n",yes);
    }
    return 0;
}

