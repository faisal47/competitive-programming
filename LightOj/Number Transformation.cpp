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
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sz(a) a.size()
#define mt 1010
using namespace std;
int dist[mt],s,t,flag[mt],i,v,flag1[mt],j;
vec_<int>primes;
bool bfs()
{
    queue<int>q;
    dist[s]=0;
    q.push(s);
    flag1[s]=1;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        if(flag[s]==1)continue;
        for(i=0;i<sz(primes) && primes[i]<s;i++)
        {
            if(s%primes[i]==0)
            {
                v=s+primes[i];
                if(v<=t && !flag1[v])
                {
                    flag1[v]=1;
                    dist[v]=dist[s]+1;
                    q.push(v);
                    if(v==t)return true;
                }
            }
        }
    }
    return false;
}
int main ()
{
    int test,t1=1,s1;
    flag[2]=1;
    primes.pb(2);
    for(i=3; i<mt; i+=2)
    {
        if(!flag[i])
        {
            primes.pb(i);
            flag[i]=1;
            for(j=i+i; j<mt; j+=i)
                flag[j]=3;
        }
    }
    sci1(test);
    while(test--)
    {
        sci2(s,t);
        ms(flag1,0);
        printf("Case %d: ",t1++);
        if(s==t)cout<<"0\n";
        else if(s>t || flag[s]==1 || !bfs())cout<<"-1\n";
        else printf("%d\n",dist[t]);
    }
    return 0;
}

