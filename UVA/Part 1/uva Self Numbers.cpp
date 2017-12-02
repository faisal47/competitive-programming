#include <stdio.h>
#include <iostream>
using namespace std;
bool flag[1000010];
int main ()
{
    unsigned long long i=1,a,b;
    while(1)
    {
        if(flag[i]==0&&i<=1000000)
        {
            cout<<i<<endl;
            flag[i]=1;
        }
        a=i;b=i;
        while(1)
        {
            a+=b%10;b/=10;
            if(b==0)
            break;
        }
        flag[a]=1;
        if(i>=1000000)
        break;
        i++;
    }
    return 0;
}
