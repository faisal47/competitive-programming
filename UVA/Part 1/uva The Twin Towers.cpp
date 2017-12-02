#include <stdio.h>
#include <iostream>
using namespace std;
int arr1[105],arr2[105],c[105][105],m,n;
int lcsf(void)
{
    int i,j;
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    if(arr1[i]==arr2[j])
    c[i][j]=c[i-1][j-1]+1;
    else
    c[i][j]=max(c[i-1][j],c[i][j-1]);
    return c[m][n];
}
int main ()
{
    int i,lcs,t=1;
    while(cin>>m>>n)
    {
        if(m==0&&n==0)
        break;
        for(i=1;i<=m;i++)
        cin>>arr1[i];
        for(i=1;i<=n;i++)
        cin>>arr2[i];
        lcs=lcsf();
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",t++,lcs);
    }
    return 0;
}
