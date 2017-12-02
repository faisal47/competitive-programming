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
#define sci1(a) scanf(" %d",&a)
#define sz(a) a.size()
#define mt 100010
using namespace std;
int arr[mt];
int main ()
{
    int n,i,test,t=1,pre,j,k,a,ans;
    bool flag;
    sci1(test);
    while(test--)
    {
        flag=0;
        sci1(n);
        pre=0;
        k=-1;
        for(i=1; i<=n; i++)
        {
            sci1(j);
            a=j;
            j-=pre;
            pre=a;
            arr[i]=j;
            k=max(k,j);
        }
        ans=k+1;
        for(i=1; i<=n; i++)
        {

            if(arr[i]>k || k<0)
            {
                flag=1;
                break;
            }
            else if(arr[i]==k)
                k--;

        }
        printf("Case %d: ",t++);
        if(flag)
            cout<<ans<<endl;
        else
            cout<<ans-1<<endl;

    }
    return 0;
}
