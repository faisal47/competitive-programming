#include <stdio.h>
#include <string.h>
int main ()
{
    char arr[2000];int len,m,n;
    while(gets(arr))
    {
        len=strlen(arr);
        if(arr[0]=='0'&&len==1)
        break;
        n=arr[0]-'0';m=1;
        while(1)
        {
            if(n>=11)
            n%=11;
            if(m==len)
            break;
            n=((n*10)+(arr[m]-'0'));
            m++;
        }
        if(n==0)
        printf("%s is a multiple of 11.\n",arr);
        else
        printf("%s is not a multiple of 11.\n",arr);
    }
    return 0;
}
