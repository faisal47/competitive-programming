#include <stdio.h>
#include <string.h>
#include <math.h>
int main ()
{
    char arr[1000];
    unsigned long long n,len,i,m;
    while(gets(arr))
    {
        len=strlen(arr);
        if(arr[0]=='-')
            break;
        n=0;
        if(arr[1]=='x'&&arr[0]=='0')
        {
            m=len-3;
            for(i=2; i<len; i++)
            {
                if(arr[i]=='A'||arr[i]=='a')
                {
                    n+=10*pow(16,m);m--;
                }
                else if(arr[i]=='B'||arr[i]=='b')
                {
                     n+=11*pow(16,m);m--;
                }
                else if(arr[i]=='C'||arr[i]=='c')
                {
                    n+=12*pow(16,m);m--;
                }
                else if(arr[i]=='D'||arr[i]=='d')
                {
                        n+=13*pow(16,m);m--;
                }
                else if(arr[i]=='E'||arr[i]=='e')
                {
                        n+=14*pow(16,m);m--;
                }
                else if(arr[i]=='F'||arr[i]=='f')
                {
                    n+=15*pow(16,m);m--;
                }
                else
                {
                    n+=(arr[i]-'0')*pow(16,m);m--;
                }
            }
            printf("%llu\n",n);
        }
        else
        {
            for(i=0; i<len; i++)
            {
                n*=10;
                n+=(arr[i]-'0');
            }
            printf("0x%X\n",n);
        }
    }
    return 0;
}
