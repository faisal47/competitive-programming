#include <stdio.h>
#include <string.h>
int main ()
{
    long long int arr[50],i,max,flag,b,c,arr3[103],len;
    arr[1]=1;arr[2]=2;
    for(i=3;i<48;i++)
    arr[i]=arr[i-1]+arr[i-2];
    long long int t,y,n,j,a,arr4[105],k,position;
    char arr1[102],arr2[102],z;
    scanf("%lld",&t);
    for(y=0;y<t;y++)
    {
        c=max=flag=0;
        scanf("%lld",&n);
        for(j=1;j<=n;j++)
        {
            if(j==n)
            scanf("%lld%c",&arr4[j],&z);
            else
            scanf("%lld",&arr4[j]);

        }
        gets(arr1);
        len=strlen(arr1);
        for(i=0;i<len;i++)
        {
            if(arr1[i]>='A'&&arr1[i]<='Z')
            {
                z=arr1[i];
                c=i;
                break;
            }
        }
        max=0;
        for(i=1;i<=n;i++)
        {
            flag=0;
            a=arr4[i];
            for(k=1;k<48;k++)
            {
               if(arr[k]==a)
               {
                   position=k-1;
                   flag=1;
                   if(k>max)
                   max=k;
                   break;
               }
            }
            if(flag==0)
            arr2[i-1]=' ';
            else
            {
                arr2[position]=z;
                for(k=c;k<len;k++)
                {
                    if(arr1[k]>='A'&&arr1[k]<='Z')
                    {
                        z=arr1[k];
                        c=k;
                        break;
                    }
                }
            }
        }
        arr2[max]='\0';
        printf("%s\n",arr2);
    }
    return 0;
}
