#include <stdio.h>
#include <string.h>
int arr[5003][1200],arrlen[5003];
int main ()
{
    arr[0][0]=0;
    arrlen[0]=1;
    arr[1][0]=1;
    arrlen[1]=1;
    int i,len,j,d;
    for(i=2; i<5002; i++)
    {
        d=0;
        len=arrlen[i-1];
        for(j=0; j<len; j++)
        {
            d+=(arr[i-1][j])+(arr[i-2][j]);
            arr[i][j]=d%10;
            d/=10;
        }
        if(d>0)
        {
            arr[i][j]=d;
            ++j;
            arrlen[i]=j;
        }
        else
        {
            arrlen[i]=j;
        }
    }
    int n;
    while((scanf("%d",&n))==1)
    {
        len=arrlen[n];
        printf("The Fibonacci number for %d is ",n);
        for(i=len-1;i>=0;i--)
        printf("%d",arr[n][i]);
        printf("\n");
    }
    return 0;
}
