#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main ()
{
    int test,t,a,b,c,a1,b1,i,arr3[50];
    char z,arr1[50],arr2[50];
    scanf("%d",&test);
    scanf("%c",&z);
    for(t=1; t<=test; t++)
    {
        gets(arr1);
        gets(arr2);
        b=0,c=0;
        a=strlen(arr1);
        for(i=0; i<a; i++)
            arr3[i]=(arr1[i]-48);
        for(i=(a-1); i>=0; i--)
        {
            c+=(arr3[b] * pow(2,i));
            b++;
        }
        a1=c;
        b=0,c=0;
        a=strlen(arr2);
        for(i=0; i<a; i++)
            arr3[i]=(arr2[i]-48);
        for(i=(a-1); i>=0; i--)
        {
            c+=(arr3[b] * pow(2,i));
            b++;
        }
        b1=c;
        a=gcd(a1,b1);
        if(a>1)
        printf("Pair #%d: All you need is love!\n",t);
        else
        printf("Pair #%d: Love is not all you need!\n",t);
    }
}
