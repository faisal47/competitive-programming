#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define sci1(a) scanf("%d",&a)
#define sz(a) a.size()
using namespace std;
struct tri
{
    bool end;
    int flag[11];
    tri()
    {
        ms(flag,-1);
        end=0;
    }
}trie[100100];
string st;
int pnode_n;
bool make_trie(int node,int pos)
{
    if(trie[node].end)return 0;
    char ch=st[pos];
    if(pos== sz(st)-1)
    {
        if(trie[node].flag[ch-'0']!=-1)return 0;
        trie[node].flag[ch-'0']=pnode_n;
        trie[pnode_n]=tri();
        return trie[pnode_n++].end=1;
    }
    if(trie[node].flag[ch-'0']!=-1)
    return make_trie(trie[node].flag[ch-'0'],pos+1);
    trie[node].flag[ch-'0']=pnode_n;
    trie[pnode_n]=tri();
    return make_trie(pnode_n++,pos+1);
}
int main ()
{
    int i,n,test,t=1;
    bool break_flag;
    sci1(test);
    while(test--)
    {
        sci1(n);
        break_flag=0;
        pnode_n=0;
        trie[pnode_n++]=tri();
        for(i=0;i<n;i++)
        {
            cin>>st;
            if(!break_flag && !make_trie(0,0))
                    break_flag=1;
        }
        if(break_flag)
        printf("Case %d: NO\n",t++);
        else
        printf("Case %d: YES\n",t++);
    }
    return 0;
}

