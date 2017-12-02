#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char arr[25][25],z;
bool color[25][25];
int count;
void dfs(int i,int j, int lomba,int pash)
{
    if(i>=0&&j>=0&&i<lomba&&j<pash)
    {
        if(arr[i][j]=='.'&&color[i][j]==0)
        {
            count++;
            color[i][j]=1;
            dfs(i-1,j,lomba,pash);
            dfs(i+1,j,lomba,pash);
            dfs(i,j-1,lomba,pash);
            dfs(i,j+1,lomba,pash);
        }
    }
    return;
}
int main ()
{
    int test,flag,i,j,k,w,h;
    cin>>test;
    for(i=1; i<=test; i++)
    {
        flag=0;
        scanf("%d %d",&w,&h);
        scanf("%c",&z);
        for(j=0; j<h; j++)
            gets(arr[j]);
        for(k=0; k<h; k++)
        {
            for(j=0; j<w; j++)
            {
                if(arr[k][j]=='@')
                {
                    flag=1;
                    count=0;
                    memset(color,0,sizeof(color));
                    arr[k][j]='.';
                    dfs(k,j,h,w);
                    break;
                }
            }
            if(flag==1)
            break;
        }
        printf("Case %d: %d\n",i,count);
    }
    return 0;
}
