#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 5000010
#define mod

int trie[MAX][2], last;
ll inputArr[100010];
bool arr[50],ansArr[50];

void AddToTrie()
{
    int i, cur = 0;
    bool id;
    for(i=45; i>=0; i--)
    {
        id=arr[i];
        if(trie[cur][id] == -1)
        {
            trie[cur][id] = ++last;
            memset(trie[last], -1,sizeof(trie[last]));
        }
        cur = trie[cur][id];
    }
}

void decimalToBinary(ll num)
{
    memset(arr,0,sizeof(arr));
    int cnt=0;
    while(num > 0)
    {
        arr[cnt++]=(num&1ll);
        num>>=1ll;
    }
}

ll binaryToDecimal()
{
    ll ret=0ll;
    for(int i=0;i<=45;i++)
    {
        if(ansArr[i])
            ret|=(1ll<<i);
    }
    return ret;
}

ll findMaximumValue()
{
    memset(ansArr,0,sizeof(ansArr));
    int i, cur = 0;
    bool id;
    for(i=45; i>=0; i--)
    {
        id=arr[i];
        id^=1;
        if(trie[cur][id]==-1)
            {
                id^=1;
                ansArr[i]=0;
            }
        else
            ansArr[i]=1;
        cur = trie[cur][id];
    }
    return binaryToDecimal();
}

int main ()
{
    int i,j,test,n,t=1;
    ll prefixXor,suffixXor,ans;

    prefixXor=suffixXor=ans=0ll;
    last=0;

    memset(trie[0], -1,sizeof(trie[0]));
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>inputArr[i];
        prefixXor^=inputArr[i];
    }

    inputArr[0]=inputArr[n+1]=0ll;

    for(int i=n+1; i>=0; i--)
    {
        prefixXor^=inputArr[i];
        suffixXor^=inputArr[i];

        decimalToBinary(suffixXor);
        AddToTrie();

        decimalToBinary(prefixXor);

        ans=max(ans,findMaximumValue());
    }

    cout<<ans<<endl;

    return 0;
}
