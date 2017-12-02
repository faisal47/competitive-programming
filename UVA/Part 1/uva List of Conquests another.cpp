#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
struct country
{
    char con[100];
    int b;
};
int main ()
{
    country a[2002];
    int test,i,count=0,len,j,flag=0,len1,len2,k,temp,flag1;
    char arr[100],z;
    for(i=0; i<2002; i++)
        a[i].b=0;
    scanf("%d",&test);
    scanf("%c",&z);
    for(i=0; i<test; i++)
    {
        gets(arr);
        len=strlen(arr);
        for(j=0; j<len; j++)
        {
            if(arr[j]==' ')
            {
                arr[j]='\0';
                break;
            }
        }
        flag=0;
        for(j=0; j<count; j++)
        {
            if(strcmp(a[j].con,arr)==0)
            {
                flag=1;
                a[j].b++;
                break;
            }
        }
        if(flag==0)
        {
            strcpy(a[count].con,arr);
            a[count].b++;
            count++;
        }
    }
    for(i=0; i<count-1; i++)
        for(j=i+1; j<count; j++)
        {
            len1=strlen(a[i].con);
            len2=strlen(a[j].con);
            if(len1<=len2)
            {
                len=len1;
                for(k=0; k<len; k++)
                {
                    if(a[i].con[k]<a[j].con[k])
                        break;
                    else if(a[i].con[k]>a[j].con[k])
                    {
                        temp=a[i].b;
                        a[i].b=a[j].b;
                        a[j].b=temp;
                        strcpy(arr,a[i].con);
                        strcpy(a[i].con,a[j].con);
                        strcpy(a[j].con,arr);
                        break;
                    }
                }
            }
            else
            {
                len=len2;
                for(k=0; k<len; k++)
                {
                    if(a[i].con[k]<a[j].con[k])
                        break;
                    else if(a[i].con[k]>a[j].con[k])
                    {
                        temp=a[i].b;
                        a[i].b=a[j].b;
                        a[j].b=temp;
                        strcpy(arr,a[i].con);
                        strcpy(a[i].con,a[j].con);
                        strcpy(a[j].con,arr);
                        break;
                    }
                }
            }
        }
    for(i=0; i<count; i++)
        cout<<a[i].con<<" "<<a[i].b<<endl;
    return 0;
}
