#include <stdio.h>
#include <string.h>
int main ()
{
    int n,i,z,count=1,len,j;
    char arr[105][105];
    while((scanf("%d%c",&n,&z))==2)
    {
        if(n==0)
        break;
        for(i=0;i<n;i++)
        gets(arr[i]);
        printf("Case %d:\n#include<string.h>\n#include<stdio.h>\nint main()\n{\n",count);
        for(i=0;i<n;i++)
        {
            printf("printf(\"");
            len=strlen(arr[i]);
            for(j=0;j<len;j++)
            {
                if(arr[i][j]==92||arr[i][j]==34)
                printf("\\%c",arr[i][j]);
                else
                printf("%c",arr[i][j]);
            }
            printf("%cn\");\n",92);
        }
        printf("printf(\"\\n\");\nreturn 0;\n}\n");
        count++;
    }
    return 0;
}
