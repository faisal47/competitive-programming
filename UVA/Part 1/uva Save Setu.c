#include <stdio.h>
#include <string.h>
int main ()
{
    unsigned long long u=0,n;int t,i;char arr[20],z;
    scanf("%d%c",&t,&z);
    for(i=0;i<t;i++)
    {
        scanf("%s",arr);
        if(strcmp(arr,"donate")==0)
        {
            scanf("%llu",&n);u+=n;
        }
        else
        printf("%llu\n",u);
    }
    return 0;
}
