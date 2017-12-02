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
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#include <utility>
#define sci1(a) scanf(" %d",&a)
#define mt 55
using namespace std;
vec_<int>v1,v2;
int main ()
{
    bool col1[mt],col2[mt];
    int n,i,test,t=1,ans,j;
    sci1(test);
    while(test--)
    {
        sci1(n);
        ans=0;
        clr(v1);
        clr(v2);
        for(i=0; i<n; i++)
        {
            col1[i]=0;
            sci1(j);
            v1.pb(j);
        }

        for(i=0; i<n; i++)
        {
            col2[i]=0;
            sci1(j);
            v2.pb(j);
        }

        sort(v1.begin(),v1.end());
        sort(v2.rbegin(),v2.rend());
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                if(!col2[j] && v1[i]>v2[j])
                {
                    ans+=2;
                    col1[i]=col2[j]=1;
                    break;
                }
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(!col2[j] && v1[i]==v2[j] && !col1[i])
        {
            ans++;
            col2[j]=1;
            break;
        }

        printf("Case %d: %d\n",t++,ans);
    }

    return 0;
}

