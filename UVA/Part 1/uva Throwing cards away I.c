#include <stdio.h>
int main ()
{
    int n,m,o,arr1[55],i;
    while((scanf("%d",&n))==1)
    {
        if(n==0)
        break;
        if(n==1)
        {printf("Discarded cards:\nRemaining card: 1\n");continue;}
        else if(n==2)
        {
           printf("Discarded cards: 1\nRemaining card: 2\n");continue;
        }
        else if(n==3)
        {
           printf("Discarded cards: 1, 3\nRemaining card: 2\n");continue;
        }
        printf("Discarded cards:");
        for(i=1;i<=n;i+=2)
        printf(" %d,",i);
        o=0;
        for(i=2;i<=n;i+=2)
            {
                arr1[o]=i;o++;
            }
        while(1)
        {
            if(o==2)
            {
                printf(" %d\nRemaining card: %d\n",arr1[0],arr1[1]);break;
            }
            else if(o==3)
            {
                printf(" %d, %d\nRemaining card: %d\n",arr1[0],arr1[2],arr1[1]);break;
            }
           if(o%2==1)
           {
               m=0;
               o/=2;
               for(i=0;i<(o+1);i++)
                {
                   printf(" %d,",arr1[m]);m+=2;
                }
           }
           else
           {
               m=0;
               o/=2;
               for(i=0;i<o;i++)
                {
                   printf(" %d,",arr1[m]);m+=2;
                }
           }
           m=1;
           for(i=0;i<o;i++)
           {
               arr1[i]=arr1[m];m+=2;
           }
        }
    }
    return 0;
}
