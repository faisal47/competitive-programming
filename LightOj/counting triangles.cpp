#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define sz
using namespace std;
int main ()
{
    long long j,k,c,n,test,t,i,arr[2010],h,l,mid,dorkar;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>n;
        for(i=0;i<n;i++)
        cin>>arr[i];
        c=0;
        sort(arr,arr+n);
        for(i=0;i<n-2;i++)
        for(j=i+1;j<n-1;j++)
        {
            dorkar=-1;
            l=j+1;h=n-1;
            while(l<=h)
            {
                mid=(l+h)/2;
                if(arr[mid]<arr[i]+arr[j])
                {
                    l=mid+1;
                    dorkar=max(dorkar,mid);
                }
                else
                h=mid-1;
            }
            if(arr[dorkar]<arr[i]+arr[j] && dorkar!=-1)
            {
                //cout<<dorkar<<endl;
                c+=(dorkar-j);
              //  cout<<"eikhane "<<i<<" "<<j<<" "<<mid<<endl;
            }
        }
        printf("Case %lld: %lld\n",t,c);
    }
    return 0;
}

