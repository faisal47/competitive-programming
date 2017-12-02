
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
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf("%c",&a)
#define sci1(a) scanf(" %d%c",&a,&z)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define deb1(a) cout<<a<<endl;
#define deb2(a,b) cout<<a<<" "<<b<<endl
#define deb3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

///***************************************************** ekhon kamer kam ********************************************************************///

#define mt 50000

int par[mt];

int find_parent(int s)
{
    if(par[s]==s)
        return s;

    return par[s]=find_parent(par[s]);
}

void make_set(int a,int b)
{
    a=find_parent(a);
    b=find_parent(b);
    if(a==b)
        return;
    par[a]=b;
}

int main ()
{
    int n,a,b,c1,c2,t=0,test,i;
    char com,arr[500],z;

    scanf(" %d",&test);

    test--;

    while(test--)
    {
        c1=c2=0;

        if(t++)
            printf("\n");
        scanf(" %d%c",&n,&z);


        for(i=1; i<=n; i++)
            par[i]=i;
        while(gets(arr))
        {
            if(strlen(arr)==0)
                break;
            int len=strlen(arr),flag=0;
            a=b=0;
            for(i=2; i<len; i++)
            {
                if(arr[i]==' ')
                    flag=1;
                else if(flag==0)
                    a=(a*10)+arr[i]-'0';
                else
                    b=(b*10)+arr[i]-'0';
            }

            com=arr[0];
            if(com=='q')
            {
                a=find_parent(a);
                b=find_parent(b);
                if(a==b)
                    c1++;
                else
                    c2++;
            }
            else
                make_set(a,b);
        }
        printf("%d,%d\n",c1,c2);
    }

    c1=c2=0;
    if(t++)
        printf("\n");
    scanf(" %d%c",&n,&z);

    //deb1(n);

    for(i=1; i<=n; i++)
        par[i]=i;

    while(gets(arr))
    {
        if(strlen(arr)==0)
            break;
        a=b=0;
        int len=strlen(arr),flag=0;
        for(i=2; i<len; i++)
        {
            if(arr[i]==' ')
                flag=1;
            else if(flag==0)
                a=(a*10)+arr[i]-'0';
            else
                b=(b*10)+arr[i]-'0';
        }
        com=arr[0];
        if(com=='q')
        {
            a=find_parent(a);
            b=find_parent(b);
            if(a==b)
                c1++;
            else
                c2++;
        }
        else
            make_set(a,b);
    }
    printf("%d,%d\n",c1,c2);

    return 0;
}

