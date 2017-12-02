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
#define sci1(a) scanf(" %d",&a)
#define ll long long
using namespace std;

int mod;

struct matrix
{
    ll x[7][7];
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
    int test,t=1,q,n,yes1,yes2,f0,f1,f2,g0,g1,g2;
    sci1(test);
    base.x[1][3]=0;
    base.x[1][4]=0;
    base.x[1][5]=0;

    base.x[2][1]=1;
    base.x[2][2]=0;
    base.x[2][3]=0;
    base.x[2][4]=0;
    base.x[2][5]=0;
    base.x[2][6]=0;

    base.x[3][1]=0;
    base.x[3][2]=1;
    base.x[3][3]=0;
    base.x[3][4]=0;
    base.x[3][5]=0;
    base.x[3][6]=0;

    base.x[4][1]=0;
    base.x[4][2]=0;
    base.x[4][6]=0;

    base.x[5][1]=0;
    base.x[5][2]=0;
    base.x[5][3]=0;
    base.x[5][4]=1;
    base.x[5][5]=0;
    base.x[5][6]=0;

    base.x[6][1]=0;
    base.x[6][2]=0;
    base.x[6][3]=0;
    base.x[6][4]=0;
    base.x[6][5]=1;
    base.x[6][6]=0;
    while(test--)
    {
        sci1(base.x[1][1]);
        sci1(base.x[1][2]);
        sci1(base.x[1][6]);
        sci1(base.x[4][4]);
        sci1(base.x[4][5]);
        sci1(base.x[4][3]);
        sci1(f0);
        sci1(f1);
        sci1(f2);
        sci1(g0);
        sci1(g1);
        sci1(g2);
        sci1(mod);
        sci1(q);
        printf("Case %d:\n",t++);
        while(q--)
        {
            sci1(n);
            if(n==0)
            {
                yes1=f0%mod;
                yes2=g0%mod;
            }
            else if(n==1)
            {
                yes1=f1%mod;
                yes2=g1%mod;
            }
            else if(n==2)
            {
                yes1=f2%mod;
                yes2=g2%mod;
            }
            else
            {
                ans=bigmod(base,n-2,6);
                yes1=(ans.x[1][1]*f2)%mod;
                yes1=(yes1+((ans.x[1][2]*f1)%mod))%mod;
                yes1=(yes1+((ans.x[1][3]*f0)%mod))%mod;
                yes1=(yes1+((ans.x[1][4]*g2)%mod))%mod;
                yes1=(yes1+((ans.x[1][5]*g1)%mod))%mod;
                yes1=(yes1+((ans.x[1][6]*g0)%mod))%mod;
                yes2=(ans.x[4][1]*f2)%mod;
                yes2=(yes2+((ans.x[4][2]*f1)%mod))%mod;
                yes2=(yes2+((ans.x[4][3]*f0)%mod))%mod;
                yes2=(yes2+((ans.x[4][4]*g2)%mod))%mod;
                yes2=(yes2+((ans.x[4][5]*g1)%mod))%mod;
                yes2=(yes2+((ans.x[4][6]*g0)%mod))%mod;
            }

            printf("%d %d\n",yes1,yes2);
        }
    }
    return 0;
}

