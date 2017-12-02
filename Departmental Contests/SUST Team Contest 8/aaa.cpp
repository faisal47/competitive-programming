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
#define mt 15
using namespace std;

int flag[15],n;
int arr[15][3];

int bt(int pre,int d,int p)
{
    int ans=0;
    for(int i=0; i<n; i++)
    {
        if(!flag[i])
        {
            if(arr[i][0]<=d && arr[i][1]<=p)
            {
                flag[i]=1;
                ans=max(ans,1+bt(i,arr[i][0],arr[i][1]));
                flag[i]=0;
            }

            if(arr[i][1]<=d && arr[i][2]<=p)
            {
                flag[i]=1;
                ans=max(ans,1+bt(i,arr[i][1],arr[i][2]));
                flag[i]=0;
            }

            if(arr[i][0]<=d && arr[i][2]<=p)
            {
                flag[i]=1;
                ans=max(ans,1+bt(i,arr[i][0],arr[i][2]));
                flag[i]=0;
            }
        }
    }
    return ans;
}

int main ()
{

    int i,kase=1;

    while(sci1(n)==1 && n)
    {
        ms(flag,0);

        for(i=0; i<n; i++)
            {
                cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
                sort(arr[i],arr[i]+3);
               // cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<endl;
            }

        int ans=0;
        for(i=0;i<n;i++)
        {
            flag[i]=1;
            ans=max(ans,1+bt(i,arr[i][1],arr[i][2]));
            ans=max(ans,1+bt(i,arr[i][0],arr[i][1]));
            ans=max(ans,1+bt(i,arr[i][0],arr[i][2]));
            flag[i]=0;
        }
        printf("Case %d: %d\n",kase++,ans);
    }
    return 0;
}


