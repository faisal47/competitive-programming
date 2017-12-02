#include <stdio.h>
#include <string.h>
int main ()
{
    unsigned long long a,m;unsigned len,i,j,k,flag,arr2[5000],c,d,flag2;
    char z,arr[10000];
    while((scanf("%s %c %llu",arr,&z,&a))==3)
    {
        m=0;flag=1;c=0;d=0;flag2=1;
        len=strlen(arr);
        if(z=='%')
        {
            for(i=0; i<len; i++)
            {
                m*=10;
                m+=(arr[i]-'0');
                if(m>=a)
                {
                   m%=a; flag=0;
                }
            }
            if(m==0&&flag==1)
            printf("%llu\n",m);
            else if(flag==0)
            printf("%llu\n",m);
            else
            printf("%s\n",arr);
        }
        else
        {
            for(i=0; i<len; i++)
            {
                m*=10;
                m+=(arr[i]-'0');
               flag2=1;
                if(m>=a)
                {
                  arr2[c++]=(m/a); m%=a; flag=0;d=0;flag2=0;
                }
                 if(d>=1&&flag==0&&flag2==1)
                arr2[c++]=0;
                d++;
            }
             if(flag==0)
             {
                 for(i=0;i<c;i++)
                 printf("%u",arr2[i]);
                 printf("\n");
             }
             else
             printf("0\n");
        }
    }
    return 0;
}
