#include <stdio.h>
#include <string.h>
#include <math.h>
int main ()
{
    unsigned long long n;
    unsigned arr1[1000],len,i,j,k;
    char arr[1000];
    while(gets(arr))
    {
        if(arr[0]=='0')
        break;
        n=0;
        len=strlen(arr);j=len;
        for(i=0;i<len;i++)
        {n+=((arr[i]-'0')*(pow(2,j)-1));j--;}
        printf("%llu\n",n);
    }
    return 0;
}
