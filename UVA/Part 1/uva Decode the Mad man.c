#include <stdio.h>
#include <string.h>
int main ()
{
    char arr[1000];unsigned i,len;
    while(gets(arr))
    {
        len=strlen(arr);
        for(i=0;i<len;i++)
        {
            if(arr[i]=='e'||arr[i]=='E')
            printf("q");
            else if(arr[i]=='r'||arr[i]=='R')
            printf("w");
            else if(arr[i]=='t'||arr[i]=='T')
            printf("e");
            else if(arr[i]=='y'||arr[i]=='Y')
            printf("r");
            else if(arr[i]=='u'||arr[i]=='U')
            printf("t");
            else if(arr[i]=='i'||arr[i]=='I')
            printf("y");
            else if(arr[i]=='o'||arr[i]=='O')
            printf("u");
            else if(arr[i]=='p'||arr[i]=='P')
            printf("i");
            else if(arr[i]=='['||arr[i]=='{')
            printf("o");
            else if(arr[i]==']'||arr[i]=='}')
            printf("p");
            else if(arr[i]=='d'||arr[i]=='D')
            printf("a");
            else if(arr[i]=='f'||arr[i]=='F')
            printf("s");
            else if(arr[i]=='g'||arr[i]=='G')
            printf("d");
            else if(arr[i]=='h'||arr[i]=='H')
            printf("f");
            else if(arr[i]=='j'||arr[i]=='J')
            printf("g");
            else if(arr[i]=='k'||arr[i]=='K')
            printf("h");
            else if(arr[i]=='l'||arr[i]=='L')
            printf("j");
            else if(arr[i]==';'||arr[i]==':')
            printf("k");
            else if(arr[i]==34||arr[i]==39)
            printf("l");
            else if(arr[i]=='/'||arr[i]=='?')
            printf(",");
            else if(arr[i]=='.'||arr[i]=='>')
            printf("m");
            else if(arr[i]==','||arr[i]=='<')
            printf("n");
            else if(arr[i]=='m'||arr[i]=='M')
            printf("b");
            else if(arr[i]=='n'||arr[i]=='N')
            printf("v");
            else if(arr[i]=='b'||arr[i]=='B')
            printf("c");
            else if(arr[i]=='v'||arr[i]=='V')
            printf("x");
            else if(arr[i]=='c'||arr[i]=='C')
            printf("z");
            else
            printf("%c",arr[i]);
        }
        printf("\n");
    }
    return 0;
}
