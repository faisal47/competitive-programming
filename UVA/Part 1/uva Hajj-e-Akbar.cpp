#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    char arr[100];
    int test=1;
    while(gets(arr))
    {
        if(arr[0]=='*')
        break;
        else if(strcmp(arr,"Hajj")==0)
        printf("Case %d: Hajj-e-Akbar\n",test++);
        else
        printf("Case %d: Hajj-e-Asghar\n",test++);
    }
    return 0;
}
