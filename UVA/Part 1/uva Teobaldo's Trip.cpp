#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int>v[102];
int dp[105][205],b,d1,f,e;
int call(int c,int day)
{

    if(c==e && day==d1)
    {
        f=1;
        return 1;
    }
    if(dp[c][day]!=-1)
            return dp[c][day];
        int si=0;
    for(int i=0; i<v[c].size(); i++)
    {
        si=max(si,call(v[c][i],day+1));
        if(f==1)
            return 1;
    }
    return dp[c][day]=si;
}
int main ()
{
    int c,l,a,s;
    while(cin>>c>>l)
    {
        if(c==0&&l==0)
            break;
        for(a=1; a<=c; a++)
            v[a].clear();
        while(l--)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        f=0;
        cin>>s>>e>>d1;
        for(a=1; a<=c; a++)
            for(b=0; b<=d1; b++)
                dp[a][b]=-1;
        a=call(s,0);
        if(f)
            cout<<"Yes, Teobaldo can travel."<<endl;
        else
            cout<<"No, Teobaldo can not travel."<<endl;
    }
    return 0;
}
