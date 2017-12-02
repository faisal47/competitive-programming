#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    int n,k,a,b,c,d,i;
    while(cin>>n>>k)
    {
        d=0;
        for(i=0;i<n;i++)
        {
            c=0;
            cin>>a;
            while(1)
            {
                if(a==0)
                break;
                if(a%10==7||a%10==4)
                c++;
                a/=10;
            }
            if(c<=k)
            d++;
        }
        cout<<d<<endl;
    }
    return 0;
}