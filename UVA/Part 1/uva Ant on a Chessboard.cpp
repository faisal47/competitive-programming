#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
    long long int mid,time,a,b1,a1;
    while(cin>>time)
    {
        if(time==0)
        break;
        a=sqrt(time);
        if((a*a)!=time)
        a+=1;
        b1=a-1;
        b1*=b1;
        b1+=1;
        a1=a*a;
        mid=(a1+b1)/2;
        if(mid==time)
        printf("%lld %lld\n",a,a);
        else if((a%2)==1)
        {
            if(time<mid)
                cout<<a<<" "<<a-(mid-time)<<endl;
            else
            cout<<a-(time-mid)<<" "<<a<<endl;
        }
        else
        {
            if(time<mid)
            cout<<a-(mid-time)<<" "<<a<<endl;
            else
            cout<<a<<" "<<a-(time-mid)<<endl;
        }
    }
    return 0;
}
