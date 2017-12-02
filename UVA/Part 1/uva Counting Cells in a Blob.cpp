#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int count;
void bfs(int arr[][26],int len,int i,int j)
{
    if(i<len&&j<len&&i>-1&&j>-1)
    {
        if(arr[i][j]==1)
        {
            ++count;
            arr[i][j]=0;
            bfs(arr,len,i,j-1);
            bfs(arr,len,i-1,j-1);
            bfs(arr,len,i-1,j);
            bfs(arr,len,i-1,j+1);
            bfs(arr,len,i,j+1);
            bfs(arr,len,i+1,j+1);
            bfs(arr,len,i+1,j);
            bfs(arr,len,i+1,j-1);
        }
    }
    return;
}
int main ()
{
    char arr[28],z;
    int arr1[26][26],test,i,len,j,k,max;
    scanf("%d",&test);
    scanf("%c",&z);
    for(i=0; i<test; i++)
    {
        if(i)
        cout<<endl;
        memset(arr1,0,sizeof(arr1));
        max=0;
        gets(arr);
        len=strlen(arr);
        for(j=0; j<len; j++)
            arr1[0][j]=(arr[j]-'0');
        for(j=1; j<len; j++)
        {
            gets(arr);
            for(k=0; k<len; k++)
                arr1[j][k]=(arr[k]-'0');
        }
        for(j=0;j<len;j++)
        for(k=0;k<len;k++)
        {
            if(arr1[j][k]==1)
            {
                count=0;
                bfs(arr1,len,j,k);
                if(max<count)
                max=count;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}
