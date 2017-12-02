#include <stdio.h>
#include <iostream>
using namespace std;
int n,arr[10005],inf=12345678,I1[10005],f[10005],b[10005],I2[10005];
void flis()
{
    int i,low,high,mid,lis=1;
    for(i=1;i<=n;i++)
    {
        low=0;high=lis;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(I1[mid]<arr[i])
            low=mid+1;
            else
            high=mid-1;
        }
        I1[low]=arr[i];
        if(lis<low)
        lis=low;
        if(f[i]<low)
        f[i]=low;
    }
}
void blis()
{
    int i,low,high,mid,lis=1;
    for(i=n;i>=1;i--)
    {
        low=0;high=lis;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(I2[mid]<arr[i])
            low=mid+1;
            else
            high=mid-1;
        }
        I2[low]=arr[i];
        if(lis<low)
        lis=low;
        if(b[i]<low)
        b[i]=low;
    }
}
int main ()
{
    int ans,i;
    while(cin>>n)
    {
        ans=-inf;
        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
            f[i]=b[i]=1;
            I1[i]=I2[i]=inf;
        }
        I1[0]=I2[0]=-inf;
        //cout<<"hello"<<endl;
        flis();
        //cout<<"hello"<<endl;
        blis();
        for(i=1;i<=n;i++)
        ans=max(ans,min(f[i],b[i]));
        cout<<(ans*2)-1<<endl;
    }
    return 0;
}
