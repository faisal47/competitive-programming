#include <stdio.h>
#include <iostream>
using namespace std;
int inf=123456789,arr[1000010],I[1000010];
int main ()
{
    I[0]=-inf;
    int n,c=0,i,mid,low,high,lis,test=0;
    while(cin>>n)
    {
        if(n==-1&&c==0)
        break;
        else if(n==-1)
        {
            I[c]=inf;
            lis=0;
            for(i=c-1;i>=0;i--)
            {
                low=0;high=lis;
                while(low<=high)
                {
                    mid=(low+high)/2;
                    if(I[mid]<arr[i])
                    low=mid+1;
                    else
                    high=mid-1;
                }
                I[low]=arr[i];
                lis=max(lis,low);
            }
            if(test++)
            cout<<endl;
            printf("Test #%d:\n  maximum possible interceptions: ",test);
            cout<<lis+1<<endl;
            c=0;
        }
        else
        {
            arr[c]=n;
            I[c]=inf;
            c++;
        }
    }
    return 0;
}
