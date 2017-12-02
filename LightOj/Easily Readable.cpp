#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define sci1(a) scanf("%d",&a)
#define sz(a) a.size()
#define scch(a) scanf("%c",&a)
using namespace std;

struct tri
{
    int arr[52];
    int c;
    tri()
    {
        c=0;
        ms(arr,-1);
    }
} trie[80000];

char b[100010];
int nodes;
string a;
map<char,int>ma;
//char temp;

void make_trie(int node,int pos)
{
    char temp=a[pos];
    if(pos == sz(a)-1)
    {
        if(trie[node].arr[ma[temp]]!=-1)
            trie[trie[node].arr[ma[temp]]].c++;
        else
        {
            trie[node].arr[ma[temp]]=nodes;
            trie[nodes]=tri();
            trie[nodes++].c=1;
        }
        return;
    }

    if(trie[node].arr[ma[temp]]!=-1)
        make_trie(trie[node].arr[ma[temp]],pos+1);
    else
    {
        trie[node].arr[ma[temp]]=nodes;
        trie[nodes]=tri();
        make_trie(nodes++,pos+1);
    }

}

int find1(int node,int pos)
{
    char temp=a[pos];

    if(pos == sz(a)-1)
    {
        if(trie[node].arr[ma[temp]]==-1)return 0;
        return trie[trie[node].arr[ma[temp]]].c;
    }

    if(trie[node].arr[ma[temp]]==-1)return 0;

    return find1(trie[node].arr[ma[temp]],pos+1);
}

int main ()
{
    int i,t=0;
    for(i='a'; i<='z'; i++)
        ma[(char)i]=t++;
    for(i='A'; i<='Z'; i++)
        ma[(char)i]=t++;
    t=1;
    int n,test,maan,ans,len;
    sci1(test);
    while(test--)
    {
        sci1(n);
        nodes=1;
        trie[0]=tri();
        trie[1]=tri();
        while(n--)
        {
            cin>>a;
            if(sz(a)>2)
                sort(a.begin()+1,a.end()-1);
            make_trie(0,0);
        }
        sci1(n);
        char temp;
        scch(temp);
        printf("Case %d:\n",t++);
        while(n--)
        {
            gets(b);
            len=strlen(b);
            ans=0;
            clr(a);
            for(i=0; i<len; i++)
            {
                if(b[i]==' ')
                {
                    if(sz(a)>2)
                        sort(a.begin()+1,a.end()-1);
                    // cout<<a<<endl;
                    maan=find1(0,0);
                    if(maan>0 && !ans)
                        ans=maan;
                    else if(maan>0)
                        ans*=maan;
                    clr(a);
                }
                else
                    a+=b[i];
            }
            if(sz(a)>2)
                sort(a.begin()+1,a.end()-1);
            // cout<<a<<endl;
            maan=find1(0,0);
            if(maan>0 && !ans)
                ans=maan;
            else if(maan>0)
                ans*=maan;
            printf("%d\n",ans);
        }
    }
    return 0;
}

