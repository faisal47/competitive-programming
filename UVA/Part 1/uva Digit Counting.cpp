#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    int number[11];
    int test,n,a,i,b;
    cin>>test;
    while(test--)
    {
        cin>>n;
        memset(number,0,sizeof(number));
        for(i=1;i<=n;i++)
        {
            a=i;
            while(1)
            {
                if(a==0)
                break;
                b=a%10;
                a/=10;
                number[b]++;
            }
        }
        cout<<number[0];
        for(i=1;i<10;i++)
        cout<<" "<<number[i];
        cout<<endl;
    }
    return 0;
}
