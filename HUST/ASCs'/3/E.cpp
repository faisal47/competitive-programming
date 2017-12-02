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


#define mt 1002
//#define mod

#define fop freopen("dfa.in","r",stdin);freopen("dfa.out","w",stdout);

int visi[mt][28];
int calc_nxt[mt][28];
string arr;
bool ts[mt];
int n,gl;
string dp[mt][62];
int arr_st[mt][mt];
int jj[mt][mt];

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
    for(j = SZ(b)
            -1; j >= 0; j--
       )

    {
        temp="";
        carry=0;
        for(i = SZ(a)
                -1; i >= 0; i--
           )

        {
            multi=(a[i]
                   -'0')*(b[j]
                          -'0')+carry;
            temp+=(multi%10+'0');
            carry=multi/10;

        }
        if(carry) temp+=(carry+'0');
        reverse(all(temp));
        temp+=string(SZ(b)
                     -j
                     -1,'0');
        ans=add(ans,temp);

    }
    ans=cut_leading_zero(ans);
    return ans;
}
string multiply(string a,int k)
{
    string ans;
    int i,sum,carry=0;
    for(i = SZ(a)
            -1; i >= 0; i--
       )

    {
        sum=(a[i]
             -'0')*k+carry;
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
    if(SZ(a)>SZ(b)) b=string(SZ(a)
                                 -SZ(b),'0')+b;
    if(SZ(b)>SZ(a)) a=string(SZ(b)
                                 -SZ(a),'0')+a;
    ans.resize(SZ(a));
    for(i = SZ(a)
            -1; i >= 0; i--
       )

    {
        int sum=carry+a[i]+b[i]
                -96;
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
    if(SZ(b)<SZ(a)) b=string(SZ(a)
                                 -SZ(b),'0')+b;
    for(i = SZ(a)
            -1; i >= 0; i--
       )

    {
        sub=a[i]
            -b[i]
            -borrow;
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
    string mod,temp,ans="0"
                        ;
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
        temp=multiply(b,j
                      -1);
        mod=substract(mod,temp);
        ans+=(j
              -1)+'0';

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
        sum=(sum*10+(a[i]
                     -'0'));
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
        temp=multiply(b,j
                      -1);

        mod=substract(mod,temp);
        ans+=(j
              -1)+'0';

    }
    mod=cut_leading_zero(mod);
    ans=cut_leading_zero(ans);
    return mod;
}
int mod(string a,int k)
{
    int i,sum=0;
    for(i = 0; i < SZ(a); i++)
        sum=(sum*10+(a[i]
                     -'0'))%k;
    return sum;
}
int compare(string a,string b)
{
    int i;
    a=cut_leading_zero(a);
    b=cut_leading_zero(b);
    if(SZ(a)>SZ(b)) return 1; //bigger
    if(SZ(a)<SZ(b)) return
            -1; //smaller
    for(i = 0; i < SZ(a); i++)
        if(a[i]>b[i]) return 1; //bigger
        else if(a[i]<b[i]) return
                -1; //smaller
    return 0; //equal
}
string cut_leading_zero(string a)
{
    string s;
    int i;
    if(a[0]!='0') return a;
    for(i = 0; i < SZ(a)
            -1; i++) if(a[i]!='0') break;
    for(; i < SZ(a); i++) s+=a[i];
    return s;
}



string solve(int s,int len)
{
    if(len == gl)
        {
            if(ts[s]==1)
                return "1";
            return "0";
        }
    if(sz(dp[s][len]))
        return dp[s][len];
    dp[s][len]="0";

    int i;
    rep(i,sz(arr))
    {
        if(jj[s][i])
        {
            if(calc_nxt[s][i] == -1)
                continue;
            dp[s][len]=add(dp[s][len] , solve(arr_st[calc_nxt[s][i]][i],len+1));
        }
        else
            dp[s][len]=add(dp[s][len] , solve(arr_st[s][i],len+1));
    }
    return dp[s][len];
}

int dfs(int st,int c)
{
    if(!jj[st][c])
    {
        visi[st][c]=2;
        return calc_nxt[st][c]=st;
    }
    if(visi[st][c]==2)
        return calc_nxt[st][c];
    visi[st][c]=1;
    int nb=arr_st[st][c];

    if(visi[nb][c] == 1)
        calc_nxt[st][c]=-1;
    else
        calc_nxt[st][c]=dfs(nb,c);

    visi[st][c]=2;

    return calc_nxt[st][c];
}

string solve2(int s)
{
    int i,j,k,nb;
    string res;
    rep(i,gl+1)
    rep(j,n)
    {
        dp[j][i]="0";
        if(i==0)
        {
            if(ts[j])
                dp[j][i]="1";
            continue;
        }
        res="0";
        rep(k,sz(arr))
        {
            if(jj[j][k])
            {
                if(calc_nxt[j][k] == -1)
                    continue;
                res=add(res,dp[arr_st[calc_nxt[j][k]][k]][i-1]);
                continue;
            }
            else
                res=add(res,dp[arr_st[j][k]][i-1]);
        }
        dp[j][i]=res;
    }
    return dp[s][gl];
}

int main ()
{
    cffi;
    fop;
    int k,i,j,s,a,b;
    cin>>arr>>n>>s>>k;
    while(k--)
    {
        cin>>i;
        i--;
        ts[i]=1;
    }
    rep(i,n)
    rep(j,sz(arr))
    {
        cin>>arr_st[i][j];
        arr_st[i][j]--;
    }

    rep(i,n)
    rep(j,sz(arr))
    cin>>jj[i][j];

    rep(i,n)
    rep(j,sz(arr))
    dfs(i,j);

    cin>>gl;
    deb(solve2(s-1));

    return 0;
}




