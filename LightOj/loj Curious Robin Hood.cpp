#include <stdio.h>
long long arr[100010],segment[262145];
void maketree(long long s,long long e,long long nod)
{
    if(s==e)
    {
        segment[nod]=arr[s];
        return;
    }
    long long mid=(s+e)/2;
    maketree(s,mid,2*nod);
    maketree(mid+1,e,2*nod+1);
    segment[nod]=segment[2*nod]+segment[2*nod+1];
}
void q(long long pos,long long nod,long long s,long long e)
{
    if(s==e)
    {
       segment[nod]=arr[pos];
        return;
    }
   long long mid=(s+e)/2;
   if(pos<=mid)
   q(pos,2*nod,s,mid);
   else
   q(pos,2*nod+1,mid+1,e);
   segment[nod]=segment[2*nod]+segment[2*nod+1];
}
long long khuj(long long s,long long e,long long nod,long long a,long long b)
{
    if(b<s||a>e)
    return 0;
    else if(a>=s&&b<=e)
    {
        return segment[nod];
    }
    long long mid,sum1,sum2;
    mid=(a+b)/2;
    sum1=khuj(s,e,2*nod,a,mid);
    sum2=khuj(s,e,2*nod+1,mid+1,b);
    return sum1 + sum2;
}
int main ()
{
   long long a,b,test,t,i,m,n,moti;
    scanf("%lld",&test);
    for(t=1;t<=test;t++)
    {
        printf("Case %lld:\n",t);
        scanf("%lld %lld",&n,&m);
        for(i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
        maketree(1,n,1);
        while(m--)
        {
           scanf("%lld",&a);
            if(a==1)
            {
                scanf("%lld",&b);
                b++;
                printf("%lld\n",arr[b]);
                arr[b]=0;
                q(b,1,1,n);
            }
            else if(a==2)
            {
                scanf("%lld %lld",&a,&b);
                a++;
                arr[a]+=b;
                q(a,1,1,n);
            }
            else
            {
                scanf("%lld %lld",&a,&b);
                a++;b++;
                moti=khuj(a,b,1,1,n);
                printf("%lld\n",moti);
            }
        }
    }
    return 0;
}
