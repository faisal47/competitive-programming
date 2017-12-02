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
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sz(a) a.size()
#define mt 1010
using namespace std;
vec_<int>v[mt];
bool col[mt];
int taka[mt],mot_taka,mot_jon,s1;
queue<int>q;
int bfs(int s)
{
    q.push(s);
    col[s]=1;
    int i;
    mot_jon=1;
    mot_taka=taka[s];
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(i=0; i<sz(v[s]); i++)
        {
            s1=v[s][i];
            if(!col[s1])
            {
                mot_jon++;
                col[s1]=1;
                mot_taka+=taka[s1];
                q.push(s1);
            }
        }
    }
}
int main ()
{
    int i,j,n,m,test,t=1,avg,thakbe,mot_taka_final;
    bool flag;
    sci1(test);
    while(test--)
    {
        mot_taka_final=0;
        sci2(n,m);
        for(i=1; i<=n; i++)
        {
            clr(v[i]);
            col[i]=0;
            sci1(taka[i]);
            mot_taka_final+=taka[i];
        }
        thakbe=mot_taka_final/n;
        while(m--)
        {
            sci2(i,j);
            v[i].pb(j);
            v[j].pb(i);
        }
        printf("Case %d: ",t++);
        if(thakbe*n != mot_taka_final)
        {
            cout<<"No\n";
            continue;
        }
        flag=true;
        for(i=1; i<=n; i++)
        {
            if(!col[i])
            {
                bfs(i);
                avg=mot_taka/mot_jon;
                if(avg*mot_jon != mot_taka ||avg!=thakbe)
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}

