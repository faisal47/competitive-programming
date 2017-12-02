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
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define scll1(a) scanf(" %lld",&a)
#define sci1(a) scanf(" %d",&a)
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define mt
using namespace std;

struct matrix
{
    unsigned x[40][40];
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
                ret.x[i][j]=ret.x[i][j]+(a.x[i][k]*b.x[k][j]); //we can reduce complexity here
        }
    return ret;
}

matrix bigmod(matrix b,int p,int n) //have to pass n
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

vec_<pii>v;

bool check(int i,int j)
{
    return abs(v[i].fs-v[j].fs)>1 && abs(v[i].sc-v[j].sc)>1 && abs(v[i].fs-v[j].sc)>1 && abs(v[i].sc-v[j].fs)>1;
}

int main ()
{

    int i,j,test,t=1;
    unsigned int ans1;
    int n;

    for(i=1; i<=10; i++)
        for(j=i+2; j<=10; j++)
            v.pb(mp(i,j));

    for(i=0; i<36; i++)
        for(j=0; j<36; j++)
        {
            if(check(i,j))
                base.x[i+1][j+1]=1;
            else
                base.x[i+1][j+1]=0;
        }

    scll1(test);
    while(test--)
    {
        sci1(n);

        printf("Case %d: ",t++);

        if(n==1)
            printf("36\n");
        else
        {
            ans1=0;
            ans=bigmod(base,n-1,36);
            for(i=1; i<=36; i++)
                for(j=1; j<=36; j++)
                    ans1+=ans.x[i][j];
            printf("%u\n",ans1);
        }

    }
    return 0;
}

