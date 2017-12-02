#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    bool arr[105][105];
    int n,i,j,count,a,b,count0,count1,sum;
    while(cin>>n)
    {
        if(n==0)
        break;
        count=0;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        cin>>arr[i][j];
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
            sum+=arr[i][j];
            if((sum%2)!=0)
            ++count;
            if(count==1)
            {
                count0=count1=0;
                for(j=0;j<n;j++)
                {
                    if(arr[i][j]==0)
                    count0++;
                    else
                    count1++;
                }
                for(j=0;j<n;j++)
                {
                    if((count0>count1)&&arr[i][j]==1)
                    {
                        a=i+1;b=j+1;
                        break;
                    }
                    else if((count0<count1)&&arr[i][j]==0)
                    {
                        a=i+1;b=j+1;
                        break;
                    }
                }
            }
        }
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
            sum+=arr[j][i];
            if((sum%2)!=0)
            ++count;
            if(count==1)
            {
                count0=count1=0;
                for(j=0;j<n;j++)
                {
                    if(arr[j][i]==0)
                    count0++;
                    else
                    count1++;
                }
                for(j=0;j<n;j++)
                {
                    if((count0>count1)&&arr[j][i]==1)
                    {
                        a=i+1;b=j+1;
                        break;
                    }
                    else if((count0<count1)&&arr[j][i]==0)
                    {
                        a=i+1;b=j+1;
                        break;
                    }
                }
            }
        }
        if(count==0)
        printf("OK\n");
        else if(count==1)
        printf("Change bit (%d,%d)\n",a,b);
        else
        printf("Corrupt\n");
    }
    return 0;
}
