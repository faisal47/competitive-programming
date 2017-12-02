#include <stdio.h>
int arr[36],arrprime[36];
int main ()
{
    int n,i,j,flag,c,d;
    arrprime[0]=2;c=1;
    for(i=3;i<33;i+=2)
    {
        if(arr[i]==0)
        {
            arrprime[c++]=i;
            for(j=i+i;j<33;j+=i)
            arr[j]=3;
        }
    }
    while((scanf("%d",&n))==1)
    {
        if(n==0)
        break;
        flag=0;
        if(n==2)
        printf("Perfect: 6!\n");
        else if(n==3)
        printf("Perfect: 28!\n");
        else if(n==5)
        printf("Perfect: 496!\n");
        else if(n==7)
        printf("Perfect: 8128!\n");
        else if(n==13)
        printf("Perfect: 33550336!\n");
        else if(n==17)
        printf("Perfect: 8589869056!\n");
        else if(n==19)
        printf("Perfect: 137438691328!\n");
        else if(n==31)
        printf("Perfect: 2305843008139952128!\n");
        else
        {
            for(i=0;i<c;i++)
            {
                if(arrprime[i]==n)
                flag=1;
            }
            if(flag==1)
            printf("Given number is prime. But, NO perfect number is available.\n");
            else
            printf("Given number is NOT prime! NO perfect number is available.\n");
        }
    }
    return 0;
}
