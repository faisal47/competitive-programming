#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
bool color[105][105];
char arr[105][105],z;
int mlomba,mpash,dist[105][105];
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
                if(color[a][b]==0)
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
int main ()
{
    int test,i,j,a,b,k,mjayga1[10]= {-2,-2,-1,1,2,2,1,-1},mjayga2[10]= {-1,1,2,2,-1,1,-2,-2};
    cin>>test;
    while(test--)
    {
        memset(dist,0,sizeof(dist));
        memset(color,0,sizeof(color));
        cin>>mlomba>>mpash;
        scanf("%c",&z);
        for(i=0; i<mlomba; i++)
            gets(arr[i]);
        for(i=0; i<mlomba; i++)
            for(j=0; j<mpash; j++)
            {
                if(arr[i][j]=='Z')
                {
                    color[i][j]=1;
                    for(k=0; k<8; k++)
                    {
                        a=i+mjayga1[k];
                        b=j+mjayga2[k];
                        if(a>=0&&b>=0&&a<mlomba&&b<mpash)
                        {
                            if(color[a][b]==0&&arr[a][b]=='.')
                                color[a][b]=1;
                        }
                    }
                }
            }
        for(i=0; i<mlomba; i++)
            for(j=0; j<mpash; j++)
            {
                if(arr[i][j]=='A')
                {
                    bfs(i,j);
                    break;
                }
            }
    }
    return 0;
}
