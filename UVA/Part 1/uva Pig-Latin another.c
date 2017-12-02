#include <stdio.h>
#include <string.h>
char arr[20000000],arr1[20000000];
int main ()
{
    int len,i,j,k,l,flag1,flag2,a,b,c;
    while(gets(arr))
    {
        a=flag1=flag2=0;
        len=strlen(arr);
        if((arr[0]>='A'&&arr[0]<='Z')||(arr[0]>='a'&&arr[0]<='z'))
            flag2=0;
        else
            flag2=1;
        if(flag2==1)
        {
            for(i=0; i<len; i++)
            {
                if((arr[i]>='A'&&arr[i]<='Z')||(arr[i]>='a'&&arr[i]<='z'))
                {
                    a=i;
                    break;
                }
                else
                    printf("%c",arr[i]);
            }
        }
        flag1=flag2=c=0;
        for(i=a; i<len; i++)
        {
            if(arr[i]<65||(arr[i]>90&&arr[i]<97)||arr[i]>122)
                flag2=0;
            else
                flag2=1;
            if(flag2==1)
            {
                arr1[c++]=arr[i];
            }
            else
            {
                if(c==0)
                    printf("%c",arr[i]);
                else
                {
                    if(arr1[0]=='A'||arr1[0]=='E'||arr1[0]=='I'||arr1[0]=='O'||arr1[0]=='U'||arr1[0]=='a'||arr1[0]=='e'||arr1[0]=='i'||arr1[0]=='o'||arr1[0]=='u')
                    {
                        for(j=0; j<c; j++)
                            printf("%c",arr1[j]);
                        printf("ay");
                        printf("%c",arr[i]);
                    }
                    else
                    {
                        for(j=1; j<c; j++)
                            printf("%c",arr1[j]);
                        printf("%c",arr1[0]);
                        printf("ay");
                        printf("%c",arr[i]);
                    }
                    c=0;
                }
            }
        }
        if((arr[len-1]>='a'&&arr[len-1]<='z')||(arr[len-1]>='A'&&arr[len-1]<='Z'))
        {
            if(arr1[0]=='A'||arr1[0]=='E'||arr1[0]=='I'||arr1[0]=='O'||arr1[0]=='U'||arr1[0]=='a'||arr1[0]=='e'||arr1[0]=='i'||arr1[0]=='o'||arr1[0]=='u')
            {
                for(j=0; j<c; j++)
                    printf("%c",arr1[j]);
                printf("ay");
            }
            else
            {
                for(j=1; j<c; j++)
                    printf("%c",arr1[j]);
                printf("%c",arr1[0]);
                printf("ay");
            }
        }
        printf("\n");
    }
    return 0;
}
