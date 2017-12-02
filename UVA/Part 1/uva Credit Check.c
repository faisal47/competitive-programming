#include <stdio.h>
#include <string.h>
int main ()
{int n,m,arr1[20],j,b,c,arr3[20],i,a,d,o;char arr[20],z;scanf("%d%c",&n,&z);
    for(i=0;i<n;i++)
    {d=0;m=0;o=0;
        gets(arr);
        a=strlen(arr);
        for(j=0;j<a;j++)
        arr3[j]=(arr[j]-'0');
        for(j=0;j<8;j++)
        {   m+=1;
            arr1[j]=(2*arr3[o]);
            if(m==2)
            {m=0;o+=3;}
            else
            o+=2;}
        for(j=0;j<8;j++)
        {b=(arr1[j]/10);
            c=(arr1[j]%10);
            arr1[j]=(b+c);
            d+=arr1[j];}
        m=0;o=1,a=0;
        for(j=0;j<8;j++)
        {m+=1;
        a+=arr3[o];
            if(m==2)
            {m=0;o+=3;}
            else
            o+=2;}
        c=(a+d);
        if((c%10)==0)
        printf("Valid\n");
        else
        printf("Invalid\n");
    }
    return 0;}
