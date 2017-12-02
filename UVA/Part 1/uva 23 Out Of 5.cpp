#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <queue>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define ll long long
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define eps 1E-7
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz
using namespace std;
//struct data //for dj()
//{
//   int node,cost;
//   bool operator < (const data& p) const
//   {
//       return cost > p.cost;
//   }
//};
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
//ll gcd(ll a,ll b)
//{
//   if(b==0)
//   return a;
//   return gcd(b,a%b);
//}
int arr[6],res_rough,flag_res;
vec_<int>v;
char chinno[4]= {'+','-','*'};
//void func(int a,int b,int c,int d)
//{
//    if(flag_res)
//        return;
//    res_rough=0;
//    int i,j,k,l,m;
//    for(i=0; i<5; i++)
//        for(j=0; j<5; j++)
//            for(k=0; k<5; k++)
//                for(l=0; l<5; l++)
//                    for(m=0; m<5; m++)
//                    {
//                        res_rough=arr[i];
//                        opa(a,j);
//                        opa(b,k);
//                        opa(c,l);
//                        opa(d,m);
//                        if(res_rough==23)
//                        {
//                            flag_res=1;
//                            return;
//                        }
//                    }
//}
void opa(int a,int b)
{
    if(a==0)
        res_rough+=v[b];
    else if(a==1)
        res_rough-=v[b];
    else
        res_rough*=v[b];
}
void func1(int a,int b,int c,int d)
{
    //cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<" "<<v[4]<<endl;
    res_rough=v[0];
     opa(a,1);
    opa(b,2);
      opa(c,3);
      opa(d,4);
}
int main ()
{
    int i,j,k,l;
    bool flag;
    while(scanf("%d %d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4])==5)
    {
        flag=0;
        flag_res=0;
        clr(v);
        for(i=0; i<5; i++)
        {
            v.pb(arr[i]);
            if(arr[i]!=0)
                flag=1;
        }
        if(!flag)
            break;
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                for(k=0; k<3; k++)
                {
                    for(l=0; l<3; l++)
                    {
                        sort(v.begin(),v.end());
                        do
                        {
                            func1(i,j,k,l);
                            if(res_rough==23)
                            {
                                flag_res=1;
                                break;
                            }
                        }
                        while(next_permutation(v.begin(),v.end()));
                        if(flag_res)
                            break;
                    }
                    if(flag_res)
                        break;
                }
                if(flag_res)
                    break;
            }
            if(flag_res)
                break;
        }
        if(flag_res)
        {
            printf("Possible\n");
        }
        else
        {
            printf("Impossible\n");
        }
    }
    return 0;
}
