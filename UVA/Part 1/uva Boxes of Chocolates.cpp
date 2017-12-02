#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    long long int c,a,test,b,mot,d,e;
    cin>>test;
    while(test--)
    {
        mot=0;
        cin>>a>>b;
        while(b--)
        {
            cin>>c;e=1;
            while(c--)
            {
              cin>>d;
              e*=d;
              e%=a;
            }
            mot+=e;
        }
        cout<<mot%a<<endl;
    }
    return 0;
}
