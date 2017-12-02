#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sz(a) a.size()
#define matra 32767
using namespace std;
char arr[1000000];
int primes[matra+5];
bool flag[matra+5];
int main ()
{
    int i,len,j,k;
    bool flag_1;
    char *a;
    vec_<int>v;
   // j=sqrt(matra+5);
    v.pb(2);
    for(i=3; i<=matra; i+=2)
    {
        if(!flag[i])
        {
            v.pb(i);
            for(k=i; k<=matra; k+=i)
                flag[k]=1;
        }
    }
    while(gets(arr))
    {
        len=strlen(arr);
        if(len==1 && arr[0]=='0')break;
        ms(primes,0);
        a=strtok(arr," ");
        i=atoi(a);
        k=1;
        while(a!=NULL)
        {
            a=strtok(NULL," ");
           j=atoi(a);
            k*=pow(i,j);
            a=strtok(NULL," ");
            if(a==NULL)
            break;
            i=atoi(a);
        }
        //cout<<k<<endl;
        k--;
        for(i=0;i<sz(v);i++)
        {
          //  cout<<k<<endl;
            while(k%v[i]==0)
            k/=v[i],primes[v[i]]++;
        }
        flag_1=0;
        if(k>1)
        cout<<k<<" 1",flag_1=1;
        for(i=matra;i>=1;i--)
        if(primes[i])
        {
            if(flag_1)
            cout<<" ";
            flag_1=1;
            cout<<i<<" "<<primes[i];
        }
        cout<<endl;
    }
    return 0;
}

