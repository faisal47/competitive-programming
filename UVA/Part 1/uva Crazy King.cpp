#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
char arr[105][105],z;
int mpash,mlomba,dist[105][105];
bool color[105][105];
void bfs(int i,int j)
{
    int flag=0,a,b,k,mjayga1[10]= {-1,-1,-1,0,1,1,1,0},mjayga2[10]= {-1,0,1,1,1,0,-1,-1};
    queue<int>Q;
    Q.push(i);
    Q.push(j);
    color[i][j]=1;
    while(!Q.empty())
    {
        i=Q.front();
        Q.pop();
        j=Q.front();
        Q.pop();
        for(k=0; k<8; k++)
        {
            a=i+mjayga1[k];
            b=j+mjayga2[k];
            if(a>=0&&b>=0&&a<mlomba&&b<mpash)
            {
                if(color[a][b]==0&&arr[a][b]!='Z')
                {
                    color[a][b]=1;
                    dist[a][b]=dist[i][j]+1;
                    if(arr[a][b]=='B')
                    {
                        flag=1;
                        break;
                    }
                    Q.push(a);
                    Q.push(b);
                }
            }
        }
        if(flag==1)
            break;
    }
    if(flag==1)
        printf("Minimal possible length of a trip is %d\n",dist[a][b]);
    else
        cout<<"King Peter, you can't go now!"<<endl;
    return;
}
void dfs(int i,int j)
{
    if(i>=0&&j>=0&&i<mlomba&&j<mpash)
    {
        if(arr[i][j]=='.')
        {
            arr[i][j]='Z';
            dfs(i-2,j-1);
            dfs(i-2,j+1);
            dfs(i+2,j-1);
            dfs(i+2,j+1);
            dfs(i-1,j+2);
            dfs(i+1,j+2);
            dfs(i-1,j-2);
            dfs(i+1,j-2);
        }
    }
    return;
}
int main ()
{
    int test,i,j;
    cin>>test;
    while(test--)
    {
        memset(color,0,sizeof(color));
        memset(dist,0,sizeof(dist));
        cin>>mlomba>>mpash;
        scanf("%c",&z);
        for(i=0; i<mlomba; i++)
            gets(arr[i]);
        for(i=0; i<mlomba; i++)
            for(j=0; j<mpash; j++)
            {
                if(arr[i][j]=='Z')
                {
                    arr[i][j]='.';
                    dfs(i,j);
                }
            }
        for(i=0; i<mlomba; i++)
            for(j=0; j<mpash; j++)
            {
                if(arr[i][j]=='A')
                    bfs(i,j);
                break;
            }
    }
    return 0;
}
