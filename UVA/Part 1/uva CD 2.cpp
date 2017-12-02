#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main ()
{
    vector<int>v[30];
    int arr[30],i,j,dur,n,sum[25];
    while(cin>>dur>>n)
    {
        memset(sum,0,sizeof(sum));
        for(i=0;i<25;i++)
        v[i].clear();
        for(i=0;i<n;i++)
        cin>>arr[i];
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if((arr[j]+sum[i])<=dur)
            {
                sum[i]+=arr[j];
                v[i].push_back(arr[j]);
            }
        }
        int c=0,d;
        for(i=0;i<n;i++)
        if(c<sum[i])
        {
            c=sum[i];
            d=i;
        }
        for(i=0;i<v[d].size();i++)
        cout<<v[d][i]<<" ";
        printf("sum:%d\n",sum[d]);
    }
    return 0;
}
