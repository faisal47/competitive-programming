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
#define ull unsigned long long
#define dd double
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//

#define mt 110
#define mod

string arr[mt],arr2[mt];

vec_<int>adj[30];
int ind[30];

string top_sort()
{
    string ans;
    int i,u,v;
    queue<int>q;
    for(i=0;i<26;i++)
    {
        if(!ind[i])
        {
            ans+=(char)(i+'a');
            q.push(i);
        }
    }

    while(!q.empty())
    {
        u=q.front();q.pop();
        for(i=0;i<sz(adj[u]);i++)
        {
            v=adj[u][i];
            ind[v]--;
            if(!ind[v])
            {
                ans+=(char)(v+'a');
                q.push(v);
            }
        }
    }

    if(sz(ans) == 26)
        return ans;
    return "Impossible";
}

int main ()
{
    cffi;
    int i,j,n,c,k;
    c=0;
    int maxi=0;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
        arr2[i]="";
        maxi=max(maxi,sz(arr[i]));
    }
    int a,b;
    int mini;
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
        {
            mini=min(sz(arr[i]),sz(arr[j]));
            if(arr[i].substr(0,mini) == arr[j].substr(0,mini) && sz(arr[i])>sz(arr[j]))
            {
                deb("Impossible");
                return 0;
            }
        }

    for(j=0; j<maxi; j++)
    {
        for(i=0; i<n; i++)
        {
            for(k=i+1; k<n; k++)
            {
                if(arr2[i] == arr2[k] && j<sz(arr[i]) && j<sz(arr[k]))
                {
                    a=arr[i][j]-'a';
                    b=arr[k][j]-'a';
                    if(a != b)
                    {
                        adj[a].pb(b);
                        ind[b]++;
                    }
                }
            }
        }
        for(i=0;i<n;i++)
            if(j<sz(arr[i]))
            arr2[i]+=arr[i][j];

    }

//    deb("hola");

    deb(top_sort());

    return 0;
}