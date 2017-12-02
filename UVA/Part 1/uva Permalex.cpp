#include <string.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
    char a[40],b[40];
    long long int count,len;
    while(gets(a))
    {
        len=strlen(a);
        if(len==1&&a[0]=='#')
        break;
        strcpy(b,a);
        count=0;
        sort(a,a+len);
        do
        {
            count++;
            if((strcmp(a,b))==0)
            break;
        }
        while(next_permutation(a,a+len));
        printf("%10lld\n",count);
    }
    return 0;
}
