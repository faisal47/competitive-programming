#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
vector<int>v[2510];
int rasta[2510];
bool flag[2510];
int count[2510];
void bfs(int start)
{
    int i;
    flag[start]=1;
   queue<int>q;
   q.push(start);
   while(!q.empty())
   {
       start=q.front();
       q.pop();
       for(i=0;i<v[start].size();i++)
       {
           if(flag[v[start][i]]==0)
           {
               flag[v[start][i]]=1;
               rasta[v[start][i]]=rasta[start]+1;
               q.push(v[start][i]);
           }
       }
   }
}
int main ()
{
    int a,i,test,friends,m,n;
    cin>>friends;
    for(i=0;i<friends;i++)
    {
        cin>>test;
        while(test--)
        {
            cin>>a;
            v[i].push_back(a);
        }
    }
    cin>>test;
    while(test--)
    {
        for(i=0;i<friends;i++)
        {
            flag[i]=0;
            rasta[i]=0;
            count[i]=0;
        }
        cin>>i;
        bfs(i);
        m=n=0;
        for(i=0;i<friends;i++)
        count[rasta[i]]++;
        for(i=1;i<friends;i++)
        if(m<count[i])
        {
            m=count[i];n=i;
        }
        if(m==0)
            cout<<"0"<<endl;
        else
        cout<<m<<" "<<n<<endl;
    }
    return 0;
}
