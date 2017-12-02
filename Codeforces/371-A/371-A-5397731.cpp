#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    int i,n,k,arr[110],ans=0,c1,c2,j;
    cin>>n>>k;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    for(i=1;i<=k;i++)
    {
        c1=c2=0;
        for(j=i;j<=n;j+=k)
        {
            if(arr[j]==1)
                c1++;
            else
                c2++;
        }

            if(c1 && c2)
                ans+=min(c1,c2);
    }
    cout<<ans<<endl;
}