#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
bool flag[100];
int main ()
{
    char arr[5000][25];
    int i=0,j,k,len;
    while(gets(arr[i]))
    {
        if(arr[i][0]=='#')
        break;
        len=strlen(arr[i]);
        while(len<22)
        arr[i][len++]='.';
        i++;
    }
    k=i;
    for(i=0;i<22;i++)
    for(j=0;j<k;j++)
    {
        if(arr[j][i]>='A'&&arr[j][i]<='Z')
        {
            if(flag[(int)arr[j][i]]==0)
            {
                flag[(int)arr[j][i]]=1;
                cout<<arr[j][i];
            }
        }
    }
    cout<<endl;
    return 0;
}
