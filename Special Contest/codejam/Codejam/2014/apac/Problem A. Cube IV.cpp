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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
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
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//

#define mt 1010
#define mod
#define fop   freopen("al.txt","r",stdin);freopen("alout.txt","w",stdout);

int arr[mt][mt],n;
bool col[mt][mt];

bool check(int s,int e,int maan)
{
    return s>=1 && s<=n && e>=1 && e<=n && col[s][e]==0 && abs(arr[s][e]-maan)==1;
}

pii bfs(int s,int e)
{
    queue<int>q;
    q.push(s);
    q.push(e);
    col[s][e]=1;
    int retmin=arr[s][e],retans=1,i,s1,e1,maan;
    while(!q.empty())
    {
        s=q.front();q.pop();
        e=q.front();q.pop();
            maan=arr[s][e];

        for(i=0;i<4;i++)
        {
            s1=s+X[i];
            e1=e+Y[i];
            if(check(s1,e1,maan))
            {
                retans++;
                retmin=min(retmin,arr[s1][e1]);
                q.push(s1);
                q.push(e1);
                col[s1][e1]=1;
            }
        }
    }
    return mp(retmin,retans);
}

int main ()
{
//    cffi;
fop;
    int i,j,test,t=1;
    pii temp,ans;
    cin>>test;
    while(test--)
    {
        cin>>n;
        ms(col,0);
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                cin>>arr[i][j];
        ans.sc=-1;
        ans.fs=inf;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(!col[i][j])
                {
                    temp=bfs(i,j);
                    if(temp.sc > ans.sc)
                    ans=temp;
                    else if(temp.sc == ans.sc)
                    ans.fs=min(ans.fs,temp.fs);
                }
            }
        }
        printf("Case #%d: %d %d\n",t++,ans.fs,ans.sc);
    }

    return 0;
}



