#include <stdio.h>
#include <string.h>
int main ()
{
    int len,i,flag1,flag2,flag3,flag4,flag5,flag6;
    char arr[25];
    while(gets(arr))
    {
        flag1=0;
        flag2=0;
        flag3=0;
        flag4=0;
        flag5=0;
        flag6=0;
        len=strlen(arr);
        for(i=0; i<len; i++)
        {
            if((arr[i]=='B'||arr[i]=='F'||arr[i]=='P'||arr[i]=='V')&&flag1==0)
            {
                printf("1");
                flag1=1;
                flag2=0;
                flag3=0;
                flag4=0;
                flag5=0;
                flag6=0;
            }
            else if((arr[i]=='C'||arr[i]=='G'||arr[i]=='J'||arr[i]=='K'||arr[i]=='Q'||arr[i]=='S'||arr[i]=='X'||arr[i]=='Z')&&flag2==0)
            {
                printf("2");
                flag1=0;
                flag2=1;
                flag3=0;
                flag4=0;
                flag5=0;
                flag6=0;
            }
            else if((arr[i]=='D'||arr[i]=='T')&&flag3==0)
            {
                printf("3");
                flag1=0;
                flag2=0;
                flag3=1;
                flag4=0;
                flag5=0;
                flag6=0;
            }
            else if(arr[i]=='L'&&flag4==0)
            {
                printf("4");
                flag1=0;
                flag2=0;
                flag3=0;
                flag4=1;
                flag5=0;
                flag6=0;
            }
            else if ((arr[i]=='M'||arr[i]=='N')&&flag5==0)
            {
                printf("5");
                flag1=0;
                flag2=0;
                flag3=0;
                flag4=0;
                flag5=1;
                flag6=0;
            }
            else if(arr[i]=='R'&&flag6==0)
            {
                printf("6");
                flag1=0;
                flag2=0;
                flag3=0;
                flag4=0;
                flag5=0;
                flag6=1;
            }
            else if(arr[i]=='A'||arr[i]=='E'||arr[i]=='I'||arr[i]=='O'||arr[i]=='U'||arr[i]=='H'||arr[i]=='W'||arr[i]=='Y')
            {
                flag1=0;
                flag2=0;
                flag3=0;
                flag4=0;
                flag5=0;
                flag6=0;
            }
        }
        printf("\n");
    }
    return 0;
}
