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

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


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

#define mt 17
#define mod

int arr1[mt];
int arr2[mt];
int sums1[(1<<mt)+5];
int sums2[(1<<mt)+5];
int n1,n2,c1,c2;

int bs1(int num)
{
    int l=0,r=c2,mid,ret=-1;

    while(l<=r)
    {
        mid=(l+r)>>1;
        if(sums2[mid]>=num)
        {
            if(ret == -1)
                ret=mid;
            else
                ret=min(ret,mid);
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return ret;
}


int bs2(int num)
{
    int l=0,r=c2,mid,ret=-1;

    while(l<=r)
    {
        mid=(l+r)>>1;
        if(sums2[mid]<=num)
        {
            if(ret == -1)
                ret=mid;
            else
                ret=max(ret,mid);
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return ret;
}


int main ()
{
//    cffi;
    int i,j,n,a,b;

    sci3(n,a,b);

    n1=n2=0;

    for(i=0;i<n;i++)
    {
        if(n1>=17)
            sci1(arr2[n2++]);
        else
            sci1(arr1[n1++]);
    }

    int mask=(1<<n1),sum;
    c1=c2=0;
    while(mask--)
    {
        sum=0;
        for(i=0;i<n1;i++)
            if((1 << i) & mask)
            sum+=arr1[i];
        sums1[c1++]=sum;
    }

    mask=(1<<n2);

    while(mask--)
    {
        sum=0;
        for(i=0;i<n2;i++)
            if((1 << i) & mask)
            sum+=arr2[i];
        sums2[c2++]=sum;
    }
    sort(sums2,sums2+c2);
//    sort(sums1,sums1+c1);
    c1--;c2--;
//    deb(c1);
    ll ans=0;
    int bam,dan,baki;
    for(i=0;i<=c1;i++)
    {
//        deb(sums1[i],a-sums1[i],b-sums1[i]);
        baki=a-sums1[i];
        bam=bs1(baki);

        baki=b-sums1[i];
        dan=bs2(baki);

        if(bam==-1 || dan==-1)
            continue;

        ans+=(ll)(dan-bam+1);
    }

    printf("%lld\n",ans);

    return 0;
}


