#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    int test,n,a;
    cin>>test;
    while(test--)
    {
        cin>>n;
        if(n>10)
        {
            a=n-10;
            n-=a;
            cout<<a<<" "<<n<<endl;
        }
        else
        cout<<0<<" "<<n<<endl;
    }
    return 0;
}
