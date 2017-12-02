#include <bits/stdc++.h>


#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<30
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define make_flush  cout << flush; //    fflush(stdout);
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
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repa(i,n) for(auto i: n)
#define fop freopen("control.in","r",stdin);freopen("control.out","w",stdout);
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


//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
int X[]= {0,-1,-1,-1,0,1,1,1};
int Y[]= {-1,-1,0,1,1,1,0,-1};
int X2[]= {-1,0,1,0};
int Y2[]= {0,1,0,-1};


#define mt
#define mod

map<pii,bool>ma,tma;

struct maan
{
    pii temp;
    int d;
};

queue<maan>q;
queue<pii>q2;

void bfs1(pii temp,int nd)
{
    clr(tma);
    nd++;
    while(!q.empty())q.pop();
    q.push({temp,0});
    ma[temp]=1;
    pii temp2;
    int d2,td;
    tma[temp]=1;
    while(!q.empty())
    {
        temp=q.front().temp;
        d2=q.front().d;
        q.pop();
        if(d2==0)
        {
            rep(i,8)
            {
                temp2.fs=temp.fs+X[i];
                temp2.sc=temp.sc+Y[i];
                td=d2+1;
                if(td>nd || tma.find(temp2)!=tma.end())
                    continue;
                ma[temp2]=1;
                tma[temp2]=1;
                q.push({temp2,td});
            }
            continue;
        }
        rep(i,4)
        {
            temp2.fs=temp.fs+X2[i];
            temp2.sc=temp.sc+Y2[i];
            td=d2+1;
            if(td>nd || tma.find(temp2)!=tma.end())
                continue;
            ma[temp2]=1;
            tma[temp2]=1;
            q.push({temp2,td});
        }
    }
}

bool ok1(pii temp1)
{
    pii temp2=temp1;
    pii temp3=temp1;
    pii temp4=temp1;
    temp2.fs++;
    temp3.fs++;
    temp3.sc++;
    temp4.sc++;
    return ma.find(temp1)==ma.end() && ma.find(temp2)==ma.end() && ma.find(temp3)==ma.end() && ma.find(temp4)==ma.end();
}

bool ok2(pii temp1)
{
    pii temp2=temp1;
    pii temp3=temp1;
    pii temp4=temp1;
    temp2.fs--;
    temp3.fs--;
    temp3.sc++;
    temp4.sc++;
    return ma.find(temp1)==ma.end() && ma.find(temp2)==ma.end() && ma.find(temp3)==ma.end() && ma.find(temp4)==ma.end();
}

bool ok3(pii temp1)
{
    pii temp2=temp1;
    pii temp3=temp1;
    pii temp4=temp1;
    temp2.fs--;
    temp3.fs--;
    temp3.sc--;
    temp4.sc--;
    return ma.find(temp1)==ma.end() && ma.find(temp2)==ma.end() && ma.find(temp3)==ma.end() && ma.find(temp4)==ma.end();
}


bool ok4(pii temp1)
{
    pii temp2=temp1;
    pii temp3=temp1;
    pii temp4=temp1;
    temp2.fs++;
    temp3.fs++;
    temp3.sc--;
    temp4.sc--;
    return ma.find(temp1)==ma.end() && ma.find(temp2)==ma.end() && ma.find(temp3)==ma.end() && ma.find(temp4)==ma.end();
}

void bfs2()
{
    pii temp,temp2;
    repa(num,ma)
    {
        temp=num.fs;
        rep(i,8)
        {
            temp2.fs=temp.fs+X[i];
            temp2.sc=temp.sc+Y[i];
            if(ma.find(temp2) != ma.end())
                continue;
            q2.push(temp2);
        }
    }
    while(!q2.empty())
    {
        temp2=q2.front();q2.pop();
        if(ok1(temp2) || ok2(temp2) || ok3(temp2) || ok4(temp2))
            continue;
        ma[temp2]=1;
    }
}

int main ()
{
    cffi;
    fop;
    int i,j,test,n,t=1;
    cin>>n;
    int a,b,c;
    while(n--)
    {
        cin>>a>>b>>c;
        bfs1({a,b},c);
    }
    bfs2();
    deb(sz(ma));
    return 0;
}










