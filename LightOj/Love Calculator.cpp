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
#define sci1(a) scanf(" %d",&a)
#define sz(a) a.size()
#define ll long long
#define mt 35
using namespace std;

int dp1[mt][mt],len1,len2;
ll dp2[mt][mt];
char a[mt],b[mt];

int solve1(int i,int j)
{
    if(i==len1)return len2-j;
    if(j==len2)return len1-i;

    int &ret=dp1[i][j];
    if(ret!=-1)return ret;

    if(a[i]==b[j])
    return ret=1+solve1(i+1,j+1);

    return ret=1+min(solve1(i+1,j),solve1(i,j+1));
}

ll solve2(int i,int j)
{
    if(i==len1 || j==len2)return 1;

    ll &ret=dp2[i][j];

    if(ret!=-1)return ret;

    if(a[i]==b[j])
    return ret=solve2(i+1,j+1);

    int a=solve1(i+1,j);
    int b=solve1(i,j+1);

    if(a==b)
    ret=solve2(i+1,j)+solve2(i,j+1);
    else if(a<b)
    ret=solve2(i+1,j);
    else
    ret=solve2(i,j+1);

    return ret;
}

int main ()
{
    int test,t=1,i,j;
    sci1(test);
    gets(a);
    while(test--)
    {
        gets(a);
        gets(b);

        len1=strlen(a);
        len2=strlen(b);

        ms(dp1,-1);
        ms(dp2,-1);

        printf("Case %d: %d %lld\n",t++,solve1(0,0),solve2(0,0));
    }
    return 0;
}

