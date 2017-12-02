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
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define ll long long
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;

ll dp[12][(1<<11)+3];

int r,c;

bool vc(int ar,int ac,int mask)
{
    return ar>=0 && ar<r && ac>=0 && ac<c && !(mask & (1 << ac));
}

ll rec(int,int);

ll cbc(int ar,int ac,int c_mask,int n_mask)
{
    if(ac == c)
        return rec(ar+1,n_mask);

    if(!vc(ar,ac,c_mask))
        return cbc(ar,ac+1,c_mask,n_mask);

    else
    {
        ll ret=0;
        c_mask|=1<<ac;

        if(vc(ar+1,ac,n_mask))
            ret+=cbc(ar,ac+1,c_mask,n_mask|(1 << ac));

        if(vc(ar,ac+1,c_mask))
            ret+=cbc(ar,ac+2,c_mask|(1 << (ac+1)),n_mask);

        return ret;
    }
}

ll rec(int ar,int c_mask)
{
    if(ar == r)
    {
        if(!c_mask)return 1;
        return 0;
    }

    ll &ret=dp[ar][c_mask];
    if(ret!=-1)return ret;
    return ret=cbc(ar,0,c_mask,0);
}

int main ()
{
    while(sci2(r,c)==2 && (r|c))
    {
        ms(dp,-1);
        printf("%I64d\n",rec(0,0));
    }
    return 0;
}

