#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
    double x1,x2,y1,y2,d1,d2,res,lombo;
    double pi=acos(-1);
    //cout<<tan(x1)<<endl;
    while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&d1,&d2)==6)
    {
        res=0;
        d1=(pi/180.)*d1;
        d2=(pi/180.)*d2;
        lombo=sqrt(pow(x1-x2,2.)+pow(y1-y2,2.));
        res+=lombo/tan(d1);
        res+=lombo/tan(d2);
        printf("%.3lf\n",res);
    }
    return 0;
}
