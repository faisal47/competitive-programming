#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define ll long long
#define sz
using namespace std;
bool good,bad;
int dp[55][4][7],l;
string a;
//bool cons(char c)
//{
//    return c!='A' && c!='E' && c!='I' && c!='O' && c!= 'U';
//}
bool vowel(char c)
{
    return c=='A' || c=='E' || c=='I' || c=='O' || c== 'U';
}
int dekh(int pos,int vow,int con)
{
    if((con==5)|| (vow==3))
    {
        bad=1;
        return 1;
    }
    else if(l==pos)
    {
        good=1;
       return 1;
    }
    if(dp[pos][vow][con]!=-1)
    return dp[pos][vow][con];
    int i=0;
    if(a[pos]=='?')
    {
        i=dekh(pos+1,0,con+1);
        i=dekh(pos+1,vow+1,0);
    }
    else if(vowel(a[pos]))
    {
        i=dekh(pos+1,vow+1,0);
    }
    else
    {
        i=dekh(pos+1,0,con+1);
    }
    return dp[pos][vow][con]=i;
}
int main ()
{
    int test,t;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>a;
        good=bad=0;
        ms(dp,-1);
        l=a.size();
        dekh(0,0,0);
        printf("Case %d: ",t);
        if(good==1 && bad==1)
        cout<<"MIXED\n";
        else if(good==1)
        cout<<"GOOD\n";
        else
        cout<<"BAD\n";
    }
    return 0;
}
