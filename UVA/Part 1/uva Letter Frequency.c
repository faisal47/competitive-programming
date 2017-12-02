#include <stdio.h>
#include <string.h>
int main ()
{
    int i,arr[30],m=97,len,arr2[30],n,t,j;
    for(i=0;i<26;i++)
    {
        arr2[i]=m;m++;
    }
    char arr1[250],z;
    scanf("%d%c",&t,&z);
    for(j=0;j<t;j++)
    {
        gets(arr1);
        n=0;
        len=strlen(arr1);
        for(i=0;i<26;i++)
        arr[i]=0;
        for(i=0;i<len;i++)
        {
            if(arr1[i]=='a'||arr1[i]=='A')
            arr[0]++;
            else if(arr1[i]=='b'||arr1[i]=='B')
            arr[1]++;
            else if(arr1[i]=='c'||arr1[i]=='C')
            arr[2]++;
            else if(arr1[i]=='d'||arr1[i]=='D')
            arr[3]++;
            else if(arr1[i]=='e'||arr1[i]=='E')
            arr[4]++;
            else if(arr1[i]=='f'||arr1[i]=='F')
            arr[5]++;
            else if(arr1[i]=='g'||arr1[i]=='G')
            arr[6]++;
            else if(arr1[i]=='h'||arr1[i]=='H')
            arr[7]++;
            else if(arr1[i]=='i'||arr1[i]=='I')
            arr[8]++;
            else if(arr1[i]=='j'||arr1[i]=='J')
            arr[9]++;
            else if(arr1[i]=='k'||arr1[i]=='K')
            arr[10]++;
            else if(arr1[i]=='l'||arr1[i]=='L')
            arr[11]++;
            else if(arr1[i]=='m'||arr1[i]=='M')
            arr[12]++;
            else if(arr1[i]=='n'||arr1[i]=='N')
            arr[13]++;
            else if(arr1[i]=='o'||arr1[i]=='O')
            arr[14]++;
            else if(arr1[i]=='p'||arr1[i]=='P')
            arr[15]++;
            else if(arr1[i]=='q'||arr1[i]=='Q')
            arr[16]++;
            else if(arr1[i]=='r'||arr1[i]=='R')
            arr[17]++;
            else if(arr1[i]=='s'||arr1[i]=='S')
            arr[18]++;
            else if(arr1[i]=='t'||arr1[i]=='T')
            arr[19]++;
            else if(arr1[i]=='u'||arr1[i]=='U')
            arr[20]++;
            else if(arr1[i]=='v'||arr1[i]=='V')
            arr[21]++;
            else if(arr1[i]=='w'||arr1[i]=='W')
            arr[22]++;
            else if(arr1[i]=='x'||arr1[i]=='X')
            arr[23]++;
            else if(arr1[i]=='y'||arr1[i]=='Y')
            arr[24]++;
            else if(arr1[i]=='z'||arr1[i]=='Z')
            arr[25]++;
        }
        for(i=0;i<26;i++)
        {
            if(n<arr[i])
            n=arr[i];
        }
        for(i=0;i<26;i++)
        {
            if(arr[i]==n)
            printf("%c",arr2[i]);
        }
        printf("\n");
    }
    return 0;
}
