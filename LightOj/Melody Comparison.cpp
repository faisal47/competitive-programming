#include <bits/stdc++.h>

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
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define ll long long
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}


string text,pattern;
int f[100010],cum[50010];

void kmp()
{
    ms(cum,0);
    int len1=text.size(),len2=pattern.size();
    pattern.push_back('#');
    pattern+=text;
    int k;
    f[0]=k=0;
    int i;
    for(i=1; i<pattern.size(); i++)
    {
        while(k>0 && pattern[i]!=pattern[k])
            k=f[k-1];
        if(pattern[i]==pattern[k])
            k++;
        f[i]=k;
        if(k==len2 && i>len2)
            cum[i-len2-1]++;
    }

    return;
}

#define MAX 50010

int revSA[MAX],SA[MAX];
int cnt[MAX] , nxt[MAX];
bool bh[MAX],b2h[MAX];
int lcp[MAX];


bool cmp(int i,int j)
{
    return text[i]<text[j];
}

void sortFirstChar(int n)
{
    for(int i =0 ; i<n ; i++)
        SA[i] = i;
    sort(SA,SA+n ,cmp);

    for(int i=0 ; i<n ; i++)
    {
        bh[i] = (i==0  || text[SA[i]]!=text[SA[i-1]]);
        b2h[i] = false;
    }
    return;
}

int CountBucket(int n)
{
    int bucket = 0;
    for(int i =0 ,j; i<n ; i=j)
    {
        j = i+1;
        while(j<n && bh[j]==false) j++;
        nxt[i] = j;
        bucket++;
    }
    return bucket;
}

void SetRank(int n)
{
    for(int i = 0 ; i<n ; i=nxt[i])
    {
        cnt[i] = 0;
        for(int j =i ; j<nxt[i] ; j++)
        {
            revSA[SA[j]] = i;
        }
    }
    return;
}

void findNewRank(int l,int r,int step)
{
    for(int j = l  ; j<r ; j++)
    {
        int pre = SA[j] - step;
        if(pre>=0)
        {
            int head = revSA[pre];
            revSA[pre] = head+cnt[head]++;
            b2h[revSA[pre]] = true;
        }
    }
    return;
}

void findNewBucket(int l,int r,int step)
{
    for(int j = l  ; j<r ; j++)
    {
        int pre = SA[j] - step;
        if(pre>=0 && b2h[revSA[pre]])
        {
            for(int k = revSA[pre]+1 ; b2h[k] && !bh[k] ; k++) b2h[k] = false;
        }
    }
    return;
}

void buildSA(int n)
{
    sortFirstChar(n);
    for(int h =1 ; h<n ; h<<=1)
    {
        if(CountBucket(n)==n) break;
        SetRank(n);
        b2h[revSA[n-h]] = true;
        cnt[revSA[n-h]]++;

        for(int i = 0 ; i<n ; i=nxt[i])
        {
            findNewRank(i,nxt[i] , h);
            findNewBucket(i , nxt[i] , h);
        }
        for(int i =0 ; i<n ; i++)
        {
            SA[revSA[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    return;
}

int bs(int num,int l,int r)
{
    int mid,ret=-1;

    while(l<=r)
    {
        mid=(l+r)>>1;
        if(cum[mid]==num)
        {
            ret=max(ret,mid);
            l=mid+1;
        }
        else
            r=mid-1;
    }

    return ret;
}

ll buildLCP(int n)
{
    int len = 0,ret2,bi,num,np;
    ll ret=0;
    for(int i = 0 ; i<n ; i++)
        revSA[SA[i]] = i;
    for(int i =0 ; i< n ; i++)
    {
        int k = revSA[i];
        if(k==0)
        {
            lcp[k] = 0;
            bi=i+sz(pattern)-1;
            if(bi>n-1)
            {
                ret2=n-1;
                np=ret2-i+1;
                if(np>0)
                    ret+=(ll)np;
            }
            else
            {
                ret2=bi-1;
                if(bi==0)
                    num=0;
                else
                    num=cum[bi-1];
                ret2=max(ret2,bs(num,bi,n-1));

                if(ret2 != -1)
                {
                    np=ret2-i+1;
                    if(np>0)
                        ret+=(ll)np;
                }
            }

            continue;
        }
        int j = SA[k-1];
        while(text[i+len]==text[j+len]) len++;
        lcp[k] = len;
        bi=i+sz(pattern)-1;

        if(bi>n-1)
        {
            ret2=n-1;
            np=ret2-i+1-len;
            if(np>0)
                ret+=(ll)np;
        }
        else
        {
            ret2=bi-1;
            if(bi==0)
                num=0;
            else
                num=cum[bi-1];

            ret2=max(ret2,bs(num,bi,n-1));
            if(ret2 != -1)
            {
                np=ret2-i+1-len;
                if(np>0)
                    ret+=(ll)np;
            }

        }
        if(len) len--;
    }
    return ret;
}

int main ()
{
    cffi;
    int i,j,test,t=1;
    string temp;
    ll ans;

    cin>>test;
    while(test--)
    {
        cin>>text>>pattern;
        temp=pattern;
        kmp();
        pattern=temp;
        for(i=1; i<sz(text); i++)
            cum[i]+=cum[i-1];
        buildSA(sz(text));
        cout<<"Case "<<t++<<": ";
        deb(buildLCP(sz(text)));
    }

    return 0;
}


