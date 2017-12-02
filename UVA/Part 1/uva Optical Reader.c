#include <stdio.h>
int main ()
{
   int n,a[300],b[300],c[300],d[300],e[300],i,flag;
   char f;
   while((scanf("%d",&n))==1)
   {
       if(n==0)
       break;
       for(i=0;i<n;i++)
       scanf("%d %d %d %d %d",&a[i],&b[i],&c[i],&d[i],&e[i]);
       for(i=0;i<n;i++)
       {
           flag=0;
           if(a[i]<=127)
           {
               flag+=1;f='A';
           }
           if(b[i]<=127)
           {
               flag+=1;f='B';
           }
           if(c[i]<=127)
           {
               flag+=1;f='C';
           }
           if(d[i]<=127)
           {
               flag+=1;f='D';
           }
           if(e[i]<=127)
           {
               flag+=1;f='E';
           }
           if(flag==1)
           printf("%c\n",f);
           else
           printf("*\n");
       }
   }
    return 0;
}
