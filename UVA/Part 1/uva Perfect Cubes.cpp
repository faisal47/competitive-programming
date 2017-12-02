#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    unsigned long long arr[250],i,j,k,l;
    for(i=1;i<201;i++)
    arr[i]=(i*i*i);
    for(i=1;i<201;i++)
    {
        for(j=2;j<201;j++)
        {
            for(k=j+1;k<201;k++)
            {
                for(l=k+1;l<201;l++)
                {
                    if(arr[i]==(arr[j]+arr[k]+arr[l]))
                    {
                        printf("Cube = %llu, Triple = (%llu,%llu,%llu)\n",i,j,k,l);
                    }
                }
            }
        }
    }
    return 0;
}
