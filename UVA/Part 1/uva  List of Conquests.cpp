#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct country
{
  char con[80];
  int count;
};
int main ()
{
    country a[2002];
    char arr[100],arr1[2002][100],temp[100];
    int check,j,test,i,flag,len,m=0,koyta=0,k,l,temp1,len1,len2;
    for(i=0;i<2002;i++)
    a[i].count=0;
    scanf("%d ",&test);
    for(i=0;i<test;i++)
    {
        flag=0;
        gets(arr);
        for(j=0;j<m;j++)
        {
            check=strcmp(arr,arr1[j]);
            if(check==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        continue;
        else
            {
                strcpy(arr1[m++],arr);
                flag=0;
                for(j=0;j<len;j++)
                {
                    if(arr[j]==' ')
                    {
                        arr[j]='\0';
                        break;
                    }
                }
                flag=0;
                for(j=0;j<koyta;j++)
                {
                    check=strcmp(arr,a[j].con);
                    if(check==0)
                    {
                        a[j].count++;
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    strcpy(a[koyta++].con,arr);
                }
            }
            for(j=0;j<koyta-1;j++)
            for(k=j+1;k<koyta;k++)
            {
                len1=strlen(a[j].con);
                len2=strlen(a[k].con);
                if(len1<=len2)
                {
                    len=len1;
                    for(l=0;l<len;l++)
                    if(a[j].con[l]>a[k].con[l])
                    {
                        strcpy(temp,a[j].con);
                        strcpy(a[j].con,a[k].con);
                        strcpy(a[k].con,temp);
                        temp1=a[j].count;
                        a[j].count=a[k].count;
                        a[k].count=temp1;
                        break;
                    }
                }
                else
                {
                    len=len2;
                    for(l=0;l<len;l++)
                    if(a[j].con[l]>a[k].con[l])
                    {
                        strcpy(temp,a[j].con);
                        strcpy(a[j].con,a[k].con);
                        strcpy(a[k].con,temp);
                        temp1=a[j].count;
                        a[j].count=a[k].count;
                        a[k].count=temp1;
                        break;
                    }
                }
            }
            for(i=0;i<koyta;i++)
            cout<<a[i].con<<a[i].count<<endl;
    }
    return 0;
}
