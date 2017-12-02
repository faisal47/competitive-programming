#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    long long arr[35];
    arr[1]=1;
    arr[2]=2;
    arr[3]=5;
    arr[4]=14;
    arr[5]=42;
    arr[6]=132;
    arr[7]=429;
    arr[8]=1430;
    arr[9]=4862;
    arr[10]=16796;
    arr[11]=58786;
    arr[12]=208012;
    arr[13]=742900;
    arr[14]=2674440;
    arr[15]=9694845;
    arr[16]=35357670;
    arr[17]=129644790;
    arr[18]=477638700;
    arr[19]=1767263190;
    arr[20]=6564120420;
    int n,i;
    while(cin>>n)
    {
        for(i=1;i<=20;i++)
        if(arr[i]==n)
        {
            cout<<i<<endl;
            break;
        }
    }
   // arr[21]=;
    return 0;
}
