#include<stdio.h>


int main()
{
   char ch;
    int i, cas;
    double a, sum;
    scanf("%d", &cas);
    scanf("%c", &ch);
    while(cas--)
    {
        double num[150]={0};
        sum=0;
        scanf("%d", &i);
        scanf("%c", &ch);
        while(i--)
        {
            scanf("%c %lf", &ch, &a);
            num[(int)ch]=a;
            scanf("%c", &ch);
        }
        scanf("%d", &i);
        scanf("%c", &ch);
        while(i--)
        {
            while((ch=getchar())!='\n')
            {
                a=num[(int)ch];
                if(a)
                    sum+=a;
            }
        }
        sum/=100.0;
        printf("%01.2lf$\n", sum);
    }

    return 0;
}
