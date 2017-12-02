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
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
#define sz
using namespace std;
int main ()
{
    ll i,j,count1,count2,count3,n;
    while(cin>>n)
    {
        count1=count2=count3=0;
        for(i=1; i<=n; i++)
        {
            cin>>j;
            if(i%3==1)
                count1+=j;
            else if(i%3==2)
                count2+=j;
            else
                count3+=j;
        }
        if(count1>count2 && count1> count3)
            cout<<"chest";
        else if(count2>count1 && count2>count3)
            cout<<"biceps";
        else
            cout<<"back";
        cout<<endl;
    }
    return 0;
}