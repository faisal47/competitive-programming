#include <stdio.h>
#include <string.h>
int main ()
{
    int l,n,i,len1,j,flag,c1,c2;
    char arr[22][50],arr2[105][25],arr1[22][2][25],z;
    scanf("%d %d%c",&l,&n,&z);
    for(i=0;i<l;i++)
    gets(arr[i]);
    for(i=0;i<n;i++)
    gets(arr2[i]);
    for(i=0;i<l;i++)
    {
        c1=0;c2=0;
        flag=0;
        len1=strlen(arr[i]);
        for(j=0;j<len1;j++)
        {
            if(flag==0&&arr[i][j]!=' ')
            arr1[i][0][c1++]=arr[i][j];
            else if(flag==1)
            arr1[i][1][c2++]=arr[i][j];
            else
            flag+=1;
        }
        arr1[i][0][c1]='\0';
        arr1[i][1][c2]='\0';
    }
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<l;j++)
        {
            if(strcmp(arr2[i],arr1[j][0])==0)
            {
                printf("%s\n",arr1[j][1]);
                flag+=1;
                break;
            }
        }
        if(flag==1)
        continue;
        len1=strlen(arr2[i]);
        if(arr2[i][len1-1]=='y'&&arr2[i][len1-2]!='a'&&arr2[i][len1-2]!='e'&&arr2[i][len1-2]!='i'&&arr2[i][len1-2]!='o'&&arr2[i][len1-2]!='u')
        {
            for(j=0;j<len1-1;j++)
            printf("%c",arr2[i][j]);
            printf("ies\n");
        }
        else if(arr2[i][len1-1]=='o'||arr2[i][len1-1]=='s'||arr2[i][len1-1]=='x'||(arr2[i][len1-2]=='c'&&arr2[i][len1-1]=='h')||(arr2[i][len1-2]=='s'&&arr2[i][len1-1]=='h'))
       {
           printf("%s",arr2[i]);
           printf("es\n");
       }
       else
       {
           printf("%s",arr2[i]);
           printf("s\n");
       }
    }
    return 0;
}
