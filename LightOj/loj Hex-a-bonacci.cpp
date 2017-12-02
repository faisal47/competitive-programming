#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int dp[10020];
int a, b, c, d, e, f;
int fn(int n )
{
    if( n == 0 ) return a% 10000007;
    if( n == 1 ) return b% 10000007;
    if( n == 2 ) return c% 10000007;
    if( n == 3 ) return d% 10000007;
    if( n == 4 ) return e% 10000007;
    if( n == 5 ) return f% 10000007;
    if(dp[n]!=-1)
        return dp[n];
    else
    {
        dp[n]=(fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6)) % 10000007;
        return dp[n];
    }
}
int main()
{
    int n, caseno = 0, cases;
    cin>>cases;
    while( cases-- )
    {
        memset(dp,-1,sizeof(dp));
        cin>>a>>b>>c>>d>>e>>f>>n;
        printf("Case %d: %d\n", ++caseno, fn(n));
    }
    return 0;
}
