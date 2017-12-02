#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
char a[1000010],b[2000010],z;
int f[2000010];
int kmp()
{
    int n,i,k,n1=strlen(a);
    strcpy(b,a);
    //strrev(b);
    i=0;
    n1--;
    while(i<n1)
    {
        swap(b[i],b[n1]);
        i++;n1--;
    }
    n1=strlen(a);
    b[n1]='#';
    b[n1+1]='\0';
    strcat(b,a);
    f[0]=k=0;
    n=strlen(b);
    for(i=1;i<n;i++)
    {
        while(k>0 && b[i]!=b[k])
        k=f[k-1];
        if(b[i]==b[k])
        k++;
        f[i]=k;
    }
    n1=(n1*2)-f[n-1];
    return n1;
}
int main ()
{
    int test,t;
    scanf("%d",&test);
    scanf("%c",&z);
    for(t=1;t<=test;t++)
    {
        gets(a);
        printf("Case %d: %d\n",t,kmp());
    }
    return 0;
}
