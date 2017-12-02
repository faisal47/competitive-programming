#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;
vector<int>v[500];
vector<int>output;
int flag,parents[1000];
bool flag1[1000];
void bfs(int start,int end)
{
    queue<int>q;
    q.push(start);
    int i;
    flag1[start]=1;
    while(!q.empty())
    {
        start=q.front();
        q.pop();
        for(i=0;i<v[start].size();i++)
        {
           if(flag1[v[start][i]]==0)
           {
              flag1[v[start][i]]=1;
              q.push(v[start][i]);
              parents[v[start][i]]=start;
              if(v[start][i]==end)
              {
                  flag=1;
                  return;
              }
           }
        }
    }
    return;
}
int main ()
{
    char z,arr[1000000],*ptr;
    int test,i,j,c,start,end,k;
    while(scanf("%d",&test)==1)
    {
        scanf("%c",&z);
        for(i=1; i<=test; i++)
        {
            gets(arr);
            ptr = strtok (arr,",- ");
            c=atoi(ptr);
            while (ptr != NULL)
            {
                ptr = strtok (NULL," ,-");
                j=atoi(ptr);
                if(j!=0)
                v[c].push_back(j);
            }
        }
        c=test;
        cin>>test;
        cout<<"-----"<<endl;
        for(k=1;k<=test;k++)
        {
            cin>>start>>end;
            flag=0;
            memset(flag1,0,sizeof(flag1));
            parents[start]=start;
            bfs(start,end);
            if(flag==0)
            cout<<"connection impossible"<<endl;
            else
            {
                output.clear();
                output.push_back(end);
                i=end;
                while(1)
                {
                    output.push_back(parents[i]);
                    i=parents[i];
                    if(i==start)
                        break;
                }
                for(i=output.size()-1;i>=0;i--)
                {
                    cout<<output[i];
                    if(i)
                    cout<<" ";
                }
                cout<<endl;
            }
        }
        for(i=1;i<=300;i++)
            v[i].clear();
    }
    return 0;
}
