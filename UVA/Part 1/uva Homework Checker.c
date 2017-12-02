#include <stdio.h>
#include <string.h>
int main ()
{
    char c,f,arr[50];
    int a,b,d,g,e=0,len,i;
    while((scanf("%d%c%d",&a,&c,&b))==3)
    {
        gets(arr);
        len=strlen(arr);
        if(arr[1]=='?')
            continue;
            d=0;
        for(i=1; i<len; i++)
            d=(10*d)+(arr[i]-'0');
        if(c=='+')
        {
            if((a+b)==d)
                e++;
        }
        else
        {
            g=a-b;
            if(g<0)
                g*=(-1);
            if(g==d)
                e++;
        }
    }
    printf("%d\n",e);
    return 0;
}

