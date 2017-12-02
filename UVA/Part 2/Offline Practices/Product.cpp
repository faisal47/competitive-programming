#include <bits/stdc++.h>

using namespace std;

#define SZ(a) (int)a.size()
#define all(a) a.begin(),a.end()
string add(string a,string b); //add any two string
string multiply(string a,string b); //multiply between a and b
string cut_leading_zero(string a); //leading zero cut 001 -> 1

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
    string a,b;
    while(cin>>a>>b)
        cout<<multiply(a,b)<<endl;
    return 0;
}

