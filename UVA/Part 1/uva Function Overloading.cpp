#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
long long int sod(long long int a)
{
    long long int b=0;
    while(1)
    {
        b+=a%10;
        a/=10;
        if(a==0)
            break;
    }
    return b;
}
long long int fun(long long int a,long long int b)
{
    long long int ans=0;
    long long int i,j,cnt;
    for(i=a; i<=b; i++)
    {
        cnt=0;
        for(j=1;j<=i;j++)
        {
            if((j+sod(j))==i)
            cnt++;
        }
        if(cnt==0)
        ans++;
    }
    return ans;
}
long long int fun(long long int a)
{
    long long int i;
    for(i=1;i<=a;i++)
    {
        if((i+sod(i))==a)
        return i;
    }
    return -1;
}
int main ()
{
    long long int test,a,b,ret,c=1,len,i,flag;
    char arr[100],z;
    scanf("%lld",&test);
    scanf("%c",&z);
    while(test--)
    {
        a=b=flag=0;
        gets(arr);
        len=strlen(arr);
        for(i=0; i<len; i++)
        {
            if(arr[i]==' ')
                flag=1;
            else if(flag==0)
            {
                a=((a*10)+(arr[i]-'0'));
            }
            else
            {
                b=((b*10)+(arr[i]-'0'));
            }
        }
        if(flag==1)
            ret=fun(a,b);
        else
            ret=fun(a);
        printf("Case %lld: %lld\n",c++,ret);
    }
    return 0;
}
