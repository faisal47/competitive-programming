#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
vector<int>v[30];
bool color[30];
int count;
void bfs(int j)
{
    int a,i;
    queue<int>q;
    q.push(j);
    color[j]=1;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        for(i=0;i<v[a].size();i++)
        {
            if(color[v[a][i]]==0)
            {
                color[v[a][i]]=1;
                q.push(v[a][i]);
            }
        }
    }
    return;
}
int main ()
{
    char arr[30],z;
    int j,i,test,a,b,m;
    scanf("%d",&test);
    scanf("%c",&z);
    scanf("%c",&z);
    for(i=0;i<test;i++)
    {
        if(i!=0)
        cout<<endl;
        gets(arr);
        count=0;
        memset(color,0,sizeof(color));
        m=(arr[0]-'A')+1;
        for(j=1;j<=m;j++)
        v[j].clear();
        while(gets(arr))
        {
            if(strlen(arr)==0)
            break;
            a=(arr[0]-'A')+1;
            b=(arr[1]-'A')+1;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(j=1;j<=m;j++)
        {
            if(color[j]==0)
            {
                bfs(j);
                count++;
            }
        }
        cout<<count<<endl;
    }
}
