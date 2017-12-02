#include <stdio.h>
int main ()
{
    unsigned long long arr[6000],a=2,b=3,c=5,d=7,i,e=2,f=2,g=2,h=2,flag=0;
    arr[1]=1;
    for(i=2;i<=6000;i++)
    {
        if(a==b||a==c||a==d||b==c||b==d||c==d)
        {
            if(a==b||a==c||a==d)
            a=2*arr[e++];
            else if(b==c||b==d)
            b=3*arr[f++];
            else
            c=5*arr[g++];
            i-=1;
        }
        else if(a<b&&a<c&&a<d)
        {
            arr[i]=a;
            a=2*arr[e++];
        }
        else if(b<a&&b<c&&b<d)
        {
            arr[i]=b;
            b=3*arr[f++];
        }
        else if(c<a&&c<b&&c<d)
        {
            arr[i]=c;
            c=5*arr[g++];
        }
        else
        {
            arr[i]=d;
            d=7*arr[h++];
        }
    }
    while((scanf("%llu",&a))==1)
    {
        if(a==0)
        break;
        if(1)
        {
            if((a%100)==11||(a%100)==12||(a%100)==13||(a%100)==14||(a%100)==15||(a%100)==16||(a%100)==17||(a%100)==18||(a%100)==19)
            printf("The %lluth humble number is %llu.\n",a,arr[a]);
            else
            flag=1;
        }
        if(flag==1)
        {
            if((a%10)==1)
            printf("The %llust humble number is %llu.\n",a,arr[a]);
            else if((a%10)==2)
            printf("The %llund humble number is %llu.\n",a,arr[a]);
            else if((a%10)==3)
            printf("The %llurd humble number is %llu.\n",a,arr[a]);
            else
            printf("The %lluth humble number is %llu.\n",a,arr[a]);
            flag=0;
        }
    }
    return 0;
}
