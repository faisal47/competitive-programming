#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<30
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
//#define fs first
//#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
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


#define mt 200010
#define mod

#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

struct maan
{
    ll sr,fs,sc;
};

queue<maan>q;
queue<maan>q2;
ll ans[mt];

int main ()
{
    cffi;
    ll i,j,test,n,t=1,a,b;
    ll now=0,cap;
    maan temp;
    cin>>n>>cap;
    rep(i,n)
    {
        cin>>a>>b;

        if(a<now)
        {
            if(sz(q) < cap)
            q.push({i,a,b});
            else
            ans[i]=-1;
        }
        else
        {
            q2.push({i,a,b});
            while(!q.empty())
            {
                if(!q2.empty() && q2.front().fs < now)
                    break;
                temp=q.front();
                q.pop();
                now+=temp.sc;
                ans[temp.sr]=now;
            }
            while(!q2.empty())
            {
               temp=q2.front();
               if(now > temp.fs && sz(q) < cap)
                {
                    q.push(temp);
                    q2.pop();
                }
               else if(now > temp.fs && sz(q) == cap)
               {
                   ans[temp.sr]=-1;
                   q2.pop();
               }
               else if(q.empty())
               {
                   now=temp.fs+temp.sc;
                   q2.pop();
                   ans[temp.sr]=now;
               }
               else
                break;
            }
        }
    }

    while(1)
    {
        if(q2.empty() && q.empty())
            break;
        while(!q.empty())
            {
                if(!q2.empty() && q2.front().fs < now)
                    break;
                temp=q.front();
                q.pop();
                now+=temp.sc;
                ans[temp.sr]=now;
            }
        while(!q2.empty())
            {
               temp=q2.front();
               if(now > temp.fs && sz(q) < cap)
                {
                    q.push(temp);
                    q2.pop();
                }
               else if(now > temp.fs && sz(q) == cap)
               {
                   ans[temp.sr]=-1;
                   q2.pop();
               }
               else if(q.empty())
               {
                   now=temp.fs+temp.sc;
                   q2.pop();
                   ans[temp.sr]=now;
               }
               else
                break;
            }
    }

    rep(i,n)
    cout<<ans[i]<<" ";

    return 0;
}