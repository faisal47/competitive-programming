#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int arr[10][10],res;
void dfs(int a1,int b1,int a2,int b2,int count)
{
    if(a1==a2&&b1==b2)
    {
        if(res>count)
            res=count;
        return;
    }
    else if(a1>0&&b1>0&&a1<=8&&b1<=8)
    {
        if(count<65)
        {
            count++;
            dfs(a1-2,b1-1,a2,b2,count);
            dfs(a1-2,b1+1,a2,b2,count);
            dfs(a1+1,b1-2,a2,b2,count);
            dfs(a1-1,b1-2,a2,b2,count);
            dfs(a1+1,b1+2,a2,b2,count);
            dfs(a1-1,b1+2,a2,b2,count);
            dfs(a1+2,b1-1,a2,b2,count);
            dfs(a1+2,b1+1,a2,b2,count);
        }
    }
    return;
}
int main ()
{
    int a1,b1,a2,b2,count;
    char arr1[10];
    while(gets(arr1))
    {
        if(arr1[0]=='a')
            b1=1;
        else if(arr1[0]=='b')
            b1=2;
        else if(arr1[0]=='c')
            b1=3;
        else if(arr1[0]=='d')
            b1=4;
        else if(arr1[0]=='e')
            b1=5;
        else if(arr1[0]=='f')
            b1=6;
        else if(arr1[0]=='g')
            b1=7;
        else if(arr1[0]=='h')
            b1=8;
        if(arr1[1]=='1')
            a1=1;
        else if(arr1[1]=='2')
            a1=2;
        else if(arr1[1]=='3')
            a1=3;
        else if(arr1[1]=='4')
            a1=4;
        else if(arr1[1]=='5')
            a1=5;
        else if(arr1[1]=='6')
            a1=6;
        else if(arr1[1]=='7')
            a1=7;
        else if(arr1[1]=='8')
            a1=8;
        if(arr1[3]=='a')
            b2=1;
        else if(arr1[3]=='b')
            b2=2;
        else if(arr1[3]=='c')
            b2=3;
        else if(arr1[3]=='d')
            b2=4;
        else if(arr1[3]=='e')
            b2=5;
        else if(arr1[3]=='f')
            b2=6;
        else if(arr1[3]=='g')
            b2=7;
        else if(arr1[3]=='h')
            b2=8;
        if(arr1[4]=='1')
            a2=1;
        else if(arr1[4]=='2')
            a2=2;
        else if(arr1[4]=='3')
            a2=3;
        else if(arr1[4]=='4')
            a2=4;
        else if(arr1[4]=='5')
            a2=5;
        else if(arr1[4]=='6')
            a2=6;
        else if(arr1[4]=='7')
            a2=7;
        else if(arr1[4]=='8')
            a2=8;
        memset(arr,0,sizeof(arr));
        if(a1==a2&&b1==b2)
        {
            printf("To get from %c%c to %c%c takes 0 knight moves.\n",arr1[0],arr1[1],arr1[3],arr1[4]);
        }
        else
        {
            res=100;
            count=0;
            arr[a2][b2]=1;
            printf("%d %d %d %d\n",a1,b1,a2,b2);
            dfs(a1,b1,a2,b2,count);
            printf("To get from %c%c to %c%c takes %d knight moves.\n",arr1[0],arr1[1],arr1[3],arr1[4],res);
        }
    }
    return 0;
}
