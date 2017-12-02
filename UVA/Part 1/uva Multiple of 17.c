#include <stdio.h>
#include <string.h>
int main ()
{
    char arr[105];
    int len,m,n;
    while(gets(arr))
    {
        len=strlen(arr);
        if(arr[0]=='0'&&len==1)
        break;
        n=arr[0]-'0';m=1;
        while(1)
        {
            if(n>=17)
            n%=17;
            if(m==len)
            break;
            n=((n*10)+(arr[m]-'0'));
            m++;
        }
        if(n==0)
        printf("1\n");
        else
        printf("0\n");
    }
    return 0;
}
