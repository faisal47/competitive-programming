#include <iostream>
#include <stdio.h>
using namespace std;
int count=0;
void dfs(char arr[][200],int i,int j,int m,int n)
{
    if(i>-1&&j>-1&&i<m&&j<n)
    {
        if(arr[i][j]=='*')
        {
            count++;
            arr[i][j]='.';
            dfs(arr,i,j-1,m,n);
            dfs(arr,i,j+1,m,n);
            dfs(arr,i+1,j-1,m,n);
            dfs(arr,i+1,j,m,n);
            dfs(arr,i+1,j+1,m,n);
            dfs(arr,i-1,j-1,m,n);
            dfs(arr,i-1,j,m,n);
            dfs(arr,i-1,j+1,m,n);
        }
    }
    return;
}
int main ()
{
    int m,n,i,j,k;
    char a,arr[200][200];
    while((scanf("%d %d%c",&m,&n,&a))==3)
    {
        if(m==0&&n==0)
        break;
        k=0;
        for(i=0;i<m;i++)
        gets(arr[i]);
        for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        if(arr[i][j]=='*')
        {
            count=0;
            dfs(arr,i,j,m,n);
            if(count==1)
            ++k;
        }
        cout<<k<<endl;
    }
    return 0;
}
