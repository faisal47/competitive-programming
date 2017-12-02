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
#define scull1(a) scanf(" %llu",&a)
#define sci1(a) scanf(" %d",&a)
#define ull unsigned long long
#define ll long long
using namespace std;
struct matrix{
     ull x[3][3];
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
            ret.x[i][j]=ret.x[i][j]+(a.x[i][k]*b.x[k][j]); //we can reduce complexity here
    }
    return ret;
}

matrix bigmod(matrix b,unsigned long long p,int n) //have to pass n
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
    int test,t=1;
    ull p,q;
    int n;
    sci1(test);
    base.x[2][1]=1;
    base.x[2][2]=0;
    while(test--)
    {
        scull1(p);
        scull1(q);
        sci1(n);
        printf("Case %d: ",t++);
        if(n==0)
            cout<<2<<endl;
        else if(n==1)
            printf("%llu\n",p);
        else
        {
            base.x[1][1]=p;
            base.x[1][2]=-q;
            ans=bigmod(base,n-1,2);
            printf("%llu\n",(ans.x[1][1]*p)+(ans.x[1][2]*2));
        }
    }
    return 0;
}

