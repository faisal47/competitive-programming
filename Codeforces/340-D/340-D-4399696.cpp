#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define sci1(a) scanf("%d",&a)
#define mt 100010
using namespace std;
int arr[mt],n,i,low,high,I[mt];
int LisL()
{
    int lis=0,mid;
    ms(I,inf);
    I[0]=-I[0];
    for(i=0;i<n;i++)
    {
        low=0;
        high=lis;
        while(low<=high)
        {
            mid=(low+high)>>1;
            if(I[mid]<arr[i])
            low=mid+1;
            else
            high=mid-1;
        }
        I[low]=arr[i];
        lis=max(lis,low);
    }
    return lis;

}
int main ()
{
    sci1(n);
    for(i=0;i<n;i++)
    sci1(arr[i]);
    cout<<LisL();
    return 0;
}