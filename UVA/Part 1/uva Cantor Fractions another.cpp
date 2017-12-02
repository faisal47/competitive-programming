#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main ()
{
    unsigned long long a,i,c=1,b,j,n,sum;
    while((scanf("%llu",&n))==1)
    {
        if(n==1)
        {
            cout<<"1/1"<<endl;
            continue;
        }
         sum=sqrt(1+(4*2*n));
        sum-=1;
        sum/=2;
        a=(sum*(sum+1))/2;
        if(a==n)
        {
            b=a;
            sum-=1;
            a=(sum*(sum+1))/2;
        }
        else
        {
            sum+=1;
        b=(sum*(sum+1))/2;
        }
        j=b-a;
        i=n-a;
        j=(j-i)+1;
        cout<<j<<"/"<<i<<endl;
    }
    return 0;
}
