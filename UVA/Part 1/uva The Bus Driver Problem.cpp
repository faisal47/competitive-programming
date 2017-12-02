#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    long long int n,d,r,t,b,e,arr[105],i,min,flag;
    while(cin>>n>>d>>r)
    {
        if(n==0&&d==0&&r==0)
            break;
        for(i=0; i<105; i++)
            arr[i]=0;
        t=2;flag=0;min=0;
        while(t--)
        {
            for(i=0; i<n; i++)
            {
                cin>>b;
                arr[i]+=b;
            }
        }
        for(i=0; i<n; i++)
        {
            if(arr[i]>d)
                {
                    e=arr[i]-d;
                    if(flag==0)
                    {
                        min=e;
                        flag=1;
                    }
                    else if(e<min)
                    min=e;
                }
        }
        e=r*min;
        cout<<e<<endl;
    }
    return 0;
}
