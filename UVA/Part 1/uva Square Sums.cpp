#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    int n,i,j,arr[12][12],result[15],test=1,danx,dany,bamx,bamy,count;
    while(cin>>n)
    {
        if(n==0)
        break;
        memset(result,0,sizeof(result));
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        cin>>arr[i][j];
        bamx=count=0;danx=n;
        if(n==1)
        printf("Case %d: %d\n",test++,arr[0][0]);
        else if((n%2)==0)
        {
            while(1)
            {
                for(i=bamx;i<danx;i++)
                result[count]+=arr[bamx][i];
                for(i=bamx;i<danx;i++)
                result[count]+=arr[danx-1][i];
                for(i=bamx+1;i<danx-1;i++)
                result[count]+=arr[i][bamx];
                for(i=bamx+1;i<danx-1;i++)
                result[count]+=arr[i][danx-1];
                ++count;
                ++bamx;--danx;
                if(bamx==danx)
                break;
            }
            printf("Case %d:",test++);
            for(i=0;i<count;i++)
            printf(" %d",result[i]);
            printf("\n");
        }
        else
        {
            while(1)
            {
                for(i=bamx;i<danx;i++)
                result[count]+=arr[bamx][i];
                for(i=bamx;i<danx;i++)
                result[count]+=arr[danx-1][i];
                for(i=bamx+1;i<danx-1;i++)
                result[count]+=arr[i][bamx];
                for(i=bamx+1;i<danx-1;i++)
                result[count]+=arr[i][danx-1];
                ++count;
                ++bamx;--danx;
                if(bamx==danx-1)
                break;
            }
            printf("Case %d:",test++);
            for(i=0;i<count;i++)
            printf(" %d",result[i]);
            printf(" %d",arr[bamx][danx-1]);
            printf("\n");
        }
    }
    return 0;
}
