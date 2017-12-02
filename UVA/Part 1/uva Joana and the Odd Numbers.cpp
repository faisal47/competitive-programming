#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    long long int n,a;
    while(cin>>a)
    {
        n=a;
        n/=2;
        n+=1;
        a+=1;
        n*=a;
        n-=1;
        n+=(n-2)+(n-4);
        cout<<n<<endl;
    }
    return 0;
}
