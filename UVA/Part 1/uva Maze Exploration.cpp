#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
void dfs(char arr[][100],int i,int j,int lomba,int len)
{
    len=strlen(arr[i]);
    if(i>-1&&j>-1&&i<lomba&&j<len)
    {
        if(arr[i][j]==' ')
        {
            arr[i][j]='#';
            dfs(arr,i-1,j,lomba,len);
            dfs(arr,i+1,j,lomba,len);
            dfs(arr,i,j-1,lomba,len);
            dfs(arr,i,j+1,lomba,len);
        }
    }
    return;
}
int main ()
{
    char arr[50][100],a;
    int test,i,len,lomba,flag,j;
    scanf("%d",&test);
    scanf("%c",&a);
    while(test--)
    {
        i=flag=0;
        while(gets(arr[i]))
        {
            len=strlen(arr[i]);
            if(arr[i][0]=='_'&&arr[i][len-1]=='_')
                break;
                ++i;
        }
        lomba=i+1;
        for(i=0; i<lomba-1; i++)
        {
            len=strlen(arr[i]);
            for(j=0; j<len; j++)
            {
                if(arr[i][j]!=' '&&flag==0)
                {
                    a=arr[i][j];
                    flag=1;
                }
                else if(arr[i][j]!=a&&arr[i][j]!=' ')
                {
                    arr[i][j]=' ';
                    dfs(arr,i,j,lomba,len);
                }
            }
        }
        for(i=0; i<lomba; i++)
            cout<<arr[i]<<endl;
    }
    return 0;
}
