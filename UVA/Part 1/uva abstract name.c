#include <stdio.h>
#include <string.h>
int main ()
{
    char arr[1000],arr1[1000],k;
    int n,i,j,a,b,c;
    scanf("%d",&n);
    scanf("%c",&k);
    for(i=0; i<n; i++)
    {
        c=0;
        gets(arr);
        a=strlen(arr);
        gets(arr1);
        b=strlen(arr1);
        if(a==b)
        {
            for(j=0; j<a; j++)
            {
                if((arr[j]=='a'||arr[j]=='e'||arr[j]=='i'||arr[j]=='o'||arr[j]=='u')&&(arr1[j]=='a'||arr1[j]=='e'||arr1[j]=='i'||arr1[j]=='o'||arr1[j]=='u'))
                {
                    arr[j]='a';
                    arr1[j]='a';
                }
            }
            for(j=0; j<a; j++)
            {
                if(arr[j]==arr1[j])
                {
                    c++;
                }
            }
            if(a==c)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
