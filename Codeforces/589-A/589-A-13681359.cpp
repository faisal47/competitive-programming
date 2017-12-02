#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
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
#define sz(a) (int)a.size()
#define ll long long
#define LL long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
using namespace std;

#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

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



#define mt
#define mod

int trie[2000010][30], cnt[2000010], last,kg[2000010],gc;

vec_<string>ins;
vec_<int>grps[20010];

bool okay(string arr)
{
    reverse(all(arr));
    arr=arr.substr(0,10);
    int i;
    rep(i,sz(arr))
    arr[i]=tolower(arr[i]);
    return arr=="moc.liamb@";
}

string process1(string arr)
{
    string ret="";
    int flag=0,i;
    rep(i,sz(arr))
    {
        if(arr[i]=='+')
            flag=1;
        else if(arr[i]=='@')
            flag=2;
        if(!flag && arr[i]!='.')
            ret+=tolower(arr[i]);
        else if(flag==2)
            ret+=tolower(arr[i]);
    }
    return ret;
}

string process2(string arr)
{
    string ret="";

    int i;
    rep(i,sz(arr))
    ret+=tolower(arr[i]);

    return ret;
}

string str;

void add(int ind)
{
    int i, id, cur = 0;
    for(i = 0; i<sz(str); i++)
    {
        if(str[i]=='.')
            id = 26;
        else if(str[i]=='+')
            id=27;
        else if(str[i]=='@')
            id=28;
        else
            id = str[i] - 'a';
        if(trie[cur][id] == -1)
        {
            trie[cur][id] = ++last;
            ms(trie[last], -1);
            cnt[last] = 0;
        }
        cur = trie[cur][id];
    }
    cnt[cur]++;
//    deb(ind,cnt[cur]);
    if(cnt[cur] == 1)
    {
        kg[cur]=gc;
        grps[gc].pb(ind);
        gc++;
//        deb(gc);
    }
    else
    grps[kg[cur]].pb(ind);
}

int main ()
{
    cffi;
    ms(trie[0],-1);
    string arr;
    int i,j,n;
    gc=1;

    cin>>n;
    rep(i,n)
    {
        cin>>arr;
        ins.pb(arr);
        if(okay(arr))
            arr=process1(arr);
        else
            arr=process2(arr);
        str=arr;
//        deb(str);
        add(i);
    }
    deb(gc-1);
    rep1(i,gc-1)
    {
        cout<<sz(grps[i]);
        rep(j,sz(grps[i]))
        cout<<" "<<ins[grps[i][j]];
        cout<<endl;
    }

    return 0;
}