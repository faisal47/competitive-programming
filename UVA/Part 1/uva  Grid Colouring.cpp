#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int colour[35][100];
void dfs(int colour[][100],char arr[][100],int i,int j,char a)
{
    if(arr[i][j]==' ')
    {
        if(colour[i][j]==0)
        {
            colour[i][j]=1;
            arr[i][j]=a;
            dfs(colour,arr,i,j-1,a);
            dfs(colour,arr,i-1,j-1,a);
            dfs(colour,arr,i-1,j,a);
            dfs(colour,arr,i-1,j+1,a);
            dfs(colour,arr,i,j+1,a);
            dfs(colour,arr,i+1,j+1,a);
            dfs(colour,arr,i+1,j,a);
            dfs(colour,arr,i+1,j-1,a);
        }
    }
    return;
}
int main ()
{
    char arr[35][100],a;
    int len,i,j,lomba=0;
    while(gets(arr[lomba]))
    {
        while(1)
        {
            if(arr[lomba][0]=='_')
                break;
            ++lomba;
            gets(arr[lomba]);
        }
        for(i=0; i<lomba-2; i++)
        {
            len=strlen(arr[i]);
            for(j=0; j<len; j++)
                if(arr[i][j]!='X'&&arr[i][j]!=' '&&colour[i][j]==0)
                {
                    a=arr[i][j];
                    arr[i][j]=' ';
                    dfs(colour,arr,i,j,a);
                }
        }
        for(i=0; i<lomba; i++)
            cout<<arr[i]<<endl;
        lomba=0;
        memset(colour,0,sizeof(colour));
    }
    return 0;
}
