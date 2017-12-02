#include <stdio.h>
#include <string.h>
int main ()
{
    char arr[8],arr1[5]={"one"},z;
    int len,t,i,m,n,j;
    scanf("%d%c",&t,&z);
    for(i=0;i<t;i++)
    {
        m=0;n=0;
        gets(arr);
        len=strlen(arr);
        if(len==3)
        {
          for(j=0;j<3;j++)
          {
              if(arr[j]==arr1[j])
              m++;
              else
              n++;
          }
          if(m>=2)
          printf("1\n");
          else
          printf("2\n");
        }
        else
        printf("3\n");
    }
    return 0;
}
