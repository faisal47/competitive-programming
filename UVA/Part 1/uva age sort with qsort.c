#include <stdio.h>
#include <stdlib.h>
int arr[2000000];
int cp(void const *p, void const *q);
int main ()
{
   long long int n,i;
   while((scanf("%lld",&n))==1)
   {
       if(n==0)
       break;
       for(i=0;i<n;i++)
       scanf("%d",&arr[i]);
       qsort(arr,n,sizeof(int),cp);
       for(i=0;i<n;i++)
       printf("%d ",arr[i]);
       printf("\n");
   }
    return 0;
}
int cp(void const *p, void const *q)
{
    return *(int*)p - *(int*)q;
}
