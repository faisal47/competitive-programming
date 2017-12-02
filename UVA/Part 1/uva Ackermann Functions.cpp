#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    long long int a,b,i,max_count,count,maxi_val,maxi_val_final;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)
            break;
        if(a>b)
            swap(a,b);
        max_count=0;
        for(i=a; i<=b; i++)
        {
            if(i==0)
            {
                continue;
            }
            if(i==1)
            {
                max_count=3;
                maxi_val_final=1;
                continue;
            }
            count=1;
            maxi_val=i;
            while(1)
            {
                if((i%2)==1)
                    i=(3*i)+1;
                else
                    i/=2;
                    if(i==1)
                break;
                count++;
            }
            if(count>max_count)
            {
                max_count=count;
                maxi_val_final=maxi_val;
            }
            i=maxi_val;
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",a,b,maxi_val_final,max_count);
    }
    return 0;
}
