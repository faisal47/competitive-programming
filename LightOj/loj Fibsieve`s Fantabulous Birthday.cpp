#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
   long long int test,t,n,row,col,y,mid;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>n;
        y=sqrt(n);
        if((y*y)==n);
        else
        y++;
        //cout<<y<<endl;
        mid=(y*y)-(y-1);
       // cout<<mid<<endl;
       if(n==mid)
       {
           row=col=y;
       }
       else if(y%2==0)
       {
           if(n>mid)
           {
               row=((y*y)-n)+1;
               col=y;
           }
           else
           {
               row=y;
               col=y-(mid-n);
           }
       }
       else
       {
           if(n>mid)
           {
              col=(y*y)-n+1;
               row=y;
           }
           else
           {
               col=y;
               row=y-(mid-n);
           }
       }
       printf("Case %lld: %lld %lld\n",t,col,row);
    }
    return 0;
}
