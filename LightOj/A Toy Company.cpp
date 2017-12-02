#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define pri1(a) printf("%d ",a)
#define pri2(a,b) printf("%d %d ",a,b)
#define prll1(a) printf("%I64d ",a)
#define prll2(a,b) printf("%I64d %I64d ",a,b)
#define sz(a) a.size()
using namespace std;
map<string,bool>m;
map<string,int>m1;
string s,e,temp,a,b,c;
int n,ans;
bool check(string emne)
{
    if(emne==e)return 1;
    return 0;
}
bool map_check(string emne)
{
    if(m1.find(emne)==m1.end())
    {
        return 0;
    }
    return 1;
}
char bamchar(char emne)
{
    if(emne=='a')return 'z';
    return emne-1;
}
char danchar(char emne)
{
    if(emne=='z')return 'a';
    return emne+1;
}
bool forbidden(string emne)
{
    if(m.find(emne)==m.end())return 0;
    return 1;
}
int bfs()
{
    if(forbidden(s))return -1;
    clr(m1);
    m1[s]=1;
    ans=0;
    if(s==e)return ans;
    queue<string>q;
    q.push(s);
    m1[s]=0;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        ans=m1[a]+1;
        temp=bamchar(a[0]);
        temp+=a[1];
        temp+=a[2];
        // cout<<" temp== "<<temp<<endl;
        if(!forbidden(temp))
        {
            if(check(temp))return ans;
            if(!map_check(temp))
            {
                q.push(temp);
                m1[temp]=ans;
            }
        }
        temp=danchar(a[0]);
        temp+=a[1];
        temp+=a[2];
        //cout<<" temp== "<<temp<<endl;
        if(!forbidden(temp))
        {
            if(check(temp))return ans;
            if(!map_check(temp))
            {
                q.push(temp);
                m1[temp]=ans;
            }
        }
        temp=a[0];
        temp+=bamchar(a[1]);
        temp+=a[2];
        // cout<<" temp== "<<temp<<endl;
        if(!forbidden(temp))
        {
            if(check(temp))return ans;
            if(!map_check(temp))
            {
                q.push(temp);
                m1[temp]=ans;
            }
        }
        temp=a[0];
        temp+=danchar(a[1]);
        temp+=a[2];
        //cout<<" temp== "<<temp<<endl;
        if(!forbidden(temp))
        {
            if(check(temp))return ans;
            if(!map_check(temp))
            {
                q.push(temp);
                m1[temp]=ans;
            }
        }
        temp=a[0];
        temp+=a[1];
        temp+=bamchar(a[2]);
        //cout<<" temp== "<<temp<<endl;
        if(!forbidden(temp))
        {
            if(check(temp))return ans;
            if(!map_check(temp))
            {
                q.push(temp);
                m1[temp]=ans;
            }
        }
        temp=a[0];
        temp+=a[1];
        temp+=danchar(a[2]);
        //cout<<" temp== "<<temp<<endl;
        if(!forbidden(temp))
        {
            if(check(temp))return ans;
            if(!map_check(temp))
            {
                q.push(temp);
                m1[temp]=ans;
            }
        }
    }
    return -1;
}
int main ()
{
    int test,t=1,i,j,k;
    sci1(test);
    while(test--)
    {
        cin>>s>>e;
        sci1(n);
        clr(m);
        while(n--)
        {
            cin>>a>>b>>c;
            for(i=0; i<sz(a); i++)
                for(j=0; j<sz(b); j++)
                    for(k=0; k<sz(c); k++)
                    {
                        temp=a[i];
                        temp+=b[j];
                        temp+=c[k];
                        //cout<<"main map er a,b,c,== "<<a[i]<<" "<<b[j]<<" "<<c[k]<<" "<<temp<<endl;
                        m[temp]=1;
                    }
        }
        printf("Case %d: %d\n",t++,bfs());
    }
    return 0;
}
