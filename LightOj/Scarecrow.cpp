#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <stack>
#include <utility>
#include <queue>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sci1(a) scanf("%d",&a)
#define scch(a) scanf("%c",&a)
using namespace std;
int main ()
{
    int i,test,t=1,c,n,ans;
    char z,arr[101];
    sci1(test);
    while(test--)
    {
        c=ans=0;
        sci1(n);
        scch(z);
        gets(arr);
        for(i=0; i<n; i++)
        {
            if((arr[i]=='#' && c>0) || (i==n-1 && (c>0 || arr[i]=='.')))
            {
                if(arr[i]=='.')
                c++;
                ans+=c/3;
                c%=3;
                if(c==1 && arr[i+1]!='#' && (i+1)<n)
                {
                    ans++;
                    i++;
                }
                else if(c>0)
                    ans++;
                c=0;
            }
            else if(arr[i]=='.')
                c++;
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

