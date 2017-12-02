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
#define scch(a) scanf(" %c",&a)
#define scull1(a) scanf(" %ulld",&a)
#define sci1(a) scanf(" %d",&a)
#define ull unsigned long long
using namespace std;

ull dp[102][1<<8];
int vp[102][1<<8];
int t,r,c;
char arr[102][9];


bool vc(int ar,int ac,int mask)
{
    return ar>=0 && ar<r && ac>=0 && ac<c && arr[ar][ac]=='.' && !(mask & (1 << ac));
}

ull rec(int,int);

ull cbc(int ar,int ac,int c_mask,int n_mask)
{
    if(ac == c)
    return rec(ar+1,n_mask);

    if(!vc(ar,ac,c_mask))
    return cbc(ar,ac+1,c_mask,n_mask);

    else
    {
        ull ret=0;
        c_mask|=1<<ac;

        if(vc(ar+1,ac,n_mask))
        ret+=cbc(ar,ac+1,c_mask,n_mask|(1 << ac));

        if(vc(ar,ac+1,c_mask))
        ret+=cbc(ar,ac+2,c_mask|(1 << (ac+1)),n_mask);

        if(vc(ar+1,ac,n_mask) && vc(ar+1,ac+1,n_mask))
        ret+=cbc(ar,ac+1,c_mask,n_mask|(1 << (ac+1))| (1<<ac));

        if(vc(ar+1,ac,n_mask) && vc(ar,ac+1,c_mask))
        ret+=cbc(ar,ac+2,c_mask|(1 << (ac+1)),n_mask|(1 << ac));

        if(vc(ar+1,ac,n_mask) && vc(ar+1,ac-1,n_mask))
        ret+=cbc(ar,ac+1,c_mask,n_mask|(1<<ac)|(1<<(ac-1)));

        if(vc(ar,ac+1,c_mask) && vc(ar+1,ac+1,n_mask))
        ret+=cbc(ar,ac+2,c_mask|(1<<(ac+1)),n_mask|(1<<(ac+1)));

        return ret;
    }
}

ull rec(int ar,int c_mask)
{
    if(ar == r)
    {
        if(!c_mask)return 1;
        return 0;
    }

    ull &ret=dp[ar][c_mask];
    if(vp[ar][c_mask]==t)return ret;
    vp[ar][c_mask]=t;
    return ret=cbc(ar,0,c_mask,0);
}

int main ()
{
    int test,i,j;
    sci1(test);
    for(t=1;t<=test;t++)
    {
        sci1(r);
        sci1(c);
        if(r>=c)
        {
            for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            scch(arr[i][j]);
        }
        else
        {
            for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            scch(arr[j][i]);
            swap(r,c);
        }
        printf("Case %d: %llu\n",t,rec(0,0));
    }
    return 0;
}
