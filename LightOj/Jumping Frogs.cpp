#include <bits/stdc++.h>
using namespace std;

struct pathors1
{
    int a;
    bool b;
};

int ans;
pathors1 arr[105];

void solve(int a,int b)
{
    int i;
    for(i=a;i<b;i++)
    {
        if(i==a)
        {
            ans=max(ans,arr[i+1].a-arr[i].a);
        }

        if(i==b-1)
        {
            ans=max(ans,arr[i+1].a-arr[i].a);
        }

        if(i+2 <= b)
        ans=max(ans,arr[i+2].a-arr[i].a);
    }
}

int main ()
{

    int i,test,t=1,n,d,j,c;
    char z;

    scanf(" %d",&test);
    while(test--)
    {
        ans=-1;
        scanf(" %d %d",&n,&d);
        n+=2;
        arr[1].a=0;
        arr[1].b=1;

        arr[n].a=d;
        arr[n].b=1;

        for(i=2;i<n;i++)
        {
           scanf(" %c-%d",&z,&d);
           arr[i].a=d;

           if(z=='B')
               arr[i].b=1;
           else
               arr[i].b=0;
        }

        for(i=1;i<=n;i++)
        {
            if(arr[i].b)
            {
                for(j=i+1;j<=n;j++)
                {
                    if(arr[j].b)
                        {
                            solve(i,j);break;
                        }
                }
            }
        }

        printf("Case %d: %d\n",t++,ans);
    }

    return 0;
}


