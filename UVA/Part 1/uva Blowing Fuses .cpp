#include <stdio.h>
#include <iostream>
#include <iostream>
using namespace std;
int main ()
{
    long long test=1,arr[25],n,m,i,flag[25],maxi,flag1;
    long long sum1,sum2;
    while(cin>>n>>m>>sum2)
    {
        if(n==0&&m==0&&sum2==0)
        break;
        sum1=0;flag1=0;
        maxi=0;
        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
            flag[i]=0;
        }
        while(m--)
        {
            cin>>i;
            flag[i]+=1;
            if(flag[i]%2==0)
            sum1-=arr[i];
            else
            sum1+=arr[i];
            if(sum1>sum2)
            flag1=1;
            maxi=max(maxi,sum1);
        }
        if(flag1==1)
        printf("Sequence %lld\nFuse was blown.\n",test++);
        else
        {
            printf("Sequence %lld\nFuse was not blown.\nMaximal power consumption was %lld amperes.\n",test++,maxi);
        }
        cout<<endl;
    }
    return 0;
}
