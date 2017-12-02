#include <stdio.h>
#include <string.h>
int main ()
{
    char arr[102],arr3[102],z,arr4[102];
    long long int flag,n,arr2[55],i,j,k,l,a,t,y,len,c,arr1[102],max;
    arr2[1]=1;
    arr2[2]=2;
    for(i=3;i<50;i++)
    arr2[i]=arr2[i-1]+arr2[i-2];
    scanf("%lld",&t);
    for(y=0;y<t;y++)
    {
        c=0;flag=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            if(i==n-1)
            scanf("%lld%c",&a,&z);
            else
            scanf("%lld",&a);
            flag=0;
            for(j=1;j<=48;j++)
            {
                if(a==arr2[j])
                {
                   arr1[i]=(j-1);
                   flag=1;
                   break;
                }
            }
            if(flag==0)
            arr1[i]=100;
        }
        gets(arr);c=0;
        len=strlen(arr);
        for(i=0;i<len;i++)
        {
            if(arr[i]>='A'&&arr[i]<='Z')
            arr3[c++]=arr[i];
        }
        len=c;c=0;z=arr3[0];
        for(i=0;i<100;i++)
        arr4[i]='a';
        max=1;
        for(i=0;i<n;i++)
        {
            if(arr1[i]==100)
            arr4[i]=' ';
            else
            {
                arr4[arr1[i]]=z;
                z=arr3[++c];
                if(max<arr1[i]+1)
                 max=arr1[i]+1;
            }
        }
        for(i=0;i<100;i++)
        {
            if(arr4[i]=='a')
            arr4[i]=' ';
        }
        arr4[max]='\0';
        printf("%s\n",arr4);
    }
    return 0;
}
