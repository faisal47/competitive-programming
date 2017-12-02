#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <queue>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define ll long long
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define eps 1E-7
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz
using namespace std;
//struct data //for dj()
//{
//   int node,cost;
//   bool operator < (const data& p) const
//   {
//       return cost > p.cost;
//   }
//};
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
//ll gcd(ll a,ll b)
//{
//   if(b==0)
//   return a;
//   return gcd(b,a%b);
//}
int main ()
{
    //cout<<(int)'a'<<endl;
    int i,j,test,t,len,count1[200],count2[200];
    bool flag1=0,flag2=0;
    char arr1[110],arr2[110],c;
    scanf("%d",&test);
    scanf("%c",&c);
    for(t=1;t<=test;t++)
    {
        flag1=flag2=0;
        gets(arr1);
        gets(arr2);
        ms(count1,0);
        ms(count2,0);
        len=strlen(arr1);
        for(i=0;i<len;i++)
        {
            arr1[i]=tolower(arr1[i]);
            if(arr1[i]>='a' && arr1[i]<='z')
            count1[arr1[i]]++;
        }
        len=strlen(arr2);
        for(i=0;i<len;i++)
        {
            arr2[i]=tolower(arr2[i]);
            if(arr2[i]>='a' && arr2[i]<='z')
            count2[arr2[i]]++;
        }
        for(i='a';i<='z';i++)
        {
            if(count1[i]>count2[i])
            {
                flag1=1;
            }
            else if(count1[i]<count2[i])
            {
                flag2=1;
            }
        }
        printf("Case %d: ",t);
        if(flag1==0 || flag2==0)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}

