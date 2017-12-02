#include <stdio.h>
#include <string.h>
double arr[300];
char arr1[10005];
int main ()
{
    char a,b,o,p;
    int i,c,len,j,n,y,z,k;
    double m,l;
    scanf("%d",&z);
    for(y=0;y<z;y++)
    {
        m=0;
        scanf("%d%c",&k,&o);
        for(i=0;i<k;i++)
        {
            scanf("%c %lf",&a,&l);
            arr[a]=l;
            scanf("%c",&o);
        }
        scanf("%d%c",&n,&o);
        for(i=0;i<n;i++)
        {
            gets(arr1);
            len=strlen(arr1);
            for(j=0;j<len;j++)
            m+=arr[arr1[j]];
        }
        m/=100.0;
        printf("%01.2lf$\n",m);
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
