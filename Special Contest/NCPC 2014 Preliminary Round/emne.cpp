#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int t,b=0;
    scanf("%d",&t);
    char gar;
    scanf("%c",&gar);
    while(t--)
    {
        int l;
        char s[1000];
        gets(s);
        l=strlen(s);
        long long int c=0;
        int i,j;
        for(i=0; i<l; i++)
        {
            for(j=i+1; j<=l; j++) if(s[i]==s[j]) c++;
        }

        long long int x=pow(2,l);
        long long int y=x-c;

        y=y%100009;
        printf("Case %d: %lld\n",++b,y);
    }
    return 0;
}
