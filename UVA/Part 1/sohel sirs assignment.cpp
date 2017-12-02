#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 100000000000000
using namespace std;
int main ()
{
    long long test,x,y,i,k,xmain,j,j1;
    cin>>test;
    while(test--)
    {
        cin>>x>>y;
        y-=2L;
        if(x<y)
        {
            cout<<"Impossible"<<endl;
            continue;
        }
        else if(x==y)
        {
            cout<<x+1<<endl;
            continue;
        }
        xmain=x;
        x=x-y;
        k=sqrt(x)+1;
        j1=inf;
        for(i=1; i<k; i++)
        {
            if(x%i==0)
            {
                if(xmain%i==y)
                {
                        j1=min(j1,i);
                }
            }
            j=x/i;
            if(x%j==0)
            {
                if(xmain%j==y)
                {
                        j1=min(j1,j);
                }
            }
        }
        if(j1==inf)
            cout<<"Impossible"<<endl;
        else
            cout<<j1<<endl;
    }
    return 0;
}
