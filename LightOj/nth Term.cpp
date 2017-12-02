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

int mod = 10007;

struct matrix
{
    ll x[5][5];
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
    int test,t=1,a,b,n,m,yes,c;
    sci1(test);
    while(test--)
    {
        sci1(n);
        sci1(a);
        sci1(b);
        sci1(c);

        base.x[1][1]=a;
        base.x[1][2]=0;
        base.x[1][3]=b;
        base.x[1][4]=1;
        base.x[2][1]=1;
        base.x[2][2]=0;
        base.x[2][3]=0;
        base.x[2][4]=0;
        base.x[3][1]=0;
        base.x[3][2]=1;
        base.x[3][3]=0;
        base.x[3][4]=0;
        base.x[4][1]=0;
        base.x[4][2]=0;
        base.x[4][3]=0;
        base.x[4][4]=1;

        printf("Case %d: ",t++);

        if(n<3)
            {
                printf("0\n");
                continue;
            }

        ans=bigmod(base,n-2,4);
        yes=(ans.x[1][4]*c)%mod;
        printf("%d\n",yes);
    }
    return 0;
}


