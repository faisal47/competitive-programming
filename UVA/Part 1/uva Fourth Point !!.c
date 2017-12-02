#include <stdio.h>
int main ()
{
    double arr[5][5],b1,b2;
    int i,j,m;
    while((scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&arr[0][0],&arr[0][1],&arr[1][0],&arr[1][1],&arr[2][0],&arr[2][1],&arr[3][0],&arr[3][1]))==8)
    {
        m=0;
        for(i=0; i<3; i++)
        {
            for(j=i+1; j<4; j++)
        {
            if(arr[i][0]==arr[j][0]&&arr[i][1]==arr[j][1])
            {
                b1=arr[i][0];b2=arr[i][1];
            }
        }
        }
        for(i=0;i<4;i++)
        {
            if(arr[i][0]!=b1||arr[i][1]!=b2)
            {
                arr[m][0]=arr[i][0];arr[m][1]=arr[i][1];
                m++;
            }
        }
        printf("%.3lf %.3lf\n",(arr[0][0]+arr[1][0])-b1,(arr[0][1]+arr[1][1])-b2);
    }
    return 0;
}
