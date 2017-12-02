#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    int i,test,s=1;
    char arr[1030][1050],z;
    scanf("%d",&test);
    scanf("%c",&z);
    for(i=1; i<=test; i++)
        gets(arr[i]);
    char out1[20][150];
    strcpy(out1[1],"Happy");
    strcpy(out1[2],"birthday");
    strcpy(out1[3],"to");
    strcpy(out1[4],"you");
    strcpy(out1[5],"Happy");
    strcpy(out1[6],"birthday");
    strcpy(out1[7],"to");
    strcpy(out1[8],"you");
    strcpy(out1[9],"Happy");
    strcpy(out1[10],"birthday");
    strcpy(out1[11],"to");
    strcpy(out1[12],"Rujia");
    strcpy(out1[13],"Happy");
    strcpy(out1[14],"birthday");
    strcpy(out1[15],"to");
    strcpy(out1[16],"you");
    strcpy(out1[17],"Rujia");
    for(i=1; i<=test; i++)
    {
        if((((i-12)%16)==0)&&(i>=12))
            cout<<arr[i]<<": "<<out1[17]<<endl;
        else
        {
            cout<<arr[i]<<": "<<out1[s]<<endl;
        }
        s++;
        if(s>16)
        s=1;
    }
    int j=1;
    for(i=s;i<=16;i++)
    {
        cout<<arr[j++]<<": "<<out1[i]<<endl;
        if(j>test)
        j=1;
    }
    return 0;
}
