#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    unsigned long long a,b,i,jog1=0,jog2=0,j,flag=0,count=0;
    a=6;b=8;
    printf("%10llu%10llu\n",a,b);
    a=35;b=49;
    printf("%10llu%10llu\n",a,b);
    for(i=1;i<=34;i++)
    jog1+=i;
    for(i=36;i<=49;i++)
    jog2+=i;
    j=49;
    i=35;
    while(i++)
    {
        jog1+=i-1;
        jog2-=i;
        while(1)
        {
            if(jog2>jog1)
            break;
            else if(jog1==jog2)
            {
                printf("%10llu%10llu\n",i,j);
                count++;
                if(count==8)
                flag=1;
                break;
            }
            j++;
            jog2+=j;
        }
        if(flag==1)
        break;
    }
    return 0;
}
