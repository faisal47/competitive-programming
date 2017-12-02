#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    long long int a,b,d,test,count,plus,jog;
    cin>>test;
    while(test--)
    {
        cin>>a>>b;
        if(a==b)
        {
            cout<<0<<endl;
            continue;
        }
        else if((b-a)==1)
        {
            cout<<1<<endl;
            continue;
        }
        d=b-a;
        plus=2;
        a=d/2;
        count=jog=0;
        while(jog<d)
        {
            jog+=plus/2;
            plus++;
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
