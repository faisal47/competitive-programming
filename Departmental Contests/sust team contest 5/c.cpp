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
#define inf 1<<28
#define sort_n(a) sort(a.begin(),a.end())
#define sci1(a) scanf(" %d",&a)
using namespace std;
string st;
int a,b,c,d,i,j,k;
int maan(int x,int y,int sign)
{
    if(sign==1)return x+y;
    else if(sign==2)return x-y;
    else if(sign==3)return x*y;
    else
    {
        if(y==0)return inf;
        else
            return x/y;
    }
}
bool check()
{
    sort_n(st);
    do
    {
        a=st[0]-'0';
        b=st[1]-'0';
        c=st[2]-'0';
        d=st[3]-'0';
        for(i=1; i<=4; i++)
            for(j=1; j<=4; j++)
                for(k=1; k<=4; k++)
                    if(maan(a,maan(b,maan(c,d,k),j),i)==10 || maan(a,maan(maan(b,c,j),d,k),i)==10 || maan(maan(a,b,i),maan(c,d,k),j)==10 || maan(maan(maan(a,b,i),c,j),d,k)==10 || maan(maan(a,maan(b,c,j),i),d,k)==10)return 1;
    }
    while(next_permutation(st.begin(),st.end()));
    return 0;
}
int main ()
{
    int i,j,n;
    bool flag;
    while(sci1(n)==1 && n)
    {
        flag=1;
        while(n--)
        {
            cin>>st;
            if(flag)
            {
                if(!check())flag=0;
            }
        }
        if(flag)
        cout<<"TRUE\n";
        else
        cout<<"BUSTED\n";
    }
    return 0;
}

