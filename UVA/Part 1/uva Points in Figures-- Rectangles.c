#include <stdio.h>
#include <math.h>
typedef struct
{
    double p1,p2,p3,p4;
}rectangle;
int main ()
{
    rectangle arr[15];
    char c,z;
    int count=0,flag1,i,flag2,count2=1,flag3,flag4,flag5;
    double a,b;
        while((scanf(" %c",&c))==1)
        {
            if(c=='*')
            break;
            scanf("%lf %lf %lf %lf",&arr[count].p1,&arr[count].p2,&arr[count].p3,&arr[count].p4);
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

                    if((a-arr[i].p3)<0)
                    flag1=1;
                    if((b-arr[i].p4)>0)
                    flag3=1;
                    if((a-arr[i].p1)>0)
                    flag4=1;
                    if((b-arr[i].p2)<0)
                    flag5=1;
                    if(flag1==1&&flag3==1&&flag4==1&&flag5==1)
                    {
                        flag2=1;
                        printf("Point %d is contained in figure %d\n",count2,i+1);
                    }

            }
            if(flag2==0)
            printf("Point %d is not contained in any figure\n",count2);
            count2++;
        }
    return 0;
}
