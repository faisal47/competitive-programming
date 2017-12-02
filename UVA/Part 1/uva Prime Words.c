#include <stdio.h>
#include <string.h>
int arr1[1150],prime[200];
int main ()
{
    char arr[25];
    int arrchar[150],i,j,k,c=0,len,flag;
    for(i=0; i<1100; i++)
        arr1[i]=0;
    for(i=0; i<28; i++)
        arrchar['a'+i]=i+1;
    for(i=0; i<28; i++)
        arrchar['A'+i]=i+27;
    for(i=4; i<1100; i+=2)
        arr1[i]=3;
    arr1[0]=3;
    arr1[1]=1;
    arr1[2]=1;
    for(i=3; i<1100; i++)
    {
        if(arr1[i]==0)
        {
            arr1[i]=1;
            k=i+i;
            while(1)
            {
                if(k>=1100)
                    break;
                arr1[k]=3;
                k+=i;
            }
        }
    }
    for(i=0; i<1100; i++)
    {
        if(arr1[i]==1)
            prime[c++]=i;
    }
    while(gets(arr))
    {
        flag=j=0;
        len=strlen(arr);
        for(i=0;i<len;i++)
        j+=arrchar[arr[i]];
        for(i=0;i<200;i++)
        {
            if(j==prime[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        printf("It is a prime word.\n");
        else
        printf("It is not a prime word.\n");
    }
    return 0;
}
