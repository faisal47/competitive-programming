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
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define SZ(a) (int)a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define repa(i,n) for(auto i: n)
#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};


#define mt
//#define mod


string add(string a,string b); //add any two string
string multiply(string a,string b); //multiply between a and b
string multiply(string a,int k); //multiply between a and int k
string substract(string a,string b); // substract from a to b(a always >=b)
string divide(string a,string b); //divide return a/b
string divide(string a,int k); //divide return a/k
string mod(string a,string b); //Modulus of divide a%b
int mod(string a,int k); //Modulus of divide a%k
string cut_leading_zero(string a); //leading zero cut 001 -> 1
int compare(string a,string b); //(1 means a>b) (-1 means a<b) (0 means a=b)
string power(string s, int a); //Calculate powerer s^a
string GCD(string a,string b); //Calculate GCD between a and b
string LCM(string a,string b); //Calculate LCM between a and b
string LCM(string a,string b)
{
    return divide(multiply(a,b),GCD(a,b));
}
string GCD(string a,string b)
{
    return (b=="0")?a:GCD(b,mod(a,b));
}
string power(string B,int P)
{
    string R="1";
    while(P>0)
    {
        if(P%2==1)
            R=multiply(R,B);
        P/=2;
        B=multiply(B,B);
    }
    return R;
}
string multiply(string a,string b)
{
    int i,j,multi,carry;
    string ans,temp;
    ans="0";
    for(j = SZ(b)-1; j >= 0; j--)
    {
        temp="";
        carry=0;
        for(i = SZ(a)-1; i >= 0; i--)
        {
            multi=(a[i]-'0')*(b[j]-'0')+carry;
            temp+=(multi%10+'0');
            carry=multi/10;
        }
        if(carry) temp+=(carry+'0');
        reverse(all(temp));
        temp+=string(SZ(b)-j-1,'0');
        ans=add(ans,temp);
    }
    ans=cut_leading_zero(ans);
    return ans;
}
string multiply(string a,int k)
{
    string ans;
    int i,sum,carry=0;
    for(i = SZ(a)-1; i >= 0; i--)
    {
        sum=(a[i]-'0')*k+carry;
        carry=sum/10;
        ans+=(sum%10)+'0';
    }
    while(carry)
    {
        ans+=(carry%10)+'0';
        carry/=10;
    }
    reverse(all(ans));
    ans=cut_leading_zero(ans);
    return ans;
}
string add(string a,string b)
{
    int carry=0,i;
    string ans;
    if(SZ(a)>SZ(b)) b=string(SZ(a)-SZ(b),'0')+b;
    if(SZ(b)>SZ(a)) a=string(SZ(b)-SZ(a),'0')+a;
    ans.resize(SZ(a));
    for(i = SZ(a)-1; i >= 0; i--)
    {
        int sum=carry+a[i]+b[i]-96;
        ans[i]=(char)(sum%10+'0');
        carry=sum/10;
    }
    if(carry) ans.insert(0,string(1,carry+'0'));
    ans=cut_leading_zero(ans);
    return ans;
}
string substract(string a,string b)
{
    int borrow=0,i,sub;
    string ans;
    if(SZ(b)<SZ(a)) b=string(SZ(a)-SZ(b),'0')+b;
    for(i = SZ(a)-1; i >= 0; i--)
    {
        sub=a[i]-b[i]-borrow;
        if(sub<0)
        {
            sub+=10;
            borrow=1;
        }
        else borrow=0;
        ans+=sub+'0';
    }
    reverse(all(ans));
    ans=cut_leading_zero(ans);
    return ans;
}
string divide(string a,string b)
{
    string mod,temp,ans="0";
    int i,j;
    for(i = 0; i < SZ(a); i++)
    {
        mod+=a[i];
        mod=cut_leading_zero(mod);
        for(j = 0; j < 10; j++)
        {
            temp=multiply(b,j);
            if(compare(temp,mod)==1)
                break;
        }
        temp=multiply(b,j-1);
        mod=substract(mod,temp);
        ans+=(j-1)+'0';
    }
    mod=cut_leading_zero(mod);
    ans=cut_leading_zero(ans);
    return ans;
}
string divide(string a,int k)
{
    int i,sum=0;
    string ans="0";
    for(i = 0; i < SZ(a); i++)
    {
        sum=(sum*10+(a[i]-'0'));
        ans+=(sum/k)+'0';
        sum=sum%k;
    }
    ans=cut_leading_zero(ans);
    return ans;
}
string mod(string a,string b)
{
    string mod,temp,ans="0";
    int i,j;
    for(i = 0; i < SZ(a); i++)
    {
        mod+=a[i];
        mod=cut_leading_zero(mod);
        for(j = 0; j < 10; j++)
        {
            temp=multiply(b,j);
            if(compare(temp,mod)==1)
                break;
        }
        temp=multiply(b,j-1);
        mod=substract(mod,temp);
        ans+=(j-1)+'0';
    }
    mod=cut_leading_zero(mod);
    ans=cut_leading_zero(ans);
    return mod;
}
int mod(string a,int k)
{
    int i,sum=0;
    for(i = 0; i < SZ(a); i++)
        sum=(sum*10+(a[i]-'0'))%k;
    return sum;
}
int compare(string a,string b)
{
    int i;
    a=cut_leading_zero(a);
    b=cut_leading_zero(b);
    if(SZ(a)>SZ(b)) return 1; //bigger
    if(SZ(a)<SZ(b)) return -1; //smaller
    for(i = 0; i < SZ(a); i++)
        if(a[i]>b[i]) return 1; //bigger
        else if(a[i]<b[i]) return -1; //smaller
    return 0; //equal
}
string cut_leading_zero(string a)
{
    string s;
    int i;
    if(a[0]!='0') return a;
    for(i = 0; i < SZ(a)-1; i++) if(a[i]!='0') break;
    for(; i < SZ(a); i++) s+=a[i];
    return s;
}


int main ()
{
//    cffi;
    string arr;
    string ans,a,b;
    int test,t=1;
    scanf("%d",&test);
    while(test--)
    {
        cin>>arr;
        b=arr;
        a=substract(b,"1");
        ans=multiply(a,b);
        ans=divide(ans,"2");

        printf("Case %d: %s\n",t++,ans.c_str());
//        cout<<"Case "<<t++<<": "<<ans<<endl;
    }
//    fflush(stdout);
//    cout << flush;
    return 0;
}










