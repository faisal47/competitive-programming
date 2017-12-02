#include <bits/stdc++.h>
#define pb push_back
#define vec_ vector
#define clr(a) a.clear()
#define sz(a) a.size()
using namespace std;
typedef long long ll;
int main ()
{
    vec_<ll>ins,ans;
    ll i,j,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>j;
        ins.pb(j);
    }
    ll ekhon,ekhon1;
    for(i=31;i>=0;i--)
    {
        ekhon=1<<(i+1);
        ekhon--;
        clr(ans);
        ekhon1=1<<i;
        for(j=0;j<n;j++)
        if(ins[j] & ekhon1)
        {
            ans.pb(ins[j]);
            ekhon=ekhon & ins[j];
        }
        if(sz(ans) && !(ekhon1 % ekhon))
        break;
    }
    cout<<sz(ans)<<endl;
    for(i=0;i<sz(ans);i++)
    cout<<ans[i]<<" ";
    return 0;
}