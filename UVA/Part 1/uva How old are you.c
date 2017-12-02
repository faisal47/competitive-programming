#include <stdio.h>
int main ()
{
    char arr[2][40]= {"Invalid birth date","Check birth date"};
    int t,i,a1,b1,c1,a2,b2,c2,age;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d/%d/%d",&a1,&b1,&c1);
        scanf("%d/%d/%d",&a2,&b2,&c2);
        if(c1==c2)
        {
            if(b1==b2)
            {
                if(a1>=a2)
                    printf("Case #%d: 0\n",i);
                else if(a1<a2)
                    printf("Case #%d: %s\n",i,arr[0]);
            }
            else if(b1>b2)
                printf("Case #%d: 0\n",i);
            else if(b1<b2)
                printf("Case #%d: %s\n",i,arr[0]);
        }
        else if(c1<c2)
            printf("Case #%d: %s\n",i,arr[0]);
        else if(c1>c2)
        {
            if(b1==b2)
            {
                if(a1>=a2)
                {
                    if((c1-c2)>130)
                        printf("Case #%d: %s\n",i,arr[1]);
                    else
                        printf("Case #%d: %d\n",i,c1-c2);
                }
                else
                {
                    if((c1-c2)>131)
                        printf("Case #%d: %s\n",i,arr[1]);
                    else
                        printf("Case #%d: %d\n",i,(c1-c2)-1);
                }
            }
            else if(b1<b2)
            {
                if((c1-c2)>131)
                    printf("Case #%d: %s\n",i,arr[1]);
                else
                    printf("Case #%d: %d\n",i,(c1-c2)-1);
            }
            else

            {
                if((c1-c2)>130)
                    printf("Case #%d: %s\n",i,arr[1]);
                else
                    printf("Case #%d: %d\n",i,(c1-c2));
            }
        }
    }
    return 0;
}
