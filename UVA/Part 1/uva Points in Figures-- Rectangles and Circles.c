#include <stdio.h>
#include <math.h>
typedef struct
{
    double p1,p2,p3,p4;
}rectangle;
typedef struct
{
    double c1,c2,r;
}circle;
typedef union
{
    circle cir;
    rectangle rec;
}bindu;
int main ()
{
    bindu arr[15];
    char c[20],z;
    int count=0,flag1,i,flag2,count2=1,flag3,flag4,flag5;
    double a,b;
        while((scanf(" %c",&c[count]))==1)
        {
            if(c[count]=='*')
            break;
            else if(c[count]=='c')
            {
                scanf("%lf %lf %lf",&arr[count].cir.c1,&arr[count].cir.c2,&arr[count].cir.r);
            }
            else if(c[count]=='r')
            {
                scanf("%lf %lf %lf %lf",&arr[count].rec.p1,&arr[count].rec.p2,&arr[count].rec.p3,&arr[count].rec.p4);
            }
            count++;
        }
     while((scanf("%lf %lf",&a,&b))==2)
        {
            flag2=0;
            if(a==9999.9&&b==9999.9)
            break;
            for(i=0;i<count;i++)
            {
                flag1=0;flag3=0;flag4=0;flag5=0;
                if(c[i]=='r')
                {
                    if((a-arr[i].rec.p3)<=0)
                    flag1=1;
                    if((b-arr[i].rec.p4)>=0)
                    flag3=1;
                    if((a-arr[i].rec.p1)>=0)
                    flag4=1;
                    if((b-arr[i].rec.p2)<=0)
                    flag5=1;
                    if(flag1==1&&flag3==1&&flag4==1&&flag5==1)
                    {
                        flag2=1;
                        printf("Point %d is contained in figure %d\n",count2,i+1);
                    }
                }
                else
                {
                    if((pow(a-arr[i].cir.c1,2)+pow(b-arr[i].cir.c2,2)-pow(arr[i].cir.r,2))<=0)
                    {
                        flag2=1;
                        printf("Point %d is contained in figure %d\n",count2,i+1);
                    }
                }
            }
            if(flag2==0)
            printf("Point %d is not contained in any figure\n",count2);
            count2++;
        }
    return 0;
}
