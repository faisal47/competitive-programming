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
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define pri1(a) printf("%d ",a)
#define pri2(a,b) printf("%d %d ",a,b)
#define prll1(a) printf("%I64d ",a)
#define prll2(a,b) printf("%I64d %I64d ",a,b)
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define mt
using namespace std;
int x,y,n;

void jump(int x1,int y2,char &dik,int s)
{
    x=x1;
    y=y2;
    if(dik=='S')
    {
        x+=s;
        if(x>n)
        {
            x=n-(x-n);
            dik='N';
        }
    }
    else if(dik=='N')
    {
        x-=s;
        if(x<1)
        {
            x=1+(1-x);
            dik='S';
        }
    }
    else if(dik=='E')
    {
        y+=s;
        if(y>n)
        {
            y=n-(y-n);
            dik='W';
        }
    }
    else
    {
        y-=s;
        if(y<1)
        {
            y=1+(1-y);
            dik='E';
        }
    }
}

void change(char &dik)
{
    if(dik=='S')
    dik='E';
    else if(dik=='E')
    dik='N';
    else if(dik=='N')
    dik='W';
    else
    dik='S';
}

int main ()
{
    int t,x1,x2,y1,y2,t1,t2,s1,s2,i;
    char dik1,dik2;
    while(cin>>n && n)
    {
        cin>>dik1>>s1>>t1;
        cin>>dik2>>s2>>t2;
        cin>>t;
        x1=1;
        y1=1;

        x2=n;
        y2=n;

        for(i=1; i<=t; i++)
        {
            jump(x1,y1,dik1,s1);
            x1=x;
            y1=y;
            jump(x2,y2,dik2,s2);
            x2=x;
            y2=y;
            if(x1==x2 && y1==y2)
            {
                swap(dik1,dik2);
            }
            else
            {
                if(i%t1==0)
                {
                    change(dik1);
                }
                if(i%t2==0)
                {
                    change(dik2);
                }
            }
        }
        cout<<x1<<" "<<y1<<endl;
        cout<<x2<<" "<<y2<<endl;

    }
    return 0;
}


