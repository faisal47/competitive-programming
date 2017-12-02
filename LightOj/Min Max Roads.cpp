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
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define eps 1E-7
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scll1(a) scanf("%lld",&a)
#define scll2(a,b) scanf("%lld %lld",&a,&b)
#define scll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scd1(a) scanf("%lf",&a)
#define scd2(a,b) scanf("%lf %lf",&a,&b)
#define scd3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define sz 100010
using namespace std;
int n,a,b,c,ansmaxi,ansmini;
struct node
{
    int b,c;
};
vec_ <node>nodes[sz];
bool col[sz];
int h,i,j,test,t=1,distmaxi[sz][20],pare[sz][20],distmini[sz][20],L[sz];
void dfs(int e)
{
    int i1,f;
    for(i1=0; i1<nodes[e].size(); i1++)
    {
        f=nodes[e][i1].b;
        if(!col[f])
        {
            col[f]=1;
            L[f]=L[e]+1;
            pare[f][0]=e;
            distmaxi[f][0]=nodes[e][i1].c;
            distmini[f][0]=nodes[e][i1].c;
            dfs(f);
        }
    }
}
void pp()
{
    L[1]=0;
    pare[1][0]=-1;
    col[1]=1;
    dfs(1);
    for(h=1; (1<<h)<n; h++);
    h--;
    for(j=1;j<=h;j++)
    for(i=1;i<=n;i++)
    if(pare[i][j-1]!=-1)
    {
        pare[i][j]=pare[pare[i][j-1]][j-1];
        distmaxi[i][j]=max(distmaxi[i][j-1],distmaxi[pare[i][j-1]][j-1]);
        distmini[i][j]=min(distmini[i][j-1],distmini[pare[i][j-1]][j-1]);
    }
}
void query()
{
    ansmaxi=-1;
    ansmini=inf;
    if(L[a]<L[b])
    swap(a,b);
    for(h=1;(1<<h)<=L[a];h++);h--;
    for(i=h;i>=0;i--)
    {
        if((L[a]-(1<<i))>=L[b])
        {
            ansmaxi=max(ansmaxi,distmaxi[a][i]);
            ansmini=min(ansmini,distmini[a][i]);
            a=pare[a][i];
        }
    }
    if(a==b)
    {
       // cout<<"jd"<<endl;
        return;
    }
    for(i=h;i>=0;i--)
    if(pare[a][i]!=pare[b][i] && pare[a][i]!=-1 && pare[b][i]!=-1)
    {
        ansmaxi=max(ansmaxi,max(distmaxi[b][i],distmaxi[a][i]));
        ansmini=min(ansmini,min(distmini[b][i],distmini[a][i]));
        a=pare[a][i];
        b=pare[b][i];
    }
    ansmaxi=max(ansmaxi,max(distmaxi[b][0],distmaxi[a][0]));
        ansmini=min(ansmini,min(distmini[b][0],distmini[a][0]));
}
int main ()
{
    int q;
    sci1(test);
    while(test--)
    {
        sci1(n);
        for(i=1; i<=n; i++)
        {
            col[i]=0;
            for(j=0; j<20; j++)
            {
//                distmaxi[i][j]=-1;
//                distmini[i][j]=-1;
                pare[i][j]=-1;
            }
            clr(nodes[i]);
        }
        for(i=1; i<=n-1; i++)
        {
            sci3(a,b,c);
            nodes[a].pb( {b,c});
            nodes[b].pb( {a,c});
        }
        pp();
        sci1(q);
        printf("Case %d:\n",t++);
        while(q--)
        {
            sci2(a,b);
            query();
            printf("%d %d\n",ansmini,ansmaxi);
        }
    }
    return 0;
}

