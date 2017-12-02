#include <stdio.h>
#include <string.h>
int main ()
{
    char test[20];
    char a[6][20]={"HELLO","HOLA","HALLO","BONJOUR","CIAO","ZDRAVSTVUJTE"};
    char b[6][20]={"ENGLISH","SPANISH","GERMAN","FRENCH","ITALIAN","RUSSIAN"};
    int i,c,m=1;
    while(gets(test))
    {
        if(test[0]=='#')
            break;
        for(i=0;i<6;i++)
        {
            c=strcmp(test,a[i]);
            if(c==0)
            {
             printf("Case %d: %s\n",m,b[i]);
                break;
            }
        }
        if(c!=0)
        printf("Case %d: UNKNOWN\n",m);
        m++;
    }
    return 0;
}
