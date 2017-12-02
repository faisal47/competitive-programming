#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    int ans,inf=123456789,low,mid,high,lis1,lis2,lis11[100000],lis22[100000],i,test,n,arr[100000],I1[100000],I2[100000];
    cin>>test;
    while(test--)
    {
        I1[0]=inf;
        I2[0]=-inf;ans=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            I1[i+1]=inf;
            I2[i+1]=inf;
        }
        lis1=lis2=0;
        for(i=n-1;i>=0;i--)
        {
            low=0;high=lis1;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(I1[mid]>arr[i])
                low=mid+1;
                else
                high=mid-1;
            }
            I1[low]=arr[i];
            lis11[i]=low;
            lis1=max(low,lis1);
        }
        for(i=n-1;i>=0;i--)
        {
            low=0;high=lis2;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(I2[mid]<arr[i])
                low=mid+1;
                else
                high=mid-1;
            }
            lis22[i]=low;
            I2[low]=arr[i];
            lis2=max(low,lis2);
        }
        for(i=0;i<n;i++)
        ans=max(ans,lis11[i]+lis22[i]-1);
        cout<<ans<<endl;
    }
    return 0;
}
