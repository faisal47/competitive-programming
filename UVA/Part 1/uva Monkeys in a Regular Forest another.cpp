#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
bool color[1000][1000];
char arr[1000][1000],ch;
int count,arr1[1000][1000];
void dfs(int i,int j,int m,int n)
{
    if(i>=0&&j>=0&&i<m&&j<n)
    {
        if(color[i][j]==0&&arr[i][j]==ch)
        {
            arr1[i][j]=count;
            color[i][j]=1;
            dfs(i-1,j,m,n);
            dfs(i+1,j,m,n);
            dfs(i,j-2,m,n);
            dfs(i,j+2,m,n);
            dfs(i-1,j+2,m,n);
            dfs(i-1,j-2,m,n);
            dfs(i+1,j-2,m,n);
            dfs(i+1,j+2,m,n);
        }
    }
    return;
}
int main ()
{
    int m,c=0,len,i,j,flag[1000];
    while(gets(arr[c++]))
    {
        if(arr[c-1][0]=='%')
        {
            count=0;
            memset(color,0,sizeof(color));
            memset(flag,0,sizeof(flag));
            len=strlen(arr[c-2]);
            for(i=0; i<c-1; i++)
                for(j=0; j<len; j++)
                {
                    if(color[i][j]==0&&arr[i][j]!=' ')
                    {
                        count++;
                        ch=arr[i][j];
                        dfs(i,j,c-1,len);
                    }
                }
            for(i=0; i<len; i+=2)
            {
                for(j=0; j<c-1; j++)
                {
                    if(arr[j][i]!=' ')
                    {
                        if(flag[i]<arr1[j][i])
                            flag[i]=arr1[j][i];
                    }
                }
                if(flag[i]<10)
                    flag[i]=1;
                else if(flag[i]<100)
                    flag[i]=2;
                else if(flag[i]<1000)
                    flag[i]=3;
                else if(flag[i]<10000)
                    flag[i]=4;
            }
            for(i=0; i<c-1; i++)
            {
                for(j=0; j<len; j++)
                {
                    if(arr[i][j]!=' ')
                    {
                        if(flag[j]==1)
                            cout<<arr1[i][j];
                        else if(flag[j]==2)
                            printf("%2d",arr1[i][j]);
                        else if(flag[j]==3)
                            printf("%3d",arr1[i][j]);
                        else if(flag[j]==4)
                            printf("%4d",arr1[i][j]);
                    }
                    else
                        cout<<arr[i][j];
                }
                cout<<endl;
            }
            cout<<"%"<<endl;
            c=0;
        }
    }
    count=0;
    memset(color,0,sizeof(color));
    len=strlen(arr[c-2]);
    for(i=0; i<c-1; i++)
        for(j=0; j<len; j++)
        {
            if(color[i][j]==0&&arr[i][j]!=' ')
            {
                count++;
                ch=arr[i][j];
                dfs(i,j,c-1,len);
            }
        }
    memset(flag,0,sizeof(flag));
    for(i=0; i<len; i+=2)
    {
        for(j=0; j<c-1; j++)
        {
            if(arr[j][i]!=' ')
            {
                if(flag[i]<arr1[j][i])
                    flag[i]=arr1[j][i];
            }
        }
        if(flag[i]<10)
            flag[i]=1;
        else if(flag[i]<100)
            flag[i]=2;
        else if(flag[i]<1000)
            flag[i]=3;
        else if(flag[i]<10000)
            flag[i]=4;
    }
    for(i=0; i<c-1; i++)
    {
        for(j=0; j<len; j++)
        {
            if(arr[i][j]!=' ')
            {
                if(flag[j]==1)
                    cout<<arr1[i][j];
                else if(flag[j]==2)
                    printf("%2d",arr1[i][j]);
                else if(flag[j]==3)
                    printf("%3d",arr1[i][j]);
                else if(flag[j]==4)
                    printf("%4d",arr1[i][j]);
            }
            else
                cout<<arr[i][j];
        }
        cout<<endl;
    }
    cout<<"%"<<endl;
    return 0;
}
