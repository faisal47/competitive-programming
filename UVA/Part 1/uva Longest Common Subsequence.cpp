#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char arr1[1010],arr2[1010];
int len1,len2,c[1010][1010];
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
    int lcs;
    while(gets(arr1))
    {
        gets(arr2);
        len1=strlen(arr1);
        len2=strlen(arr2);
        lcs=lcsf();
        cout<<lcs<<endl;
    }
    return 0;
}
