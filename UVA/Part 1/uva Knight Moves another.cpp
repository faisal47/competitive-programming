#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int count,colour[100][100];
int okay(int a,int b)
{
    if(a>=1&&a<=8&&b>=1&&b<=8)
        return 1;
    else
        return 0;
}
void bfs(int a1,int b1,int a2,int b2)
{
    int i,j,children1[70][2],flag=0,children2[70][2],c=1,d=0,m,n,yes,flag1=0,a,b;
    children1[0][0]=a1;
    children1[0][1]=b1;
    colour[a1][b1]=1;
    while(1)
    {
        if(flag1==0)
        {
            for(i=0; i<c; i++)
            {
                m=children1[i][0];
                n=children1[i][1];
                a=m-2;
                b=n+1;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children2[d][0]=a;
                    children2[d][1]=b;
                    d++;
                }
                a=m-2;
                b=n-1;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children2[d][0]=a;
                    children2[d][1]=b;
                    d++;
                }
                a=m-1;
                b=n+2;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children2[d][0]=a;
                    children2[d][1]=b;
                    d++;
                }
                a=m+1;
                b=n+2;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children2[d][0]=a;
                    children2[d][1]=b;
                    d++;
                }
                a=m+1;
                b=n-2;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children2[d][0]=a;
                    children2[d][1]=b;
                    d++;
                }
                a=m-1;
                b=n-2;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children2[d][0]=a;
                    children2[d][1]=b;
                    d++;
                }
                a=m+2;
                b=n-1;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children2[d][0]=a;
                    children2[d][1]=b;
                    d++;
                }
                a=m+2;
                b=n+1;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children2[d][0]=a;
                    children2[d][1]=b;
                    d++;
                }
            }
            c=0;
            flag1=1;
        }
        else
        {
            for(i=0; i<d; i++)
            {
                m=children2[i][0];
                n=children2[i][1];
                a=m-2;
                b=n+1;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children1[c][0]=a;
                    children1[c][1]=b;
                    c++;
                }
                a=m-2;
                b=n-1;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children1[c][0]=a;
                    children1[c][1]=b;
                    c++;
                }
                a=m-1;
                b=n+2;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children1[c][0]=a;
                    children1[c][1]=b;
                    c++;
                }
                a=m+1;
                b=n+2;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children1[c][0]=a;
                    children1[c][1]=b;
                    c++;
                }
                a=m+1;
                b=n-2;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children1[c][0]=a;
                    children1[c][1]=b;
                    c++;
                }
                a=m-1;
                b=n-2;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children1[c][0]=a;
                    children1[c][1]=b;
                    c++;
                }
                a=m+2;
                b=n-1;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children1[c][0]=a;
                    children1[c][1]=b;
                    c++;
                }
                a=m+2;
                b=n+1;
                yes=okay(a,b);
                if(yes==1&&colour[a][b]==0)
                {
                    colour[a][b]=1;
                    if(a==a2&&b==b2)
                        flag=1;
                    if(flag==1)
                        break;
                    children1[c][0]=a;
                    children1[c][1]=b;
                    c++;
                }
            }
            d=0;
            flag1=0;
        }
        count++;
        if(flag==1)
            break;
    }
    return;
}
int main ()
{
    int a1,b1,a2,b2;
    char arr1[10];
    while(gets(arr1))
    {
        if(arr1[0]=='a')
            b1=1;
        else if(arr1[0]=='b')
            b1=2;
        else if(arr1[0]=='c')
            b1=3;
        else if(arr1[0]=='d')
            b1=4;
        else if(arr1[0]=='e')
            b1=5;
        else if(arr1[0]=='f')
            b1=6;
        else if(arr1[0]=='g')
            b1=7;
        else if(arr1[0]=='h')
            b1=8;
        if(arr1[1]=='1')
            a1=1;
        else if(arr1[1]=='2')
            a1=2;
        else if(arr1[1]=='3')
            a1=3;
        else if(arr1[1]=='4')
            a1=4;
        else if(arr1[1]=='5')
            a1=5;
        else if(arr1[1]=='6')
            a1=6;
        else if(arr1[1]=='7')
            a1=7;
        else if(arr1[1]=='8')
            a1=8;
        if(arr1[3]=='a')
            b2=1;
        else if(arr1[3]=='b')
            b2=2;
        else if(arr1[3]=='c')
            b2=3;
        else if(arr1[3]=='d')
            b2=4;
        else if(arr1[3]=='e')
            b2=5;
        else if(arr1[3]=='f')
            b2=6;
        else if(arr1[3]=='g')
            b2=7;
        else if(arr1[3]=='h')
            b2=8;
        if(arr1[4]=='1')
            a2=1;
        else if(arr1[4]=='2')
            a2=2;
        else if(arr1[4]=='3')
            a2=3;
        else if(arr1[4]=='4')
            a2=4;
        else if(arr1[4]=='5')
            a2=5;
        else if(arr1[4]=='6')
            a2=6;
        else if(arr1[4]=='7')
            a2=7;
        else if(arr1[4]=='8')
            a2=8;
        count=0;
        if(a1==a2&&b1==b2)
            printf("To get from %c%c to %c%c takes 0 knight moves.\n",arr1[0],arr1[1],arr1[3],arr1[4]);
        else
        {
            memset(colour,0,sizeof(colour));
            bfs(a1,b1,a2,b2);
            printf("To get from %c%c to %c%c takes %d knight moves.\n",arr1[0],arr1[1],arr1[3],arr1[4],count);
        }
    }
    return 0;
}
