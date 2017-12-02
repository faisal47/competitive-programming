#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
char text[1000010];
int f1[1000010],f2[1000010];
void kmp()
{
    int len=strlen(text),i;
    int k;
    f1[0]=f2[len-1]=k=0;
    for(i=1;i<len;i++)
    {
        while(k>0 && text[i]!=text[k])
        k=f1[k-1];
        if(text[i]==text[k])
        k++;
        f1[i]=k;
    }
    //for
    for(i=0;i<len;i++)
    cout<<f1[i]<<endl;
}
int main ()
{

    int test,t;
    char z;
    string a;
    scanf("%d",&test);
    scanf("%c",&z);
    for(t=1;t<=test;t++)
    {
        gets(text);
        kmp();
        //a=text;
        //cout<<a<<endl;
    }
    return 0;
}
