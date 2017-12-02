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

int arr1[mt],arr2[mt];

void solve(int a,int b)
{
    if(a==0)
    {
        int i;
        for(i=0; i<b; i++)
            cout<<" ";
    }
    else if(a==1)
    {
        if(b==1)
            cout<<'.';
        else if(b==2)
            cout<<',';
        else if(b==3)
            cout<<'?';
        else
            cout<<"\"";
    }
    else if(a==2)
    {
        if(b==1)
            cout<<"a";
        else if(b==2)
            cout<<"b";
        else
            cout<<"c";
    }
    else if(a==3)
    {
        if(b==1)
            cout<<"d";
        else if(b==2)
            cout<<"e";
        else
            cout<<"f";
    }
    else if(a==4)
    {
        if(b==1)
            cout<<"g";
        else if(b==2)
            cout<<"h";
        else
            cout<<"i";
    }
    else if(a==5)
    {
        if(b==1)
            cout<<"j";
        else if(b==2)
            cout<<"k";
        else
            cout<<"l";
    }
    else if(a==6)
    {
        if(b==1)
            cout<<"m";
        else if(b==2)
            cout<<"n";
        else
            cout<<"o";

    }
    else if(a==7)
    {
        if(b==1)
            cout<<"p";
        else if(b==2)
            cout<<"q";
        else if(b==3)
            cout<<"r";
        else
            cout<<"s";

    }
    else if(a==8)
    {
        if(b==1)
            cout<<"t";
        else if(b==2)
            cout<<"u";
        else
            cout<<"v";

        }
    else if(a==9)
    {
        if(b==1)
            cout<<"w";
        else if(b==2)
            cout<<"x";
        else if(b==3)
            cout<<"y";
        else
            cout<<"z";

        }
    return ;
}

int main ()
{
    cffi;
    int i,j,test,n,a,b;

    cin>>test;

    while(test--)
    {
        cin>>n;
        for(i=1; i<=n; i++)
            cin>>arr1[i];
        for(i=1; i<=n; i++)
            cin>>arr2[i];

        for(i=1; i<=n; i++)
        {
            a=arr1[i];
            b=arr2[i];
            solve(a,b);

        }
        cout<<endl;

    }

    return 0;
}


