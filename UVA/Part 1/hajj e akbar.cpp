#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string a;
    int t=1;
    while(cin>>a)
    {
        if(a[0]=='*')
        break;
        printf("Case %d: ",t++);
        if(a=="Hajj")
        printf("Hajj-e-Akbar\n");
        else
        printf("Hajj-e-Asghar\n");
    }
    return 0;
}
