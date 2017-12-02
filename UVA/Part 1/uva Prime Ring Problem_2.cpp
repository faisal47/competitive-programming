#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
#include <ctype.h>
using namespace std;
#define inf 1<<28
int prime[35],ins[25],ans[25],n,flag1[35];
void bt(int ansin)
{
    //cout<<"kjnhd"<<endl;
    if(ansin>n)
    {
        if(prime[ans[ansin-1]+1]!=1)
        return;
            cout<<ans[1];
            for(int i=2; i<ansin; i++)
                cout<<" "<<ans[i];
            cout<<endl;
        return;
    }
    for(int i=2; i<=n; i++)
    {
        if(prime[ans[ansin-1]+i]==1)
        {
            if(flag1[i]==0)
            {
                flag1[i]=1;
                ans[ansin]=i;
                bt(ansin+1);
                flag1[i]=0;
            }
        }
    }
}
int main ()
{
    prime[2]=1;
    int i,j;
    for(i=3; i<=35; i+=2)
        if(prime[i]==0)
        {
            prime[i]=1;
            for(j=i+i; j<=35; j+=i)
                prime[j]=2;
        }
    int test=0;
    n=20;
    for(i=1; i<=n; i++)
        ins[i]=i;
    ans[1]=1;
    while(cin>>n)
    {
        memset(flag1,0,sizeof(flag1));
        if(test++)
            cout<<endl;
        printf("Case %d:\n",test);
        bt(2);
    }
    return 0;
}

