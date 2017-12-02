#include <stdio.h>
#include <string.h>
int main ()
{
    char arr[1000050];
    int len,i,a,b,c,d,e,flag,j=0,flag1;
    while(gets(arr))
    {
        a=b=c=d=e=flag=flag1=0;
        len=strlen(arr);
        for(i=0;i<len;i++)
        {
            a=((a*10)+(arr[i]-'0'))%4;
            b=((b*10)+(arr[i]-'0'))%100;
            c=((c*10)+(arr[i]-'0'))%400;
            d=((d*10)+(arr[i]-'0'))%15;
            e=((e*10)+(arr[i]-'0'))%55;
        }
        if(j==1)
        printf("\n");
        j=1;
        if((a==0&&b!=0)||c==0)
        {
            flag1=1;
            flag=1;
            printf("This is leap year.\n");
        }
        if(d==0)
        {
            flag=1;
            printf("This is huluculu festival year.\n");
        }
        if(e==0&&flag1==1)
        printf("This is bulukulu festival year.\n");
        if(flag==0)
        printf("This is an ordinary year.\n");
    }
    return 0;
}
