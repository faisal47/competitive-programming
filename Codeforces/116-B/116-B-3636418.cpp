#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <queue>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define ll long long
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define eps 1E-7
#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz 15
using namespace std;
//struct data
//{
// int cost,node;
// bool operator <(const data &p)const
// {
// return cost >p.cost;
// }
//}
//ll bigmod (ll a, ll b,ll m)
//{
// if(b==0)
// return 1%m;
// ll x=bigmod(a,b/2,m);
// x=(x*x)%m;
// if(b%2==1)
// x=(x*a)%m;
// return x;
//}
ll gcd(ll a,ll b)
{
if(b==0)
return a;
return gcd(b,a%b);
}
bool color[110];
ll n,m,mot;
vec_ <ll>v[110];
ll par[110],ans,i,j;
bool dfs(ll node)
{
int asi;
for(int p=0; p<v[node].size(); p++)
{
asi=v[node][p];
if(color[asi]==0)
{
color[asi]=1;
if(par[asi]==-1 || dfs(par[asi]))
{
par[asi]=node;
return true;
}
}
}
return false;
}
ll bpm()
{
ans=0;
for(i=0; i<mot; i++)
{
for(j=0; j<mot; j++)
color[j]=0;
if(dfs(i))
ans++;
}
return ans;
}
int main ()
{
string arr[15];
ll x,y;
ll c1,c2,number[15][15];
while(cin>>n>>m)
{
mot=n*m;
for(i=0; i<mot; i++)
{
clr(v[i]);
par[i]=-1;
}
c1=c2=1;
for(i=0; i<n; i++)
cin>>arr[i];
for(i=0; i<n; i++)
for(j=0; j<m; j++)
if(arr[i][j]=='W')
{
number[i][j]=c1++;
}
else if(arr[i][j]=='P')
{
number[i][j]=c2++;
}
for(i=0; i<n; i++)
for(j=0; j<m; j++)
if(arr[i][j]=='W')
{
x=i-1;
y=j;
if(x>=0 && x<n && y>=0 && y<m && arr[x][y]=='P')
{
v[number[i][j]].pb(number[x][y]);
}
x=i+1;
y=j;
if(x>=0 && x<n && y>=0 && y<m && arr[x][y]=='P')
{
v[number[i][j]].pb(number[x][y]);
}
x=i;
y=j-1;
if(x>=0 && x<n && y>=0 && y<m && arr[x][y]=='P')
{
v[number[i][j]].pb(number[x][y]);
}
x=i;
y=j+1;
if(x>=0 && x<n && y>=0 && y<m && arr[x][y]=='P')
{
v[number[i][j]].pb(number[x][y]);
}
}
cout<<bpm()<<endl;
}
return 0;
}