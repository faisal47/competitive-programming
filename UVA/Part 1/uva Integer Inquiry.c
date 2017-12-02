#include <stdio.h>
#include <string.h>
int main ()
{
    char arr[110][110];
    int arr1[110],k,i=0,j,o,arr2[110][110],max=0,m,sum=0,c=0;
    while(gets(arr[i]))
    {
        arr1[i]=strlen(arr[i]);
        if(arr1[i]==1&&arr[i][0]=='0')
        break;
        i++;
    }
        for(j=0;j<=i;j++)
        {
            if(arr1[j]>max)
            max=arr1[j];
        }
        for(j=0;j<=i;j++)
        {
            m=0;
            for(k=arr1[j]-1;k>=0;k--)
            {
                arr2[j][m]=(arr[j][k]-'0');
                m++;
            }
        }
        for(j=0;j<=i;j++)
        {
            if(max>arr1[j])
            {
                for(k=max-1;k>arr1[j];k--)
                arr2[j][k]=0;
            }
        }
        for(o=0;o<max;o++)
        {
            sum=c;
            for(k=0;k<=i;k++)
            {
                sum+=arr2[k][o];
            }
            c=(sum/10);
            arr1[o]=(sum%10);
        }
        if(c>0)
        {
         arr1[o]=c;
        }
        else
        {
            o-=1;
        }
        for(k=o;k>=0;k--)
        printf("%d",arr1[k]);
    return 0;
}
