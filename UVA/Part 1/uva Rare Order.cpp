#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int current_time;
bool flag[100],check[100],check_another[100][100];
vector<int>v[100];
struct res
{
    int i,time;
};
vector<res>result;
res res1;
bool comp(res a,res b)
{
    return a.time>b.time;
}
void dfs(int start)
{
    int i;
    if(flag[start]==0)
    {
       // cout<<start<<endl;
        flag[start]=1;
        current_time++;
        for(i=0;i<v[start].size();i++)
        dfs(v[start][i]);
       res1.i=start;
       res1.time=current_time;
       result.push_back(res1);
       current_time++;
    }
    return;
}
int main ()
{
    //result.clear();
//    memset(check,0,sizeof(check));
//    memset(check_another,0,sizeof(check_another));
//    memset(flag,0,sizeof(flag));
    char arr[100],a,b;
    int i,len;
    while(gets(arr))
    {
        if(arr[0]=='#')
        break;
        len=strlen(arr);
        for(i=0;i<len-1;i++)
        {
          a=arr[i];
          b=arr[i+1];
          if(check_another[(int)a][(int)b]==0&&a!=b)
          {
              check[(int)a]=check[(int)b]=1;
            check_another[(int)a][(int)b]=1;
              v[(int)a].push_back((int)b);
             // cout<<a<<" "<<b<<endl;
          }
        }
    }
//    for(i='A';i<='Z';i++)
//    cout<<check[i]<<endl;
    current_time=0;
    for(i='A';i<='Z';i++)
    if(flag[i]==0&&check[i]==1)
    {
        dfs(i);
       // cout<<i<<endl;
        current_time--;
    }
    sort(result.begin(),result.end(),comp);
    for(i=result.size()-1;i>=0;i--)
    printf("%c",result[i].i);
    cout<<endl;
    return 0;
}
