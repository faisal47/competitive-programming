#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;
#define inf 1<<29
map<int,int>m;
int dist[103][103],vertices;
void init()
{
    int i,j;
    for(i=1; i<=100; i++)
        for(j=1; j<=100; j++)
        {
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=inf;
        }
    return;
}
void fw()
{
    int i,j,k;
    for(k=1; k<=vertices; k++)
        for(i=1; i<=vertices; i++)
            for(j=1; j<=vertices; j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    return;
}
int main ()
{
    int a,b,i,j,test=1;
    double average,number;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)
            break;
        m.clear();
        vertices=1;
        average=0;
        init();
        if(m.find(a)==m.end())
            m[a]=vertices++;
        if(m.find(b)==m.end())
            m[b]=vertices++;
        dist[m[a]][m[b]]=1;
        while(cin>>a>>b)
        {
            if(a==0&&b==0)
                break;
            if(m.find(a)==m.end())
                m[a]=vertices++;
            if(m.find(b)==m.end())
                m[b]=vertices++;
            dist[m[a]][m[b]]=1;
        }
        vertices--;
        fw();
        number=((double)vertices*(double)vertices)-(double)vertices;
        for(i=1; i<=vertices; i++)
            for(j=1; j<=vertices; j++)
            {
                if(dist[i][j]<inf&&i!=j)
                    average+=(double)dist[i][j];
            }
        average/=number;
        printf("Case %d: average length between pages = %.3lf clicks\n",test++,average);
    }
    return 0;
}
