#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
struct rect
{
    double x1,x2,y1,y2;
};
struct cir
{
    double x,y,r;
};
struct tri
{
    double x1,x2,x3,y1,y2,y3;
};
union inp
{
    tri triangle;
    cir circle;
    rect rectangle;
};
int main ()
{
    char ch,c[15],z;
    int i=0,n,j=1,flag,flag1;
    inp arr[15];
    double a,b,p,q,r,s,t,a1,b1,c1,a2,b2,c2,a3,b3,c3;
    while((scanf(" %c",&ch))==1)
    {
        if(ch=='*')
        break;
        if(ch=='r')
        {
           c[i]='r';
          cin>>arr[i].rectangle.x1>>arr[i].rectangle.y1>>arr[i].rectangle.x2>>arr[i].rectangle.y2;
        }
        else if(ch=='t')
        {
          c[i]='t';
          cin>>arr[i].triangle.x1>>arr[i].triangle.y1>>arr[i].triangle.x2>>arr[i].triangle.y2>>arr[i].triangle.x3>>arr[i].triangle.y3;
        }
        else
        {
         c[i]='c';
         cin>>arr[i].circle.x>>arr[i].circle.y>>arr[i].circle.r;
        }
        i++;
    }
    n=i;
    while((scanf("%lf %lf",&a,&b))==2)
    {
        if(a==9999.9&&b==9999.9)
        break;
        flag1=flag=0;
        for(i=0;i<n;i++)
        {
            if(c[i]=='r')
            {
                if(a>arr[i].rectangle.x1&&a<arr[i].rectangle.x2&&b<arr[i].rectangle.y1&&b>arr[i].rectangle.y2)
                {
                    printf("Point %d is contained in figure %d\n",j,i+1);
                    flag=1;
                }
            }
            else if(c[i]=='c')
            {
                p=arr[i].circle.x;
                q=arr[i].circle.y;
                r=arr[i].circle.r;
                if((pow((a-p),2)+pow((b-q),2)-pow(r,2))<0)
                {
                    printf("Point %d is contained in figure %d\n",j,i+1);
                    flag=1;
                }
            }
            else
            {
                a1=arr[i].triangle.x1;
                b1=arr[i].triangle.y1;
                a2=arr[i].triangle.x2;
                b2=arr[i].triangle.y2;
                a3=arr[i].triangle.x3;
                b3=arr[i].triangle.y3;
                p=((a1*(b2-b3))+(a2*(b3-b1))+(a3*(b1-b2)))/2.;
                if(p<0)
                p=(-1.)*p;
                q=((a*(b2-b3))+(a2*(b3-b))+(a3*(b-b2)))/2.;
                if(q<0)
                q*=(-1.);
                r=((a*(b3-b1))+(a3*(b1-b))+(a1*(b-b3)))/2.;
                if(r<0)
                r*=(-1.);
                s=((a*(b1-b2))+(a1*(b2-b))+(a2*(b-b1)))/2.;
                if(s<0)
                s*=(-1.);
                q+=r+s;
                p-=q;
                if(p<=.000001&&p>=-.000001)
                {
                    printf("Point %d is contained in figure %d\n",j,i+1);
                    flag=1;
                }
            }
        }
        if(flag==0)
        printf("Point %d is not contained in any figure\n",j);
        j++;
    }
    return 0;
}
