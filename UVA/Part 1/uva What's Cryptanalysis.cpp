#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
struct b1
{
    char a;
    int b;
};
int main ()
{
    b1 out[28];
    int output[400],len,i,n;
    memset(output,0,sizeof(output));
    char arr[100000],z;
    scanf("%d%c",&n,&z);
    while(n--)
    {
        gets(arr);
        len=strlen(arr);
        for(i=0; i<len; i++)
            if(toupper(arr[i])>='A'&&toupper(arr[i])<='Z')
                ++output[toupper(arr[i])];
    }
    int c=0,temp,j;
    char tempc;
    for(i='A'; i<='Z'; i++)
    {
        out[c].a=(char)i;
        out[c].b=output[i];
        c++;
    }
    for(i=0;i<25;i++)
    for(j=i+1;j<26;j++)
   {
        if(out[i].b<out[j].b)
    {
        tempc=out[i].a;
        out[i].a=out[j].a;
        out[j].a=tempc;
        temp=out[i].b;
        out[i].b=out[j].b;
        out[j].b=temp;
    }
    else if((out[i].b==out[j].b)&&(out[i].a>out[j].a))
    {
        tempc=out[i].a;
        out[i].a=out[j].a;
        out[j].a=tempc;
    }
   }
    for(i=0;i<26;i++)
    if(out[i].b>0)
    printf("%c %d\n",out[i].a,out[i].b);
        return 0;
}
