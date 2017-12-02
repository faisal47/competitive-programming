#include <bits/stdc++.h>
#define sci1(a) scanf("%d",&a)
using namespace std;
typedef long long ll;

template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
int main ()
{
    int arr[60],n,i,c,j;
    double ans;
    while(sci1(n)==1)
    {
        if(n==0)break;
        c=0;
        for(i=0;i<n;i++)
        sci1(arr[i]);
        for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        if(gcd(arr[i],arr[j])==1)
        c++;
        n=n*(n-1)/2;
      //  cout<<"jdf "<<n<<endl;
        if(!c)
        printf("No estimate for this data set.\n");
        else
        printf("%.6lf\n",sqrt(6.*((double)n)/((double)c)));
    }
    return 0;
}

