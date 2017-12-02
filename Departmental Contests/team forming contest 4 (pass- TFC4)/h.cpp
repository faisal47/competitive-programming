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
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define sort_n(a) sort(a.begin(),a.end())
#define scll1(a) scanf("%lld",&a)
#define sz(a) a.size()
#define mt
using namespace std;
typedef long long ll;
int main ()
{
    ll i,n,t=1,pre,ase,j;
    vec_<ll>v;
    string s1,s2,temps;
    ll a,b;
    bool flag;
    while(scll1(n)==1 && n)
    {
        ase=0;
        pre=-1;
        clr(v);
        flag=0;
        while(n--)
        {
            scll1(i);
            if(pre==-1)
            {
                v.pb(i);pre=i;
            }
            else if(i-pre==1)
            {
                ase++;
                pre=i;
            }
            else
            {
                if(ase)
                {
                    v.pb(-ase);
                    ase=0;
                }
                v.pb(i);
                pre=i;
                flag=0;
            }
        }
        if(ase)
        v.pb(-ase);
        printf("Case %d:\n",t++);
        for(i=0;i<sz(v);i++)
        {
            if(i+1<sz(v) && v[i+1]>0)
                cout<<0<<v[i]<<endl;
            else if(i+1<sz(v) && v[i+1]<0)
            {
                a=v[i];
                b=v[i]-v[i+1];
                clr(s1);
                clr(s2);
                i++;
                clr(temps);
                while(1)
                {
                    if(!a)break;
                    s1+=(a%10)+'0';
                    a/=10;
                }
                while(1)
                {
                    if(!b)break;
                    s2+=(b%10)+'0';
                    b/=10;
                }
                for(j=sz(s1)-1;j>-1;j--)
                temps+=s1[j];
                s1=temps;
                clr(temps);
                for(j=sz(s2)-1;j>-1;j--)
                temps+=s2[j];
                s2=temps;
                cout<<0;
                cout<<s1<<"-";
                flag=0;
                for(j=0;j<sz(s2);j++)
                {
                    if(s1[j]!=s2[j] && !flag)
                    {
                        flag=1;
                        j--;
                    }
                    else if(flag)
                    cout<<s2[j];
                }
                cout<<endl;
            }
            else if(i==sz(v)-1)
            cout<<0<<v[i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}

