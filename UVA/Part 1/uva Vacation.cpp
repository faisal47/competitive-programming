#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char arr1[110],arr2[110];
int c[110][110],len1,len2;
int lcsf(void)
{
    int i,j;
    for(i=0;i<len1;i++)
    for(j=0;j<len2;j++)
    if(arr1[i]==arr2[j])
    c[i+1][j+1]=c[i][j]+1;
    else
    c[i+1][j+1]=max(c[i][j+1],c[i+1][j]);
    return c[len1][len2];
}
int main ()
{
    int lcs,test=1;
    while(gets(arr1))
    {
        if(arr1[0]=='#')
        break;
        gets(arr2);
        len1=strlen(arr1);
        len2=strlen(arr2);
        lcs=lcsf();
        printf("Case #%d: you can visit at most %d cities.\n",test++,lcs);
    }
    return 0;
}
