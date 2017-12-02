#include <stdio.h>
unsigned long long arr[1200][3000],arrlen[1200];
int main ()
{
    unsigned long long i,j,n,a,b,c,d,e,f;
     arr[0][0]=1;arrlen[0]=1;
      arr[1][0]=1;arrlen[1]=1;
       arr[2][0]=2;arrlen[2]=1;
      for(i=3;i<1004;i++)
       {
           a=i-1;b=0;c=0;
           for(j=0;j<arrlen[a];j++)
           {
               b+=(arr[a][j]*i);
               arr[i][c++]=b%10;
               b/=10;
           }
           while(1)
           {
               if(b==0)
               break;
               arr[i][c++]=b%10;
               b/=10;
           }
           arrlen[i]=c;
       }
       while((scanf("%llu",&n))==1)
       {
           f=0;
           i=arrlen[n];
           while(i--)
           f+=arr[n][i];
           printf("%llu\n",f);
       }
    return 0;
}
