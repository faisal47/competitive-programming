#include <stdio.h>
#include <string.h>
char arr[10000000],arr1[10000000];
int main ()
{
    unsigned long long i,len,j,k,l,c;
    while(gets(arr))
    {
        len=strlen(arr);
        c=0;
        for(i=0; i<len; i++)
        {
            if(arr[i]<65||(arr[i]>90&&arr[i]<97)||arr[i]>122)
            {
                if(arr1[0]=='A'||arr1[0]=='E'||arr1[0]=='I'||arr1[0]=='O'||arr1[0]=='U'||arr1[0]=='a'||arr1[0]=='e'||arr1[0]=='i'||arr1[0]=='o'||arr1[0]=='u')
                {
                    for(j=0; j<c; j++)
                        printf("%c",arr1[j]);
                    printf("ay");
                    printf(" ");
                }
                else
                {
                    for(j=1; j<c; j++)
                        printf("%c",arr1[j]);
                        printf("%c",arr1[0]);
                    printf("ay");
                    printf(" ");
                }
                c=0;
            }
            else
                arr1[c++]=arr[i];
        }
        if(c==len)
        {
            if(arr1[0]=='A'||arr1[0]=='E'||arr1[0]=='I'||arr1[0]=='O'||arr1[0]=='U'||arr1[0]=='a'||arr1[0]=='e'||arr1[0]=='i'||arr1[0]=='o'||arr1[0]=='u')
                {
                    for(j=0; j<c; j++)
                        {
                            if((arr1[j]>='a'&&arr1[j]<='z')||(arr1[j]>='A'&&arr1[j]<='Z'))
                            printf("%c",arr1[j]);
                        }
                    printf("ay");
                }
                else
                {
                    for(j=1; j<c; j++)
                    {
                        if((arr1[j]>='a'&&arr1[j]<='z')||(arr1[j]>='A'&&arr1[j]<='Z'))
                            printf("%c",arr1[j]);
                    }
                        printf("%c",arr1[0]);
                    printf("ay");
                }
                if(arr[len-1]!='a'&&arr[len-1]!='b'&&arr[len-1]!='c'&&arr[len-1]!='d'&&arr[len-1]!='e'&&arr[len-1]!='f'&&arr[len-1]!='g'&&arr[len-1]!='h'&&arr[len-1]!='i'&&arr[len-1]!='j'&&arr[len-1]!='k'&&arr[len-1]!='l'&&arr[len-1]!='m'&&arr[len-1]!='n'&&arr[len-1]!='o'&&arr[len-1]!='p'&&arr[len-1]!='q'&&arr[len-1]!='r'&&arr[len-1]!='s'&&arr[len-1]!='t'&&arr[len-1]!='u'&&arr[len-1]!='v'&&arr[len-1]!='w'&&arr[len-1]!='x'&&arr[len-1]!='y'&&arr[len-1]!='z'&&arr[len-1]!='A'&&arr[len-1]!='B'&&arr[len-1]!='C'&&arr[len-1]!='D'&&arr[len-1]!='E'&&arr[len-1]!='F'&&arr[len-1]!='G'&&arr[len-1]!='H'&&arr[len-1]!='I'&&arr[len-1]!='J'&&arr[len-1]!='K'&&arr[len-1]!='L'&&arr[len-1]!='M'&&arr[len-1]!='N'&&arr[len-1]!='O'&&arr[len-1]!='P'&&arr[len-1]!='Q'&&arr[len-1]!='R'&&arr[len-1]!='S'&&arr[len-1]!='T'&&arr[len-1]!='U'&&arr[len-1]!='V'&&arr[len-1]!='W'&&arr[len-1]!='X'&&arr[len-1]!='Y'&&arr[len-1]!='Z')
                printf("%c",arr[len-1]);
                printf("\n");
    }
        }
    return 0;
}
