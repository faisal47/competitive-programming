#include <stdio.h>
#include <string.h>
int main ()
{
    char arr[1020];
    int len,m,n,c,temp1,temp2,temp3,flag,count,number,i;
    while(gets(arr))
    {
        len=strlen(arr);
        if(arr[0]=='0'&&len==1)
            break;
        if(arr[0]=='9'&&len==1)
        {
            printf("%s is a multiple of 9 and has 9-degree 1.\n",arr);
            continue;
        }
        n=arr[0]-'0';
        m=1;
        while(1)
        {
            if(n>=9)
                n%=9;
            if(m==len)
                break;
            n=((n*10)+(arr[m]-'0'));
            m++;
        }
        count=1;
        if(n==0)
        {
            number=0;
            for(i=0;i<len;i++)
            number+=(arr[i]-'0');
            while(1)
            {
                if(number==9)
                    break;
                else
                {
                    temp3=0;
                    while(1)
                    {
                        temp1=number/10;
                        temp2=number%10;
                        temp3+=temp2;
                        if(temp1==0&&temp2<10)
                            break;
                        number=temp1;
                    }
                    number=temp3;
                }
                ++count;
            }
            printf("%s is a multiple of 9 and has 9-degree %d.\n",arr,count);

        }
        else
            printf("%s is not a multiple of 9.\n",arr);
    }
    return 0;
}
