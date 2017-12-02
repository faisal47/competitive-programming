#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
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
#define scch(a) scanf("%c",&a)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sz(a) a.size()
#define mt 100010
using namespace std;
typedef long long ll;
int arr[mt],jog[mt];
int main ()
{
    ll ans;
    int n,i,test,t=0,s,e,maxis,maxi,maxie;
    sci1(test);
    while(test--)
    {
        maxi=-1010;
        if(t++)cout<<endl;
        sci1(n);
        s=e=1;
       // cout<<n<<endl;
        for(i=1;i<=n;i++)
        {
            sci1(arr[i]);
            if(arr[i]>maxi)
            {
                maxis=i;
                maxie=i;
                maxi=arr[i];
            }
            if(i==1)
                jog[i]=ans=arr[i];
            else
            {
                jog[i]=jog[i-1]+arr[i];
               // cout<<jog[i]<<endl;
                if(ans<jog[i])
                {

                   // cout<<ans<<endl;
                    e=i;
                    ans=jog[i];
                   // cout<<ans<<" "<<jog[i]<<endl;
                }
            }
        }
    //  cout<<s<<" jkdfh "<<e<<endl;
        for(i=1;i<n;i++)
        {
            jog[i+1]=jog[i+1]-jog[i];
            if(jog[i+1]>ans)
            {
                s=i+1;
               // cout<<ans<<"  "<<jog[i+1]<<endl;
                ans=jog[i+1];
            }
        }
       printf("Case %d:\n",t);
       if(ans<0)
        cout<<maxi<<" "<<maxis<<" "<<maxie<<endl;
       else
       cout<<ans<<" "<<s<<" "<<e<<endl;
    }
    return 0;
}

