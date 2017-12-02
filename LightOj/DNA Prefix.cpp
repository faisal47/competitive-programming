#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define sci1(a) scanf("%d",&a)
#define sz(a) a.size()
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
using namespace std;
struct tri
{
    int arr[4][2];
    tri()
    {
        ms(arr,-1);
    }
};
vec_<tri>trie;
tri a;
map<char,int>ma;
int nodes,ans;
string st;
void make_trie(int node,int pos)
{
    char temp=st[pos];
    if(pos == sz(st)-1)
    {
        if(trie[node].arr[ma[temp]][0]!=-1)
        {
            trie[node].arr[ma[temp]][1]++;
            ans=max(ans,(pos+1)*trie[node].arr[ma[temp]][1]);
            return;
        }
        trie[node].arr[ma[temp]][0]=nodes;
        trie[node].arr[ma[temp]][1]=1;
        ans=max(ans,pos+1);
        trie.pb(a);nodes++;
        return;
    }
    if(trie[node].arr[ma[temp]][0]!=-1)
    {
        trie[node].arr[ma[temp]][1]++;
        ans=max(ans,(pos+1)*trie[node].arr[ma[temp]][1]);
        make_trie(trie[node].arr[ma[temp]][0],pos+1);
    }
    else
    {
        trie[node].arr[ma[temp]][0]=nodes;
        trie[node].arr[ma[temp]][1]=1;
        ans=max(ans,pos+1);
        trie.pb(a);nodes++;
        make_trie(trie[node].arr[ma[temp]][0],pos+1);
    }
}
int main ()
{
    ma['A']=0;
    ma['T']=1;
    ma['C']=2;
    ma['G']=3;
    int n,test,t=1,i;
    a=tri();
    sci1(test);
    while(test--)
    {
        sci1(n);
        nodes=ans=0;
        clr(trie);
        nodes++;
        trie.pb(a);
        for(i=1;i<=n;i++)
        {
            cin>>st;
            make_trie(0,0);
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

