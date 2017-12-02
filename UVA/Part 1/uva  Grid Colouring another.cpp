#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
void dfs(char arr[][1000],char b,int i,int j)
{
    if(arr[i][j]==' ')
    {
        arr[i][j]=b;
        dfs(arr,b,i,j+1);
        dfs(arr,b,i,j-1);
        dfs(arr,b,i-1,j);
        dfs(arr,b,i+1,j);
    }
    return;
}
int main ()
{
    char arr[500][1000],a,b;
    int len,i=0,j,lomba,pash,flag;
    while(gets(arr[i]))
    {
        len=strlen(arr[i]);
        if(arr[i][0]=='_'&&arr[i][len-1])
        {
            flag=0;
            ++i;
            lomba=i;
            for(i=0;i<lomba-1;i++)
            {
                len=strlen(arr[i]);
                for(j=0;j<len;j++)
                {
                    if(flag==0&&arr[i][j]!=' ')
                    {
                       a=arr[i][j];
                       flag=1;
                    }
                    else
                    {
                      if(arr[i][j]!=' '&&arr[i][j]!=a)
                      {
                          b=arr[i][j];
                          arr[i][j]=' ';
                          dfs(arr,b,i,j);
                      }
                    }
                }
            }
            for(i=0;i<lomba;i++)
            cout<<arr[i]<<endl;
            i=0;
        }
        else
        i++;
    }
    return 0;
}
