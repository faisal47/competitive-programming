#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int count;
void bfs(int arr[][26],int n,int i,int j)
{
    if(arr[i][j]==1&&i<n&&j<n&&i>-1&&j>-1)
    {
            arr[i][j]=0;
        bfs(arr,n,i,j-1);
        bfs(arr,n,i-1,j-1);
        bfs(arr,n,i-1,j);
        bfs(arr,n,i-1,j+1);
        bfs(arr,n,i,j+1);
        bfs(arr,n,i+1,j+1);
        bfs(arr,n,i+1,j);
        bfs(arr,n,i+1,j-1);
    }
    return;
}
int main ()
{
    int arr[26][26],test=0,i,j,n,len;
    char string[30],z;
    while((scanf("%d",&n))==1)
    {
        scanf("%c",&z);
        count=0;
        for(i=0;i<n;i++)
        {
            gets(string);
            len=strlen(string);
            for(j=0;j<len;j++)
            {
                if(string[j]=='0')
                arr[i][j]=0;
                else
                arr[i][j]=1;
            }
        }
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(arr[i][j]==1)
            {
                count++;
                bfs(arr,n,i,j);
            }
        }
        printf("Image number %d contains %d war eagles.\n",++test,count);
    }
    return 0;
}
