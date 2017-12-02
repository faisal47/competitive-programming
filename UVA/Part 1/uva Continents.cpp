#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
bool color[25][25];
char arr[25][25],c;
int count;
void dfs(int a,int b,int m,int n)
{
    if(arr[a][b]==c&&color[a][b]==0&&a>=0&&a<m)
    {
        color[a][b]=1;
        dfs(a-1,b,m,n);
        dfs(a+1,b,m,n);
        if(b==(n-1))
            dfs(a,0,m,n);
        else
            dfs(a,b+1,m,n);
        if(b==0)
            dfs(a,n-1,m,n);
        else
            dfs(a,b-1,m,n);
    }
    return;
}
void dfs1(int a,int b,int m,int n)
{
    if(arr[a][b]==c&&color[a][b]==0&&a>=0&&a<m)
    {
        color[a][b]=1;
        count++;
        dfs1(a-1,b,m,n);
        dfs1(a+1,b,m,n);
        if(b==(n-1))
            dfs1(a,0,m,n);
        else
            dfs1(a,b+1,m,n);
        if(b==0)
            dfs1(a,n-1,m,n);
        else
            dfs1(a,b-1,m,n);
    }
    return;
}
int main ()
{
    char z,test[10];
    int i,len,flag,a,b,j,m,n,max;
    while(cin>>m>>n)
    {
        scanf("%c",&z);
        max=0;
        for(i=0; i<m; i++)
            gets(arr[i]);
        gets(test);
        memset(color,0,sizeof(color));
        len=strlen(test);
        if(len==0)
            break;
        a=b=flag=0;
        for(i=0; i<len; i++)
        {
            if(test[i]==' ')
                flag=1;
            else if(flag==0)
                a=((a*10)+(test[i]-'0'));
            else
                b=((b*10)+(test[i]-'0'));
        }
        c=arr[a][b];
        dfs(a,b,m,n);
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
            {
                count=0;
                if(arr[i][j]==c&&color[i][j]==0)
                    dfs1(i,j,m,n);
                    if(max<count)
                    max=count;
            }
        cout<<max<<endl;
        gets(test);
    }
    return 0;
}
